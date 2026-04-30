#ifdef _WIN32
#include <windows.h>
#endif

#include <iostream>
#include <chrono>
#include <iomanip>

#include "SymbolTable.h"
#include "WordTable.h"
#include "SearchDirection.h"
#include "WordPuzzleSolver.h"
#include "WordContainer.h"
#include "WordRecord.h"
#include "StringConverter.h"

using namespace std;


/* ***************************
 * ** FUNCTION PROTOTYPES ****
 * ***************************
 */
vector<WordRecord> searchWords(string sPath, string wPath);
string directionToString(SearchDirection direction);
void displayResults(vector<WordRecord> words);


/* ***************************
 * ********* MAIN ************
 * ***************************
 */
int main() {
    
    #ifdef _WIN32
    // This command tells Windows: "I am sending you UTF-8 data"
    SetConsoleOutputCP(65001);
    // Optional: Set input to UTF-8 as well
    SetConsoleCP(65001); 
    #endif
    
    string sPath {"C:/word_puzzle_data/grid.txt"};
    string wPath {"C:/word_puzzle_data/words.txt"};
    
    auto start = chrono::high_resolution_clock::now();
    auto words = searchWords(sPath, wPath);
    auto end = chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> diff = end - start;
    std::cout << "Duration. " << diff.count() << " seconds\n" << endl << endl;
    
    displayResults(words);
    
    return 0;
}


/* ***************************
 * ******* FUNCTIONS *********
 * ***************************
 */
vector<WordRecord> searchWords(string sPath, string wPath) {
    
    cout << "creating symbol table..." << endl;
    SymbolTable symbolTable(sPath);
    cout << "done..." << endl;
    
    cout << "creating words table..." << endl;
    WordTable wordTable(wPath);
    cout << "done..." << endl;
    
    cout << "solving word puzzle..." << endl;
    WordPuzzleSolver solver(symbolTable, wordTable);
    WordContainer result = solver.matchWords();
    cout << "done..." << endl;
    
    return(result.getWordRecords());
}

string directionToString(SearchDirection direction) {
    
    switch(direction) {
        case SearchDirection::DIR_NORTH:
            return "NORTH";
            
        case SearchDirection::DIR_NEAST:
            return "NORTH-EAST";
            
        case SearchDirection::DIR_EAST:
            return "EAST";
            
        case SearchDirection::DIR_SEAST:
            return "SOUTH-EAST";
            
        case SearchDirection::DIR_SOUTH:
            return "SOUTH";
            
        case SearchDirection::DIR_SWEST:
            return "SOUTH-WEST";
            
        case SearchDirection::DIR_WEST:
            return "WEST";
            
        case SearchDirection::DIR_NWEST:
            return "NORTH-WEST";
            
        case SearchDirection::DIR_UNKNOWN:
            return "UNKNOWN";
    }
    
    return "ERROR";
}

void displayResults(vector<WordRecord> words) {

    cout << left << setw(30) << "Word"
         << left << setw(6) << "i"
         << left << setw(6) << "j"
         << left << setw(10) << "Direction" << endl
         << string(52, '-') << endl;
    
    StringConverter converter;
    for (auto &wordRecord : words) {
        
        cout << left << setw(30) << converter.to_string(wordRecord.term)
             << left << setw(6)  << wordRecord.i 
             << left << setw(6)  << wordRecord.j 
             << left << setw(10) << directionToString(wordRecord.direction)
             << endl;
    }
}