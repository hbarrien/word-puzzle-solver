#include "ThreadPool.h"


ThreadPool::ThreadPool(size_t threads)
    : stop(false), active_tasks(0)
{
    for (size_t i = 0; i < threads; ++i) {
        workers.emplace_back(&ThreadPool::worker_thread, this);
    }
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        stop = true;
    }
    cv_task.notify_all();

    for (auto& t : workers) {
        if (t.joinable())
            t.join();
    }
}

void ThreadPool::enqueue(std::function<void()> task) {
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.push(std::move(task));
    }
    cv_task.notify_one();
}

void ThreadPool::wait_for_all() {
    std::unique_lock<std::mutex> lock(queue_mutex);
    cv_finished.wait(lock, [this] {
        return tasks.empty() && active_tasks == 0;
    });
}

void ThreadPool::worker_thread() {
    while (true) {
        std::function<void()> task;

        {
            std::unique_lock<std::mutex> lock(queue_mutex);

            cv_task.wait(lock, [this] {
                return stop || !tasks.empty();
            });

            if (stop && tasks.empty())
                return;

            task = std::move(tasks.front());
            tasks.pop();
            active_tasks++;
        }

        task();

        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            active_tasks--;
            if (tasks.empty() && active_tasks == 0)
                cv_finished.notify_all();
        }
    }
}
