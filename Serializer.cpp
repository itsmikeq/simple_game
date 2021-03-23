//
// Created by Riley Quinn on 3/20/21.
//

#include "Serializer.h"

std::ostream &List::serialize(std::ostream &os) const {
    Serializer::serialize(os, Serializer::Type::List);
    for (const auto &object : objects) {
        Serializer::serialize(os, object);
    }
    Serializer::serialize(os, Serializer::Type::End);
    return os;
}

std::ostream &Dictionary::serialize(std::ostream &os) const {
    // TODO implement dictionary serialization
    return os;
}

std::ostream &SerializableObject::serialize(std::ostream &os) const {
    std::visit([&os]<typename T>(T &&object) { Serializer::serialize(os, std::forward<T>(object)); }, value);
    return os;
}
