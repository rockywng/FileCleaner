#include "indents.h"
using namespace std;

int find_replace(string &s, string const& current, string const& newstr) {
    int changes = 0;
    size_t pos = s.find(current);
    while (pos != string::npos) {
        changes++;
        s.replace(pos, current.size(), newstr);
        pos = s.find(current, pos + newstr.size());
    }
    return changes;
}

int swap_indentations(string &code_line) {
    int changes = find_replace(code_line, "    ", "\t");
    return changes;
}