#ifndef PRINT_TUPLE_H
#define PRINT_TUPLE_H

#include <iostream>
#include <tuple>
#include <type_traits>

/**
 * @brief Структура для представления позиции в кортеже.
 * @tparam Pos Позиция в кортеже.
 */
template<std::size_t Pos>
struct pos_ {
};

/**
 * @brief Функция для печати последнего элемента кортежа.
 * @tparam Ch Тип символов потока вывода.
 * @tparam Tr Тип черт потока вывода.
 * @tparam Tuple Тип кортежа.
 * @param out Поток вывода.
 * @param t Кортеж.
 * @return Ссылка на поток вывода.
 */
template<typename Ch, typename Tr, class Tuple>
std::basic_ostream<Ch, Tr> &print_tuple(std::basic_ostream<Ch, Tr> &out, const Tuple &t, pos_<1>) {
    return out << std::get<std::tuple_size<Tuple>::value - 1>(t);
}

/**
 * @brief Рекурсивная функция для печати элементов кортежа.
 * @tparam Ch Тип символов потока вывода.
 * @tparam Tr Тип черт потока вывода.
 * @tparam Tuple Тип кортежа.
 * @tparam Pos Позиция в кортеже.
 * @param out Поток вывода.
 * @param t Кортеж.
 * @return Ссылка на поток вывода.
 */
template<typename Ch, typename Tr, class Tuple, std::size_t Pos>
std::basic_ostream<Ch, Tr> &print_tuple(std::basic_ostream<Ch, Tr> &out, const Tuple &t, pos_<Pos>) {
    out << std::get<std::tuple_size<Tuple>::value - Pos>(t) << ", ";
    return print_tuple(out, t, pos_<Pos - 1>());
}

/**
 * @brief Оператор вывода для кортежа.
 * @tparam Ch Тип символов потока вывода.
 * @tparam Tr Тип черт потока вывода.
 * @tparam Args Типы элементов кортежа.
 * @param out Поток вывода.
 * @param t Кортеж.
 * @return Ссылка на поток вывода.
 */
template<typename Ch, typename Tr, class... Args>
std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &out, const std::tuple<Args...> &t) {
    print_tuple(out, t, pos_<sizeof...(Args)>());
    return out;
}

#endif //PRINT_TUPLE_H
