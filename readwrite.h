#ifndef READWRITE_H
#define READWRITE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

void write(std::string filename, std::vector<std::string> lines);

std::vector<std::string> readFile(std::string filename);

#endif