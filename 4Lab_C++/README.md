# Улучшенный проект парсера CSV

# 

## Обзор

Этот проект предоставляет анализатор CSV, реализованный на C++. Анализатор читает файлы CSV и преобразует данные в кортеж указанных типов.

## Функции

- Поддерживает различные типы данных, включая целые числа, строки и числа с плавающей запятой.
- Обрабатывает различные разделители и escape-символы.

### Предварительные условия

- Компилятор C++ (например, GCC, Clang)
- CMake

### Установка

1. Клонируйте репозиторий:
    ```sh
    git clone https://github.com/your-repo/csv-parser.git
    cd csv-parser
    ```

2. Создайте проект:
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

### Документация

Документация для этого проекта создана с помощью Doxygen. Чтобы просмотреть документацию:

1. Откройте файл index.html, расположенный в каталоге docs вашего веб-браузера.

## Использование

### Пример

Вот пример использования синтаксического анализатора CSV:

```cpp
#include <iostream>
#include <fstream>
#include <строка>
#include "CSVParser.h"

интервал основной() {
    std::ifstream file("example.csv");
    CSVParser<std::string, int, double> parser(file);

    for (const auto& row: parser) {
        std::cout << row << std::endl;
    }

    вернуть 0;
}

```
### Пример структуры проекта

```
4Lab_C++/
├── CMakeLists.txt
├── CSVParser.h
├── CSVParser.cpp
├── html/
│   ├── index.html
│   ├── ...
├── README.md
├── example/
│   ├── 1.csv
│   ├── ...
│   ├── 4.csv
└── main.cpp