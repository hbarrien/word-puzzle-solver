#ifndef _WORD_RECORD_H_
#define _WORD_RECORD_H_

#include <string>
#include <cstddef>

#include "SearchDirection.h"

using namespace std;


// Output record for a processed word
struct WordRecord {
    string term {};
    size_t i {0};
    size_t j {0};
    SearchDirection direction {SearchDirection::DIR_UNKNOWN};
};

#endif // _WORD_RECORD_H_
