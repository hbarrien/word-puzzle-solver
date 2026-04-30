Word Puzzle Solver
==================
DATE: 
2026-04-28

AUTHOR: 
Herbert Barrientos (hpbarr@gmail.com)

DESCRIPTION:  
The game
========
This program (i.e., the "solver") solves the word puzzle game, a challenge 
in which the player is presented with a set of letters (i.e., symbols) 
arranged as an n x m table (each table position holding one symbol) and a 
set of words. The words are embedded within the table. A word is read in 
a particular direction (e.g., row-wise, column-wise, or diagonally) either 
from left to right or viceversa, from top to bottom or viceversa, or 
diagonally in one of four directions. The player's task is to find the 
words and mark them by drawing an oval around the word.

Motivation
==========
The author had originally develeped this solution in R. When testing 
with letter tables greater than 100x100 (1000x1000 with 80 words, 
only 6 words present in the table), serious performance degradation 
was observed (ca. 42 minutes). The author then programmed the same 
solution in C++ to analyze performance and resource usage differences. 
Of course, in order to make the new implementation C++ idiomatic, some 
changes were introduced.

Data structures
===============
const SymbolTable symbolTable: the letter grid.  
const WordTable wordTable: the word list.  
const HashTable hashTable: contains positional references of all symbols.  

Setup
=====
Initially, input data (letter table and word list) are read from text files. 
The solver validates the input data and stores it as copies in internal data 
structures (symbolTable and wordTable). Next, the solver creates a hashTable 
using symbolTable as input. The hashTable's key is a symbol, and its associated 
value is a list of all positions where the symbol is found within symbolTable. 
Each symbol position element also contains information of where in symbolTable 
it is located: a corner, the top or bottom row, the first or last column, or 
an internal table location.

Precondition
============
(|symbolTable| > 0) &&   
(symbolTable is rectangular)  
(symbolTable must be at least 3x3) &&  
(|words| > 0) && 
(for every w in words: (w.length > 1))  

Search process
==============
The search process is executed as follows:
- The solver creates an output container.
- For every word:
  - The solver creates a word record and copies the word to it. By default, 
    the word record contains invalid location indices and an unknown read 
    direction.
  - The solver takes the word's first letter and uses it as key to obtain its 
    associated list of symbol positions from the hashTable.
  - For every symbol position:
    - the solver determines its location and derives the search direction. For 
      instance, if the symbol is located on the top left corner, the possible 
      search directions are row-wise following an "east" direction, or diagonally 
      following a "south-east" direction, or column-wise following a "south" 
      direction.
  - For every search direction:
    - The solver compares the next word's letter against the next table symbol.
    - If a complete match is achieved:
      - the search stops,
      - the word record is updated with the word's location indices and the 
        read direction,
      - the word record is added to the output container,
      - the solver continues with the next word.
  - If all search directions were attempted and no match was found, the word 
    record is simply added to the output container.

Returns
=======
The output container.

Postcondition
=============
For every word in wordTable:
  - The word was included in a word record &&
  - The word was duly processed (either found or not found in symbolTable) &&
(|output container| == |wordTable|)

CONSTRAINTS:
1-based indexing
================
- The initial implementation was developed in R, which uses 1-based vector and 
  table indexing. To keep all original (and correctly working) index calculations 
  as they are, index conversion from 0-based to 1-based was necessary.
- Given diacritic symbol display problems, this implementation is Windows-dependent.

INVARIANTS:
Structural Integrity
====================
- Grid Consistency: 
  - symbolTable is a non-empty matrix where (|rows| > 0) and |columns > 0|.
  - symbolTable is rectangular: all rows have exactly the same number of columns.
- Every entry in wordTable has a length >= 2.
- hashTable contains a mapping for every coordinate in the symbolTable, indexed 
  by the character at that position.

Ownership & Lifecycle
=====================
- Encapsulation: The solver maintains exclusive, private ownership of all data; 
  no external references can modify the internal state.
- Single-Puzzle Binding: A solver instance is permanently bound to its initial 
  dataset; it cannot be re-initialized or cleared.

Temporal Immutability
=====================
- Post-Construction Freeze: The solver maintains a physically and logically 
  immutable state. All internal data structures are declared const and initialized 
  atomically during construction.
- Stateless Execution: Immutability ensures both idempotency and thread-safety for 
  the entire lifetime of the solver instance.

TESTING:
The solver has been successfully tested:
- 1000x1000 with 80 words (only 6 words present in symbolTable): 0.418135 seconds
- 1000x1000 with 80 words (all 80 words present in symbolTable): 0.276248 seconds
- 1000x1000 with 600 words (all 600 words present in symbolTable): 1.35744 seconds
- 5000x5000 with 2000 words (all 2000 words present in symbolTable): 123.273 seconds

The solver has also been successfully tested with words containing diacritic characters
in Spanish, Portuguese, French, Italian, and German.
