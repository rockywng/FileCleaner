#ifndef NEWLINE_H
#define NEWLINE_H

#include <string>
#include <stdio.h>

// Returns a bool representing if the given string is entirely 
// made up of spaces
bool allSpaces(std::string str);

// Returns a bool representing if a newline should be added after
// the given line of code
bool newLineNeeded(std::string code_line, std::string next_line);

#endif