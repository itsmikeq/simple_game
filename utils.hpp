//
// Created by Mike Quinn on 3/18/21.
//

#ifndef SIMPLE_GAME_UTILS_HPP
#define SIMPLE_GAME_UTILS_HPP

#include <string>

std::string choppa(const std::string &t, const std::string &ws);

template<typename T>
constexpr bool bad_serialize = false;

template<typename T>
std::ostream &serialize(std::ostream &os, const T &object) {
    static_assert(bad_serialize<T>, "serialize not specialized for type");
}

template<typename T>
std::ostream &serialize(std::ostream &os, const T &object) requires (requires { os << object; }) {
    return os << object;
}

template<typename T>
concept serializable_class = requires(std::ostream &s, T t) { t.serialize(s); };

template<serializable_class T>
std::ostream &serialize(std::ostream &os, const T &object) {
    object.serialize(os);
    return os;
}

enum SerializeEnum {
    List,
    Object,
    Int,
    String,
    Map,
};

#endif //SIMPLE_GAME_UTILS_HPP
