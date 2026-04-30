#ifndef _SYMBOL_COORDINATE_H_
#define _SYMBOL_COORDINATE_H_

#include <vector>
#include "SymbolPosition.h"

using namespace std;


/* Coordinates of a symbol within the symbol table,
 * as well as its positional reference (e.g., corner, 
 * top row, right-most column, etc.)
 */
struct SymbolCoordinate {
    
    int i;  // row number
    int j;  // column number
    SymbolPosition tablePosition;
};

typedef vector<SymbolCoordinate> SymbolCoordinates;

#endif // _SYMBOL_COORDINATE_H_
