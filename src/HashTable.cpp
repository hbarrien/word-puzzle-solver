#include "HashTable.h"


void HashTable::addHashValue(const unsigned char symbol, const SymbolCoordinate value) {
        
    /* Advantages of adding a value using the [] operator:
     * a) if the value does not exist, it is added; if it exists,
     *    the value is appended to the existing key
     * b) Faster than using at() in tight loops
     */
    hashTable[symbol].push_back(value);
}

const SymbolCoordinates& HashTable::getHashValues(const unsigned char symbol) const {
    
    /* If symbol does not exist in hashTable, the .at() method 
     * will throw an exception. In order to return an object
     * reference useful to the caller, the static, "empty" 
     * variable is returned. The variable lives until process 
     * termination, time during which static memory is reclaimed 
     * by the OS, thus not creating memory leaks.
     * 
     * Advantages of this approach:
     * a) the variable is created only once, regardless of how
     *    many times the program is called
     * b) the implementation is thread-safe
     */
    static const SymbolCoordinates empty{};

    try {
        return hashTable.at(symbol);
        
    } catch (const out_of_range &exp) {
        
        return empty;
    }
}

bool HashTable::empty() const {
    
    return hashTable.empty();
}

size_t HashTable::size() const {
    
    return hashTable.size();
}