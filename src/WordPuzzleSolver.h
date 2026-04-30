#ifndef _WORD_PUZZLE_SOLVER_H_
#define _WORD_PUZZLE_SOLVER_H_

#include <vector>
#include <string>

#include "SearchDirection.h"
#include "SymbolCoordinate.h"
#include "SymbolTable.h"
#include "WordTable.h"
#include "HashTable.h"
#include "WordRecord.h"
#include "WordContainer.h"
#include "ThreadPool.h"
#include "StringConverter.h"

using namespace std;


typedef vector<SearchDirection> SearchDirections;

class WordPuzzleSolver {
    
private:
    /* Depending on the search direction, these two vectors
     * indicate how the next position is to be calculated,
     * e.g., adding 1 to the index value, subtracting 1 to
     * the index value, or neither adding nor subtracting
     *
     *                         N  NE  E SE   S  SW   W  NW
     */
    const vector<int> NEXT_i {-1, -1, 0, 1,  1,  1,  0, -1};
    const vector<int> NEXT_j { 0,  1, 1, 1,  0, -1, -1, -1};
    
    const SymbolTable symbolTable;
    const WordTable wordTable;
    const HashTable hashTable;
    
    WordPuzzleSolver(
        const SymbolTable &symbolTable, 
        const WordTable &words,
        int /* unused */
    );
    
    void validateInput(
        const SymbolTable &symbolTable, 
        const WordTable &words
    );
    
    HashTable buildHashTable();
    
    const SymbolCoordinates &getSymbolPositions(
        const string &word
    );
    
    const SearchDirections &getSearchDirections(
        SymbolPosition symbolPosition
    );
    
    const SearchDirections &getSearchDirections(
        const SymbolCoordinate &symbolCoordinate
    );

    bool canSearchOrthogonally(
        const string &word, 
        size_t i, 
        size_t j, 
        SearchDirection direction
    );
    
    bool canSearchDiagonally
        (const string &word, 
        size_t i, 
        size_t j, 
        SearchDirection direction
    );
    
    bool canSearch(
        const string &word, 
        size_t i, 
        size_t j, 
        SearchDirection direction
    );
    
    size_t getNexti(
        size_t i, 
        SearchDirection direction
    );
    
    size_t getNextj(
        size_t j, 
        SearchDirection direction
    );
    
    WordRecord solve(
        const string &word
    );
    
    bool match(
        string word, 
        size_t i, 
        size_t j, 
        SearchDirection direction
    );
    
    WordRecord create(
        const string &word
    );
    
    void update(
        WordRecord &wordRecord, 
        size_t i, 
        size_t j, 
        SearchDirection direction
    );

public:
    WordPuzzleSolver(
        const SymbolTable &symbolTable, 
        const WordTable &words
    );
    
    ~WordPuzzleSolver() = default;
    
    WordContainer matchWords();
};

#endif // _WORD_PUZZLE_SOLVER_H_
