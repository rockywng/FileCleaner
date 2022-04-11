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
    // Setup file stream
    ofstream datafile;
    // Add absolute path to data file
    datafile.open("data.dat", ios_base::app);
    // Assign tuple to clean values
    tuple<int, int, int, int, int> values = clean(name);
    // Retrieve cleaning values
    int spaces = get<0>(values);
    int newlines = get<1>(values);
    int ifndefs = get<2>(values);
    int defines = get<3>(values);
    // Write cleaning values to datafile
    datafile << name << ", " << spaces << ", " << newlines << ", " << ifndefs << ", " << defines << endl;
    // Inform user of succesful cleaning
    cout << "The file has been successfully cleaned." << endl;
}
