#include "newline.h"
using namespace std;

bool allSpaces(string str) {
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            return false;
        }
    }
    return true;
}

bool newLineNeeded(string code_line, string next_line) {
    if (code_line.compare("}") == 0) {
        if (next_line.substr(0, 5).compare("else ") == 0) {
            return false;
        }
        else if (allSpaces(next_line)) {
            return false;
        }
        return true;
    }
    return false;
}

