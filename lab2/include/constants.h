#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <string>
using namespace std;

namespace constants 
{
    const char COMMENT = '#';
    const char DIMENSION_SEPARATOR = ' ';
    const char M_VALUES_SEPARATOR = ',';

    const char SCALAR = '0';
    const char MATRIX = '1';

    const char sADD = 'a';
    const char sSUB = 's';
    const char sMUL = 'm';
    const char sDIV = 'd';

    const char ADD = 'A';
    const char SUB = 'S';
    const char MUL = 'M';
    const char TRANSPOSE = 'T';
    const char DETERMINANT = 'X';

    const char INVALID = '?';
    const char *const ALLOWED = ":asmdASMTX";

    const string LOG_FILE = "logs.log";
} 

#endif  // _CONSTANTS_H_