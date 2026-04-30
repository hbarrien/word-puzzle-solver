#include "SymbolTable.h"


SymbolTable::SymbolTable(
    const string &fPath)
    : SymbolTable((validateInput(fPath), fPath), 0) {        
}

SymbolTable::SymbolTable(
    const string &fPath,
    int unused) {

    readSymbolFile(fPath);
}

void SymbolTable::validateInput(
    const string &fPath) {
        
    if (fPath.length() == 0)
        throw invalid_argument("Symbol table file-path string is empty");
}

/* to1BasedIndex
 * Returns a vector index value based on a 1-based indexing
 * scheme. The initial implementation was developed in R, 
 * which uses 1-based vector and table indexing. To keep all 
 * original (correctly working) index calculations as they 
 * are, this conversion was necessary
 */
size_t SymbolTable::to1BasedIndex(int row, int col, int nCols) const {    
    return static_cast<size_t>((row - 1) * nCols + (col - 1));
}

/* readSymbolFile
 * Reads letter data from a text file.
 * 
 * Precondition:
 * (fPath is a non-empty string) &&
 * (the corresponding text file is open)
 * 
 * Postcondition:
 * (|data| > 0) && 
 * ((N > 0) && (M > 0)) --> data is rectangular.
 * 
 */
void SymbolTable::readSymbolFile (
    const string &fPath, 
    const char separator) {
    
    ifstream symbols {fPath, ios::in};
    
    if (!symbols.is_open())
        throw invalid_argument("Symbol file not found: " + fPath);
    
    StringConverter converter;
    string rawLine {};
    string line {};
    
    while (getline(symbols, rawLine)) {
        
        incrementNumRows();
        
        /* Convert diacritic symbols to one-byte representations.
         * This way, the table will always contain one byte per 
         * cell regardless of whether the processed symbol is ASCII 
         * or diacritic (more than one byte in size)
         */
        line = converter.to_latin1(rawLine);
        
        size_t columnsPerRow {0};
        
        for (unsigned char c : line) {
            
            if (c == separator) continue;
            
            add(c);
            columnsPerRow++;
            
            /* The number of columns in the first row is the
             * default number of columns for the entire table
             */
            if (numRows() == 1)
                incrementNumColumns();
        }
        
        if (columnsPerRow != numColumns()) {
            N = 0;
            M = 0;
            throw invalid_argument("The number of columns per row is not consistent");
        }
    }
    
    if (data.empty())
        throw invalid_argument("The symbol table is empty");
}

void SymbolTable::incrementNumRows() {
    N++;
}
    
void SymbolTable::incrementNumColumns() {
    M++; 
}
    
size_t SymbolTable::numRows() const {
    return N;
}
    
size_t SymbolTable::numColumns() const {
    return M;
}

size_t SymbolTable::size() const {
    return data.size();
}
    
void SymbolTable::add(const unsigned char &c) {
    data.push_back(c);
}

const unsigned char& SymbolTable::at(const size_t i, const size_t j) const {
    return data.at(to1BasedIndex(i, j, M));
}

/* whichPosition
 * Given i, j coordinates, this program returns the corresponding cell
 * position within the table. For instance, if (i == 1) and (j == 1)
 * then the cell position is the upper left corner. 
 */ 
const SymbolPosition SymbolTable::whichPosition(const size_t i, const size_t j) const {
        
    if (i == 1) {
        if (j == 1) return SymbolPosition::POS_ULC;
        if ((1 < j) && (j < M)) return SymbolPosition::POS_TOP;
    }
    
    if (j == M) {
        
        if (i == 1) return SymbolPosition::POS_URC;
        if ((1 < i) && (i < N)) return SymbolPosition::POS_RGT;
    }
    
    if (i == N) {
        
        if (j == M) return SymbolPosition::POS_LRC;
        if ((1 < j) && (j < M)) return SymbolPosition::POS_BOT;
    }
    
    if (j == 1) {
        
        if (i == N) return SymbolPosition::POS_LLC;
        if ((1 < i) && (i < N)) return SymbolPosition::POS_LFT;
    }
    
    return SymbolPosition::POS_INN;
}