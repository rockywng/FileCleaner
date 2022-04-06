#include "clean.h"
using namespace std;

std::tuple<int, int, int, int, int> clean(string filename) {
    int ifndefs = 0;
    int defines = 0;
    int endifs = 0;
    int newlines = 0;
    int spaces = 0;
    int line = 0;
    int changes = 0;
    string type = getFileType(filename);
    string name = getFileName(filename);
    bool introguard = false;
    bool endguard = false;
    if (type.compare("h") != 0) {
        introguard = true;
        endguard = true;
    }
    string newfilename = name + "clean." + type; 
    ofstream outfile (newfilename);
    vector<string> lines = readFile(filename);
    int len = lines.size();
    for (int i = 0; i < len; i++) {
        if (!introguard) {
            if (ifndef(lines[0])) {
                outfile << "#ifndef TEMP_H\n";
                changes++;
                ifndefs++;
            }
            if (define(lines[1])) {
                outfile << "#define TEMP_H\n";
                changes++;
                defines++;
            }
            introguard = true;
        }
        string current = lines[i];
        int swaps = swap_indentations(current);
        spaces += swaps;
        if (i != len - 1) {
            outfile << current << "\n";
            if (newLineNeeded(current, lines[i + 1])) {
                outfile << "\n";
                newlines++;
            }
        }
        else if (i == len - 1) {
            outfile << current;
            if (!endguard) {
                if (endif(lines[len - 1])) {
                    outfile << "\n#endif";
                    changes++;
                    endifs++;
                }
                endguard = true;
            }
        }
    }
    return make_tuple(spaces, newlines, ifndefs, defines, endifs);

}