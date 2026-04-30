#include "Wordtable.h"


WordTable::WordTable(
    const string &fPath)
    : WordTable((validateInput(fPath), fPath), 0) {
}

WordTable::WordTable(
    const string &fPath,
    int unused) {
        
    readWordsTable(fPath);
}

void WordTable::validateInput(
    const string &fPath) {
        
    if (fPath.length() == 0)
        throw invalid_argument("Words file-path string is empty");
}

/* readWordsTable
 * Reads the words list from a text file. 
 * 
 * * Precondition:
 * (fPath is a non-empty string) &&
 * (the corresponding text file is open)
 * 
 * Postcondition:
 * (For every word: (|word| > 1)) && (|words| > 0)
 */
void WordTable::readWordsTable(const string &fPath) {
    
    ifstream wordsFile {fPath, ios::in};
    
    if (!wordsFile.is_open())
        throw invalid_argument("Words file not found: " + fPath);
    
    StringConverter converter;
    string line {};
    
    while (getline(wordsFile, line)) {
        
        /* Convert diacritic symbols to one-byte representations.
         * This way, all word symbols will have the same size,
         * i.e., one byte
         */
        string latin1Word {converter.to_latin1(line)};
        
        if (latin1Word.length() < 2)
            throw invalid_argument("There is at least an empty or one-letter word");
        
        words.push_back(latin1Word);
    }
    
    if (words.empty())
        throw invalid_argument("The word table is empty");
}

const vector<string> WordTable::getWords() const {
    
    return words;
}