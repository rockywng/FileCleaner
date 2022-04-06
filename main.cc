#include "indents.h"
#include "newline.h"
#include "includeguard.h"
#include "filename.h"
#include "readwrite.h"
#include "clean.h"
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

int main(int argc, char *argv[]) {
    // Require full path to file
    string name = argv[1];
    //string name = "jojo.h";
    ofstream datafile;
    // Add absolute path
    datafile.open("data.dat", ios_base::app);
    tuple<int, int, int, int, int> values = clean(name);
    int spaces = get<0>(values);
    int newlines = get<1>(values);
    int ifndefs = get<2>(values);
    int defines = get<3>(values);
    datafile << name << ", " << spaces << ", " << newlines << ", " << ifndefs << ", " << defines << endl;
    cout << "The file has been successfully cleaned." << endl;
}