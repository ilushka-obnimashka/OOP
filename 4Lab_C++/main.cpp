#include <iostream>
#include <string>
#include "print_tuple.h"
#include "CSVParser.h"

int main() {
    /*std::ifstream file("1.csv");
    CSVParser<std::string, std::string, std::string> parser(file);
    */

    /*std::ifstream file("2.csv");
    CSVParser<std::string, std::string, std::string> parser(file);
    */

    /*std::ifstream file("3.csv");
    CSVParser<int, int, std::string> parser(file, 0, '\n', ' ');
    */

    std::ifstream file("4.csv");
    CSVParser<long long, std::string, std::string, std::string, std::string, std::string, std::string, std::string,
        std::string, std::string, double, double, double, double, double, double, double> parser(file);

    for (const auto &rs : parser) {
        std::cout << rs << std::endl;
    }

    return 0;
}
