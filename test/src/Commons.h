#include <iostream>
#include <vector>
#include <string>
#include <Colors/Colors.h>

#define SUCCESS 0
#define FAILURE -1

using colors::Color, colors::Colors, colors::Attr;

std::string codes(std::string cds) {
    return "\033[" + cds + "m";
}
