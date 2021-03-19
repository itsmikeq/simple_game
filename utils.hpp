//
// Created by Mike Quinn on 3/18/21.
//

#ifndef SIMPLE_GAME_UTILS_HPP
#define SIMPLE_GAME_UTILS_HPP

std::string choppa(const std::string &t, const std::string &ws)
{
    std::string str = t;
    size_t found;
    found = str.find_last_not_of(ws);
    if (found != std::string::npos)
        str.erase(found+1);
    else
        str.clear();            // str is all whitespace

    return str;
}

#endif //SIMPLE_GAME_UTILS_HPP
