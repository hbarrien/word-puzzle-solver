#ifndef _STRING_CONVERTER_H_
#define _STRING_CONVERTER_H_

#include <string>
using namespace std;


// IMPORTANT NOTE: This is an externally-created implementation 
class StringConverter
{
public:
    StringConverter()  = default;
    ~StringConverter() = default;
    
    string to_latin1(const string &s);
    string to_string(const string &s);
};

#endif // _STRING_CONVERTER_H_
