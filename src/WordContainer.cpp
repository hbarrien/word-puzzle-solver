#include "WordContainer.h"


void WordContainer::add(WordRecord word) {
    wordRecords.push_back(word);
}
    
vector<WordRecord>& WordContainer::getWordRecords() {
    return wordRecords;
}