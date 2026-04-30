#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>


// IMPORTANT NOTE: This is an externally-created implementation 
class ThreadPool {
    
public:
    explicit ThreadPool(size_t threads);
    ~ThreadPool();

    void enqueue(std::function<void()> task);
    void wait_for_all();

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable cv_task;
    std::condition_variable cv_finished;

    std::atomic<bool> stop;
    std::atomic<int> active_tasks;

    void worker_thread();
};

#endif
