//
// Created by Riley Quinn on 3/20/21.
//

#ifndef SIMPLE_GAME_SERIALIZER_CONCEPTS_H
#define SIMPLE_GAME_SERIALIZER_CONCEPTS_H

#include <ostream>
#include <type_traits>

/// \internal
namespace detail {
    /// Satisfied if T and U are the same. It is equivalent to std::is_same_v<T, U>.
    /// \note once compilers properly implement the concepts library this can be removed.
    /// \tparam T first type
    /// \tparam U second type
    template<typename T, typename U>
    concept same_as = std::is_same_v<T, U>;

    /// Satisfied if T is convertible to U. It is equivalent to std::is_convertible_v<T, U>.
    /// \note once compilers properly implement the concepts library this can be removed.
    /// \tparam T first type
    /// \tparam U second type
    template<typename T, typename U>
    concept convertible_to = std::is_convertible_v<T, U>;

    /// Satisfied if T can be written to to a std::ostream.
    /// \tparam T
    template<typename T>
    concept outputtable = requires(std::ostream &os, T &&object) {
        { os << object } -> convertible_to<std::ostream &>;
    };
}

/// Primary template for is_serializable. Specialize this class to add serialization for a type.
/// \note if T is a class it may be preferable to satisfy class_serializable instead. Types that satisfy
/// class_serializable automatically specialize this class. This class exists to allow for non-class types and classes
/// that cannot be changed to be serialized.
/// \tparam T
/// \sa class_serializable
template<typename T>
struct is_serializable : std::false_type {
    static std::ostream &serialize(std::ostream &os, T &&object) = delete;
};

/// Satisfied if a specialization of is_serializable exists for T.
/// \tparam T
/// \sa is_serializable
template<typename T>
concept serializable = is_serializable<T>::value && requires(std::ostream &os, T &&object) {
    { is_serializable<T>::serialize(os, std::forward<T>(object)) } -> detail::convertible_to<std::ostream &>;
};

/// Satisfied if T contains a member function named serialize that takes an std::ostream as input and returns an
/// std::ostream. It is recommended that the input stream is the same as the stream returned.
/// \tparam T
template<typename T>
concept class_serializable = requires(std::ostream &os, T &&object) {
    { std::forward<T>(object).serialize(os) } -> detail::convertible_to<std::ostream &>;
};

/// A specialization of is_serializable that allows for types that have a stream insertion operator defined to be
/// serialized.
template<detail::outputtable T>
struct is_serializable<T> : std::true_type {
    static std::ostream &serialize(std::ostream &os, T &&object) {
        os << std::forward<T>(object);
        return os;
    }
};

/// A specialization of is_serializable that allows for types that satisfy class_serializable to be serialized.
/// \tparam T a type that satisfies class_serializable
/// \sa class_serializable
template<class_serializable T>
struct is_serializable<T> : std::true_type {
    static std::ostream &serialize(std::ostream &os, T &&object) {
        return std::forward<T>(object).serialize(os);
    }
};

#endif //SIMPLE_GAME_SERIALIZER_CONCEPTS_H
