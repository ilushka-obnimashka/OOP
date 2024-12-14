#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <tuple>
#include <iterator>
#include <limits>
#include <utility>

#ifndef CSVPARSER_H
#define CSVPARSER_H

const std::string kRED = "\033[1;31m";
const std::string kRESET = "\033[0m";
const std::string kYELLOW = "\033[1;33m";

template<typename... Types>
class CSVParser {
public:
    /**
     * Конструктор класса CSVParser.
     * @param file Ссылка на объект std::ifstream для чтения CSV файла.
     * @param count_skip_lines Количество строк, которые нужно пропустить в начале файла.
     * @param row_separator Символ разделителя строк (по умолчанию '\n').
     * @param column_separator Символ разделителя колонок (по умолчанию ',').
     * @param escape_character Символ экранирования (по умолчанию '"').
     */
    CSVParser(std::ifstream &file, const std::size_t count_skip_lines = 0, const char row_separator = '\n',
              const char column_separator = ',', const char escape_character = '\"') : file_(file),
        row_separator_(row_separator),
        column_separator_(column_separator),
        escape_character_(escape_character) {
        if (!file_.is_open()) {
            std::cerr << kRED << "Could not open file!" << kRESET << std::endl;
            exit(1);
        }

        CheckCharacters();

        numb_column_ = 0;
        numb_row_ = count_skip_lines;
        SkipLinesFile(count_skip_lines);
    }

    /**
     * Деструктор класса CSVParser.
     * Закрывает файл, если он открыт.
     */
    ~CSVParser() {
        if (file_.is_open()) {
            file_.close();
        }
    }



    /**
     * Класс итератора для CSVParser.
     */
    class CSVParserIter {
    public:
        typedef std::input_iterator_tag iterator_category;
        typedef std::tuple<Types...> value_type;
        typedef ptrdiff_t difference_type;
        typedef value_type &reference;
        typedef value_type *pointer;

        /**
         * Конструктор итератора.
         * @param parser Ссылка на объект CSVParser.
         * @param is_end Флаг, указывающий, является ли итератор концом.
         */
        CSVParserIter(CSVParser &parser, bool is_end = false) : parser_(parser), is_end_(is_end) {
            if (!is_end_) {
                ReadNextRow();
            }
        }

        /**
         * Оператор инкремента (переход к следующей строке).
         * @return Ссылка на текущий объект итератора.
         */
        CSVParserIter &operator++() {
            if (!is_end_) {
                ReadNextRow();
            }
            return *this;
        }

        /**
         * Оператор разыменования (возвращает текущие значения).
         * @return Текущие значения в виде кортежа.
         */
        value_type operator*() const {
            return current_values_;
        }

        /**
         * Оператор сравнения (проверяет, равны ли два итератора).
         * @param other Другой итератор для сравнения.
         * @return true, если итераторы равны, иначе false.
         */
        bool operator==(const CSVParserIter &other) const {
            return is_end_ == other.is_end_;
        }

        /**
         * Оператор неравенства (проверяет, не равны ли два итератора).
         * @param other Другой итератор для сравнения.
         * @return true, если итераторы не равны, иначе false.
         */
        bool operator!=(const CSVParserIter &other) const {
            return !(*this == other);
        }

    private:
        CSVParser &parser_;
        value_type current_values_;
        bool is_end_;

        /**
         * Читает следующую строку из файла и преобразует её в кортеж значений.
         */
        void ReadNextRow() {
            if (parser_.ReadNextRow()) {
                current_values_ = parser_.GetCurrentValues();
            } else {
                current_values_ = value_type();
                is_end_ = true;
            }
        }
    };

    /**
     * Возвращает итератор, указывающий на начало последовательности.
     * @return Итератор, указывающий на начало последовательности.
     */
    CSVParserIter begin() {
        return CSVParserIter(*this);
    }

    /**
     * Возвращает итератор, указывающий на конец последовательности.
     * @return Итератор, указывающий на конец последовательности.
     */
    CSVParserIter end() {
        return CSVParserIter(*this, true);
    }

private:
    std::ifstream &file_;
    char row_separator_;
    char column_separator_;
    char escape_character_;
    std::string current_line_;
    std::vector<std::string> current_values_;
    bool isEOF_ = false;
    bool inside_escape_character_ = false;
    int numb_column_;
    int numb_row_;

    /**
     * Увеличивает значение номера колонки.
     */
    void IncColumn() {
        numb_column_++;
    }

    /**
     * Увеличивает значение номера строки.
     */
    void IncRow() {
        numb_row_++;
    }

    /**
     * Устанавливает номер колонки в 0.
     */
    void ToZeroColumn() {
        numb_column_ = 0;
    }

    /**
     * Пропускает указанное количество строк в начале файла.
     * @param count_skip_lines Количество строк для пропуска.
     */
    void SkipLinesFile(const std::size_t count_skip_lines) {
        for (size_t i = 0; i < count_skip_lines; i++) {
            file_.ignore(std::numeric_limits<std::streamsize>::max(), row_separator_);
        }
    }

    /**
     * Читает следующую строку из файла и разбивает её на отдельные значения.
     * @return true, если строка успешно прочитана, иначе false.
     */
    bool ReadNextRow() {
        if (!std::getline(file_, current_line_)) {
            isEOF_ = true;
            return false;
        }

        std::stringstream ss(current_line_);
        std::string temp_value;
        current_values_.clear();

        while (std::getline(ss, temp_value, column_separator_)) {
            for (size_t i = 0; i < temp_value.size(); ++i) {
                if (temp_value[i] == escape_character_) {
                    inside_escape_character_ = !inside_escape_character_;
                    temp_value.erase(i, 1);
                    --i;
                }
            }

            if (inside_escape_character_) {
                current_values_.back() += column_separator_ + temp_value;
            } else {
                current_values_.push_back(temp_value);
            }
        }
        ToZeroColumn();
        IncRow();
        return true;
    }

    /**
     * Преобразует текущие значения в кортеж.
     * @return Кортеж текущих значений.
     */
    std::tuple<Types...> GetCurrentValues() {
        std::tuple<Types...> result;
        convertValues(result, std::make_index_sequence<sizeof...(Types)>());
        return result;
    }

    /**
     * Преобразует значения из вектора в кортеж.
     * @param result Кортеж для заполнения.
     * @param Is Индексы для доступа к элементам кортежа.
     */
    template<std::size_t... Is>
    void convertValues(std::tuple<Types...> &result, std::index_sequence<Is...>) {
        ((std::get<Is>(result) = convert<std::decay_t<Types>>(current_values_[Is])), ...);
    }

    /**
     * Преобразует строку в указанный тип.
     * @param value Строка для преобразования.
     * @return Преобразованное значение.
     */
    template<typename T>
    T convert(const std::string &value) {
        IncColumn();
        try {
            if constexpr (std::is_same_v<T, std::string>) {
                return value;
            } else if constexpr (std::is_arithmetic_v<T>) {
                std::stringstream ss(value);
                T result;
                ss >> result;
                if (ss.fail() || !ss.eof()) {
                    throw std::runtime_error("Conversion failed");
                }
                return result;
            } else {
                throw std::runtime_error("Unsupported type");
            }
        } catch (const std::exception &ex) {
            std::cerr << kRED << "Error converting value at row " << numb_row_ << ", column " << numb_column_ << ": " <<
                    ex.what() << std::endl << kRESET;
        }
    }
    /**
    * Проверяет, что специальные символы не совпадают.
    * Если совпадают, устанавливает стандартные значения.
    */
    void CheckCharacters() {
        if (column_separator_ == row_separator_ || column_separator_ == escape_character_ || row_separator_ ==
            escape_character_) {
            std::cerr << kRED << "special characters match" << kRESET << std::endl;
            std::cerr << kYELLOW << "standard characters will be used" << kRESET << std::endl;

            column_separator_ = ',';
            row_separator_ = '\n';
            escape_character_ = '"';

            std::cerr << kYELLOW << "column separator: " << column_separator_ << ", " << "row separator: " <<
                    row_separator_ << ", " << "escape character: " << escape_character_ << kRESET << std::endl;
            }
    }
};

#endif
