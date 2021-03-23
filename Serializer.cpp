//
// Created by Riley Quinn on 3/20/21.
//

#include "Serializer.h"

std::ostream &List::serialize(std::ostream &os) const {
    auto serialize = Serializer::bind(os);
    serialize(Serializer::Type::List);
    for (const auto &object : objects) {
        serialize(object);
    }
    serialize(Serializer::Type::End);
    return os;
}

std::ostream &Dictionary::serialize(std::ostream &os) const {
    auto serialize = Serializer::bind(os);
    serialize(Serializer::Type::Dictionary);
    for (const auto &[key, value] : objects) {
        serialize(key);
        serialize(value);
    }
    serialize(Serializer::Type::End);
    return os;
}

std::ostream &SerializableObject::serialize(std::ostream &os) const {
    std::visit([&os]<typename T>(T &&object) { Serializer::serialize(os, std::forward<T>(object)); }, value);
    return os;
}
