#ifndef CLEAN_H
#define CLEAN_H
#include <string>
#include <vector>
#include <iterator>
#include <fstream>
#include <iostream>
#include <tuple>
#include "filename.h"
#include "includeguard.h"
#include "indents.h"
#include "newline.h"
#include "readwrite.h"

std::tuple<int, int, int, int, int> clean(std::string filename);

#endif