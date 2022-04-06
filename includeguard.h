#ifndef INCLUDEGUARD_H
#define INCLUDEGUARD_H

#include <string>
#include <stdio.h>

// Check if given string begins with #ifndef
bool ifndef(std::string first_line);

// Check if given string begins with #define
bool define(std::string second_line);

// Check if given string is #endif
bool endif(std::string last_line);

#endif