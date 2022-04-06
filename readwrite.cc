#include "readwrite.h"
using namespace std;

void write(string filename, vector<string> lines) {
    ofstream outfile (filename);
    for (vector<string>::iterator it = begin(lines); it != end(lines); it++) {
        outfile << *it << endl;
    }
}

vector<string> readFile(string filename) {
    vector<string> lines;
    ifstream infile (filename);
    string line;
    if (infile.is_open()) {
        while (getline(infile, line)) {
            lines.push_back(line);
        }
        infile.close();
    }
    else {
        cout << "The file could not be opened." << endl;
    }
    return lines;
}