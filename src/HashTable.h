#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#include <unordered_map>
#include <stdexcept>

#include "SymbolCoordinate.h"

using namespace std;


class HashTable {
    
private:
    unordered_map<char, SymbolCoordinates> hashTable;
    
public:
    HashTable() = default;
    ~HashTable() = default;
    
    void addHashValue(const unsigned char symbol, const SymbolCoordinate value);
    const SymbolCoordinates &getHashValues(const unsigned char symbol) const;
    
    bool empty() const;
    size_t size() const;
};

#endif // _HASH_TABLE_H_
