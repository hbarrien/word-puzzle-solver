#ifndef _WORD_CONTAINER_H_
#define _WORD_CONTAINER_H_

#include <vector>
#include "WordRecord.h" 


class WordContainer {

private:
    vector<WordRecord> wordRecords;
    
public:
    WordContainer() = default;
    ~WordContainer() = default;
    
    void add(WordRecord word);
    vector<WordRecord> &getWordRecords();
};

#endif // _WORD_CONTAINER_H_
