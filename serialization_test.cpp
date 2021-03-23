//
// Created by Riley Quinn on 3/23/21.
//

#include "Serializer.h"
#include <iostream>

struct Test {
    std::ostream &serialize(std::ostream &os) const {
        Serializer::serialize(os, List{"a", "b", "c", List{"1", "2", "3"}});
        return os;
    }
};

int main() {
    auto serialize = Serializer::bind(std::cout);
    serialize(Test{});
}