#ifndef _SEARCH_DIRECTION_H_
#define _SEARCH_DIRECTION_H_


// Word search direction within the symbol table
enum class SearchDirection {
    DIR_NORTH,  // North
    DIR_NEAST,  // North-East
    DIR_EAST,   // EAST
    DIR_SEAST,  // South-East
    DIR_SOUTH,  // South
    DIR_SWEST,  // South-West
    DIR_WEST,   // West
    DIR_NWEST,  // North-West
    DIR_UNKNOWN // Unknown
};

#endif // _SEARCH_DIRECTION_H_
