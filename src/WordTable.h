#ifndef _WORD_TABLE_H_
#define _WORD_TABLE_H_

#include <vector>
#include <string>
#include <fstream>

#include "StringConverter.h"

using namespace std;


class WordTable
{
private:
    vector<string> words; // Holds words containing ASCII and diacritic symbols
    
    WordTable(
        const string &fPath,
        int unused
    );
    
    void validateInput(
        const string &fPath
    );
    
    void readWordsTable(
        const string &fPath
    );
    
public:
    WordTable(
        const string &fPath
    );
    
    ~WordTable() = default;
    
    const vector<string> getWords() const;
};

#endif // _WORD_TABLE_H_
