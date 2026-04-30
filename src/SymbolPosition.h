#ifndef _SYMBOL_POSITION_H_
#define _SYMBOL_POSITION_H_


/* Positional reference of a symbol within
 * the symbol table 
 */
enum class SymbolPosition {
    POS_ULC,  // Upper-left corner
    POS_TOP,  // Top row
    POS_URC,  // Upper-right corner
    POS_RGT,  // Right edge (last column)
    POS_LRC,  // Lower-right corner
    POS_BOT,  // Bottom row
    POS_LLC,  // Lower-left corner
    POS_LFT,  // Left edge (first column)
    POS_INN   // Inner cell
};

#endif // _SYMBOL_POSITION_H_
