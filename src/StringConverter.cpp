#include "StringConverter.h"

 
string StringConverter::to_latin1(const string &s) {
    
    string out;
    out.reserve(s.size());

    for (size_t i = 0; i < s.size(); ) {

        unsigned char c = static_cast<unsigned char>(s[i]);

        if (c < 0x80) {
            // ASCII
            out.push_back(static_cast<char>(c));
            i++;
        }
        else if ((c & 0xE0) == 0xC0 && i + 1 < s.size()) {
            // 2-byte UTF-8
            unsigned char c1 = static_cast<unsigned char>(s[i+1]);

            // Decode Unicode codepoint
            unsigned int code = ((c & 0x1F) << 6) | (c1 & 0x3F);

            // Latin-1 range only
            if (code <= 0xFF) {
                out.push_back(static_cast<char>(code));
            } else {
                out.push_back('?');
            }

            i += 2;
        }
        else {
            // Skip 3- and 4-byte UTF-8 sequences
            out.push_back('?');

            if      ((c & 0xF0) == 0xE0) i += 3;
            else if ((c & 0xF8) == 0xF0) i += 4;
            else i++;
        }
    }

    return out;
}

string StringConverter::to_string(const string &s)
{
    std::string result;
    result.reserve(s.size() * 1.5); 

    for (unsigned char c : s) {
        if (c <= 0x7F) {
            result.push_back(static_cast<char>(c));
            
        } else {
            
            // Correct formula to convert Latin-1 (0x80-0xFF) to UTF-8
            // This handles the shift between the C2 and C3 UTF-8 blocks
            result.push_back(static_cast<char>(0xC0 | (c >> 6)));
            result.push_back(static_cast<char>(0x80 | (c & 0x3F)));
        }
    }
    
    return result;
}