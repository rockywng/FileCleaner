#ifndef INDENTS_H
#define INDENTS_H

#include <stdio.h>
#include <string>
#include <iostream>

// Find and replace all instances of substr current with newstr in the string s
int find_replace(std::string &s, std::string const& current, std::string const& newstr);

// Remove leading spaces and replace with a tab
int swap_indentations(std::string &code_line);

#endif