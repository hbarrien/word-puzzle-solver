#include "WordPuzzleSolver.h"

 
/* Validates arguments before initializing the corresponding 
 * instance variables
 */ 
WordPuzzleSolver::WordPuzzleSolver(
    const SymbolTable &symbolTable, 
    const WordTable &words)
    : WordPuzzleSolver((validateInput(symbolTable, words), symbolTable), words, 0) {
}

/* Arguments are valid. Initialize instance variables
 * and create the hash table
 */
WordPuzzleSolver::WordPuzzleSolver(
    const SymbolTable &symbolTable, 
    const WordTable &wordTable,
    int unused)
    : symbolTable(symbolTable), wordTable(wordTable), hashTable(buildHashTable()) {
}

/* validateInput
 * 
 * Precondition:
 *   (|symbolTable| > 0) && 
 *   ((|symbolTable.rows| > 0) && (|symbolTable.cols| > 0)) -->
 *     symbolTable is rectangular
 *   (symbolTable must be at least 3x3) &&
 *   (|words| > 0) &&
 *   (for every w in words: (w.length > 1))
 */
void WordPuzzleSolver::validateInput(
    const SymbolTable &symbolTable, 
    const WordTable &words) {
    
    if (symbolTable.size() == 0)
        throw invalid_argument("The symbol table is empty");
    
    if (!((symbolTable.numRows() > 0) || (symbolTable.numColumns() > 0)))
        throw invalid_argument("The symbol table is not rectangular");
    
    if ((symbolTable.numRows() < 3) || (symbolTable.numColumns() < 3))
        throw invalid_argument("The size of the symbol table must be at least of size 3x3");
    
    auto searchWords {words.getWords()};
    
    if (searchWords.empty())
        throw invalid_argument("The word table is empty");
    
    StringConverter converter;
    for (auto &word : searchWords) {
        
        string latin1Word {converter.to_latin1(word)};
        
        if (word.length() < 2)
            throw invalid_argument("There is at least an empty or one-letter word");
    }
}

HashTable WordPuzzleSolver::buildHashTable() {
    
    HashTable hTable;
    size_t valueCount{0};
    
    for (size_t i {1}; i <= symbolTable.numRows(); i++) {
        
        for (size_t j {1}; j <= symbolTable.numColumns(); j++) {
            
            unsigned char symbol = symbolTable.at(i, j);
            
            SymbolCoordinate value;
            value.i = i;
            value.j = j;
            value.tablePosition = symbolTable.whichPosition(i, j);
            
            hTable.addHashValue(symbol, value);
            valueCount++;
        }
    }
    
    if (hashTable.empty())
        throw invalid_argument("The hash table is empty");
    
    if (symbolTable.size() != valueCount)
        throw invalid_argument("The symbol table and hash table sizes don't match");
    
    return hTable;
}

const SymbolCoordinates& WordPuzzleSolver::getSymbolPositions(
    const string &word
) {
    
    return hashTable.getHashValues(word.at(0));
}

/* getSearchDirections
 * Given the position of a symbol within the symbol table, this 
 * program returns the possible search branching directions. For 
 * instance, if the symbol's position is at the upper left corner, 
 * the only possible searching directions are from left to right 
 * (east), diagonally and downward (south-east), and from top to 
 * bottom (south).
 * 
 */
const SearchDirections& WordPuzzleSolver::getSearchDirections(
    SymbolPosition symbolPosition) {
    
    switch(symbolPosition) {
        
        case SymbolPosition::POS_ULC:
            { 
                static const SearchDirections directions {SearchDirection::DIR_EAST, 
                                                          SearchDirection::DIR_SEAST, 
                                                          SearchDirection::DIR_SOUTH};
                return directions;
            }
        
        case SymbolPosition::POS_TOP:
            {
                static const SearchDirections directions {SearchDirection::DIR_EAST, 
                                                          SearchDirection::DIR_SEAST, 
                                                          SearchDirection::DIR_SOUTH, 
                                                          SearchDirection::DIR_SWEST, 
                                                          SearchDirection::DIR_WEST};
                return directions;
            }
        
        case SymbolPosition::POS_URC:
            {
                static const SearchDirections directions {SearchDirection::DIR_SOUTH, 
                                                          SearchDirection::DIR_SWEST, 
                                                          SearchDirection::DIR_WEST};
                return directions;
            }
        
        case SymbolPosition::POS_RGT:
            {
                static const SearchDirections directions {SearchDirection::DIR_SOUTH, 
                                                          SearchDirection::DIR_SWEST, 
                                                          SearchDirection::DIR_WEST, 
                                                          SearchDirection::DIR_NWEST, 
                                                          SearchDirection::DIR_NORTH};
                return directions;
            }
        
        case SymbolPosition::POS_LRC:
            {
                static const SearchDirections directions {SearchDirection::DIR_WEST, 
                                                          SearchDirection::DIR_NWEST, 
                                                          SearchDirection::DIR_NORTH};
                return directions;
            }
        
        case SymbolPosition::POS_BOT:
            {
                static const SearchDirections directions {SearchDirection::DIR_EAST, 
                                                          SearchDirection::DIR_WEST, 
                                                          SearchDirection::DIR_NWEST, 
                                                          SearchDirection::DIR_NORTH, 
                                                          SearchDirection::DIR_NEAST};
                return directions;
            }
        
        case SymbolPosition::POS_LLC:
            {
                static const SearchDirections directions {SearchDirection::DIR_EAST, 
                                                          SearchDirection::DIR_NORTH, 
                                                          SearchDirection::DIR_NEAST};
                return directions;
            }
        
        case SymbolPosition::POS_LFT:
            {
                static const SearchDirections directions {SearchDirection::DIR_NORTH, 
                                                          SearchDirection::DIR_NEAST, 
                                                          SearchDirection::DIR_EAST, 
                                                          SearchDirection::DIR_SEAST, 
                                                          SearchDirection::DIR_SOUTH};
                return directions;
            }
        
        case SymbolPosition::POS_INN:
            {
                static const SearchDirections directions {SearchDirection::DIR_NORTH, 
                                                          SearchDirection::DIR_NEAST, 
                                                          SearchDirection::DIR_EAST, 
                                                          SearchDirection::DIR_SEAST, 
                                                          SearchDirection::DIR_SOUTH, 
                                                          SearchDirection::DIR_SWEST, 
                                                          SearchDirection::DIR_WEST, 
                                                          SearchDirection::DIR_NWEST};
                return directions;
            }
    }
    
    static const SearchDirections directions {};
    return directions;
}

const SearchDirections& WordPuzzleSolver::getSearchDirections(
    const SymbolCoordinate &symbolCoordinate) {
    
    SymbolPosition pos = symbolCoordinate.tablePosition;
    return getSearchDirections(pos);
}

bool WordPuzzleSolver::canSearchOrthogonally(
    const string &word, 
    size_t i, 
    size_t j, 
    SearchDirection direction) {
    
    size_t lw {word.length()};
    size_t N {symbolTable.numRows()};
    size_t M {symbolTable.numColumns()};

    if (direction == SearchDirection::DIR_NORTH) return (lw <= i);
    if (direction == SearchDirection::DIR_EAST)  return (lw <= ((M-j)+1));
    if (direction == SearchDirection::DIR_SOUTH) return (lw <= ((N-i)+1));
    if (direction == SearchDirection::DIR_WEST)  return (lw <= j);
    
    return false;
}

bool WordPuzzleSolver::canSearchDiagonally(
    const string &word, 
    size_t i, 
    size_t j, 
    SearchDirection direction) {
    
    size_t N {symbolTable.numRows()};
    size_t M {symbolTable.numColumns()};
        
    int h {-1};
    int b {-1};
  
    switch(direction) {
        
        case SearchDirection::DIR_NEAST:
            {
                h = i;
                b = ((j + h) <= M) ? h : ((M - j) + 1);
            }
            break;
        
        case SearchDirection::DIR_SEAST:
            {
                size_t db {(N - i)};
                h = (db + 1);
                b = ((j + db) <= M) ? h : ((M - j) + 1);
            }
            break;
        
        case SearchDirection::DIR_SWEST: 
            {
                size_t db {(N - i)};
                h = (db + 1);
                b = ((j - db) >=  1) ? h : j;
            }
            break;
        
        case SearchDirection::DIR_NWEST: 
            {
                h = i;
                b = ((j - h) >= 1) ? h : j;
            }
            break;
        
        case SearchDirection::DIR_NORTH:
        case SearchDirection::DIR_SOUTH:
        case SearchDirection::DIR_EAST:
        case SearchDirection::DIR_WEST:
        case SearchDirection::DIR_UNKNOWN:
            return false;
    }
    
    if ((h < 0) || (b < 0))
        return false;
    
    int d = b;
    int lw = word.length();
    
    return (lw <= d);
}

bool WordPuzzleSolver::canSearch(
    const string &word, 
    size_t i, 
    size_t j, 
    SearchDirection direction) {
    
    return (canSearchOrthogonally(word, i, j, direction) ||
            canSearchDiagonally(word, i, j, direction));
}

size_t WordPuzzleSolver::getNexti(
    size_t i, 
    SearchDirection direction) {
    
    return (i + NEXT_i.at(static_cast<int>(direction)));
}

size_t WordPuzzleSolver::getNextj(
    size_t j, 
    SearchDirection direction) {
    
    return (j + NEXT_j.at(static_cast<int>(direction)));
}

WordRecord WordPuzzleSolver::solve(
    const string &word) {
    
    bool done {false};
    auto &symbolPositions = getSymbolPositions(word);
    WordRecord wordRecord = create(word);
    
    for (auto &symbolPosition : symbolPositions) {
    
        size_t i = symbolPosition.i;
        size_t j = symbolPosition.j;
        auto &directions = getSearchDirections(symbolPosition);
             
        for (auto direction : directions) {
        
            if (!canSearch(word, i, j, direction))
                continue;
                    
            if (match(word, i, j, direction)) {
            
                update(wordRecord, i, j, direction);
                done = true;
                break;
            }
        }
            
        if (done) break;
    }
    
    return wordRecord;
}

bool WordPuzzleSolver::match(
    string word, 
    size_t i, 
    size_t j, 
    SearchDirection direction) {
    
    bool done {false};
    
    size_t wordIdx {0};
    size_t lenWord = word.length();
    
    while (!done) {
                
        unsigned char wordSymBolTable {symbolTable.at(i, j)};
        unsigned char searchWord  {static_cast<unsigned char>(word.at(wordIdx))};

        if (wordSymBolTable != searchWord)
            return false;
        
        if (++wordIdx == lenWord) {
            done = true;
            continue;
        }
        
        i = getNexti(i, direction);
        j = getNextj(j, direction);
    }
    
    return true;
}

WordRecord WordPuzzleSolver::create(
    const string &word) {
    
    WordRecord wordRecord;
    wordRecord.term = word;
    return wordRecord;
}

void WordPuzzleSolver::update(
    WordRecord &wordRecord, 
    size_t i, 
    size_t j, 
    SearchDirection direction) {
    
    wordRecord.i = i;
    wordRecord.j = j;
    wordRecord.direction = direction;
}

/* matchWords
 * Searches all words from wordTable in symbolTable. Given 
 * that every word search is independent and no data mutation 
 * is possible, all searches are executed as thread processes.
 * 
 * Postcondition:
 * (for every word in searchWords:
 *   word was duly processed (either found or not found in symbolTable) &&
 *   word was included in a WordRecord instance)
 */
WordContainer WordPuzzleSolver::matchWords() {
    
    ThreadPool pool(std::thread::hardware_concurrency());
    mutex results_mutex;
    WordContainer result;
    
    auto searchWords {wordTable.getWords()};
    
    for (auto &word : searchWords) {
        
        pool.enqueue([&, word] {
            
            WordRecord wordRecord = solve(word);
            std::lock_guard<std::mutex> lock(results_mutex);
            result.add(std::move(wordRecord));
        });
    }
    
    return result;
}
