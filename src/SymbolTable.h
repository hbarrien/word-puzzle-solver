#ifndef _SYMBOL_TABLE_H_
#define _SYMBOL_TABLE_H_

#include <vector>
#include <string>
#include <fstream>

#include "SymbolPosition.h"
#include "StringConverter.h"

using namespace std;


class SymbolTable {
    
private:
    vector<unsigned char> data; // Holds both regular ASCII and diacritic characters
    size_t N {0};  // Number of rows
    size_t M {0};  // Number of columns
    
    SymbolTable(
        const string &fPath,
        int unused
    );
    
    void validateInput(
        const string &fPath
    );
    
    size_t to1BasedIndex(int row, int col, int nCols) const;
    
    void readSymbolFile(
        const string &fPath, 
        const char separator = ','
    );
        
    void incrementNumRows();
    void incrementNumColumns();
    
    void add(
        const unsigned char &c
    );
    
public:
    SymbolTable(const string &fPath);
    ~SymbolTable() = default;
    
    size_t numRows() const;
    size_t numColumns() const;
    size_t size() const;
    
    const unsigned char &at(
        const size_t i, 
        const size_t j
    ) const; 
    
    const SymbolPosition whichPosition(
        const size_t i, 
        const size_t j
    ) const;
};

#endif // _SYMBOL_TABLE_H_
