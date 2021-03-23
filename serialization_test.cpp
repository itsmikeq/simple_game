//
// Created by Riley Quinn on 3/23/21.
//

#include "Serializer.h"
#include <iostream>

struct Test {
    std::vector<std::string> colors = {"Red", "Blue", "Green", "Yellow"};

    std::ostream &serialize(std::ostream &os) const {
        Serializer::serialize(os, Dictionary{
                {"colors", SerializableObject{colors}}
        });
        return os;
    }
};

int main() {
    auto serialize = Serializer::bind(std::cout);
    serialize(Test{});
}