//
// Created by Riley Quinn on 3/20/21.
//

#ifndef SIMPLE_GAME_SERIALIZER_H
#define SIMPLE_GAME_SERIALIZER_H

#include "serializer_concepts.h"

#include <ostream>
#include <type_traits>
#include <utility>
#include <vector>
#include <variant>
#include <unordered_map>

/// Serializes objects and writes them to an output stream.
class Serializer {
public:
    /// Type of serialized object. The type is prefixed to any serialized data.
    enum class Type : char {
        Int = 'i',
        Float = 'f',
        String = 's',
        Bool = 'b',
        List = 'l',
        Dictionary = 'd',
        End = 'e',
    };

    /// Serialize any object that satisfies the serializable concept
    /// \tparam T a type that satisfies serializable
    /// \param os output stream
    /// \param object
    /// \sa serializable
    template<serializable T>
    static void serialize(std::ostream &os, T &&object) {
        is_serializable<T>::serialize(os, std::forward<T>(object));
    }

    /// Serializes Type to an output stream
    /// \param os output stream
    /// \param type serializer type
    /// \sa Serializer::Type
    static void serialize(std::ostream &os, Type type) {
        serialize(os, char(type));
    }

    /// Serializes an integer
    /// \param os output stream
    /// \param n integer value
    static void serialize(std::ostream &os, int n) {
        serialize(os, Type::Int);
        serialize(os, asBytes(n));
    }

    /// Serializes a float
    /// \param os output string
    /// \param n float value
    static void serialize(std::ostream &os, float n) {
        serialize(os, Type::Float);
        serialize(os, asBytes(n));
    }

    /// Serializes a string
    /// \param os output stream
    /// \param str string value
    static void serialize(std::ostream &os, std::string_view str) {
        serialize(os, Type::String);
        serialize(os, asBytes(str.size()));
        serialize(os, str.data());
    }

    /// Serializes a bool
    /// \param os output stream
    /// \param value bool value
    static void serialize(std::ostream &os, bool value) {
        serialize(os, Type::Bool);
        serialize(os, asBytes(value));
    }

    /// \overload Serializer::serialize(std::ostream&, std::string_view)
    static void serialize(std::ostream &os, const std::string &str) {
        serialize(os, std::string_view{str});
    }

    /// Returns a serialize functor with the passed stream bound to the first argument. This is useful for when you
    /// use the same stream and don't want to pass it into each invocation of serialize.
    /// \code{.cpp}
    /// auto serialize = Serializer::bind(std::cout);
    /// serialize("Hello, world!"); // equivalent to s.serialize(std::cout, "hello world");
    /// \endcode
    /// \param os output stream
    /// \return serialize functor
    static auto bind(std::ostream &os) {
        return [&os]<typename T>(T &&object) {
            Serializer::serialize(os, std::forward<T>(object));
        };
    }

private:
    /// Returns the bytes of an object. This is might be unsafe.
    /// \tparam T type of object
    /// \param object object to cast to bytes
    /// \return object as bytes
    template<typename T>
    static const char *asBytes(const T &object) {
        return reinterpret_cast<const char *>(&object);
    }
};

struct SerializableObject;

struct List {
    std::vector<SerializableObject> objects;

    List(const std::initializer_list<SerializableObject> &list) : objects(list) {}

    template<typename ...Args>
    requires(std::is_convertible_v<Args, SerializableObject> &&...)
    explicit List(Args &&...args) {
        objects.emplace_back(std::forward<Args>(args)...);
    }

    template<typename Begin, typename End>
    List(Begin &&begin, End &&end) : objects(std::forward<Begin>(begin), std::forward<End>(end)) {}

    template<typename Container>
    requires (requires(Container c) { std::begin(c); std::end(c); })
    List(Container &&c) : List(std::forward<Container>(c).begin(), std::forward<Container>(c).end()) {}

    std::ostream &serialize(std::ostream &os) const;
};

struct Dictionary {
    using key_type = std::string;
    using value_type = SerializableObject;

    std::unordered_map<key_type, value_type> objects;

    Dictionary(const std::initializer_list<std::pair<const key_type, value_type>> &list) : objects(list) {}

    std::ostream &serialize(std::ostream &os) const;
};

struct SerializableObject {
    using value_type = std::variant<int, float, std::string, bool, List, Dictionary>;
    value_type value;

    SerializableObject(value_type value) : value(std::move(value)) {}

    template<typename T> requires(std::is_convertible_v<T, value_type>)
    SerializableObject(T && object) : value(std::forward<T>(object)) {}

    std::ostream &serialize(std::ostream &os) const;
};

#endif //SIMPLE_GAME_SERIALIZER_H
