#include "filename.h"
using namespace std;

string getFileName(std::string file) {
    int dot = file.find(".");
    return file.substr(0, dot);
}

string getFileType(std::string file) {
    int dot = file.find(".");
    int len = file.length();
    return file.substr(dot + 1, len - dot);
}