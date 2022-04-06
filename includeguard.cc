#include "includeguard.h"
using namespace std;

bool ifndef(string first_line) {
    if (first_line.substr(0, 7).compare("#ifndef") == 0) {
        return false;
    }
    else {
        return true;
    }
}

bool define(string second_line) {
    if (second_line.substr(0, 7).compare("#define") == 0) {
        return false;
    }
    else {
        return true;
    }
}

bool endif(string last_line) {
    if (last_line.compare("#endif") == 0) {
        return false;
    }
    else {
        return true;
    }
}