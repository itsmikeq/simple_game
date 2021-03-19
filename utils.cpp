//
// Created by Mike Quinn on 3/19/21.
//

#include "utils.hpp"

std::string choppa(const std::string &t, const std::string &ws) {
    std::string str = t;
    size_t found;
    found = str.find_last_not_of(ws);
    if (found != std::string::npos)
        str.erase(found + 1);
    else
        str.clear();            // str is all whitespace

    return str;
}
