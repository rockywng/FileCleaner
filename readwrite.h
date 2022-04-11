#ifndef READWRITE_H
#define READWRITE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

// Write strings from provided vector of strings to provided file
void write(std::string filename, std::vector<std::string> lines);

// Read lines from given file and return them as a vector of strings
std::vector<std::string> readFile(std::string filename);

#endif
