#include <getopt.h>
#include <string>
#include <iostream>
#include "ArgumentParser.h"


const std::string kRED = "\033[1;31m";
const std::string kRESET = "\033[0m";
const std::string kGREEN = "\033[32m";

void ArgumentParser::Parse() {
    int opt;
    int opt_idx;
    while ((opt = getopt_long(argc_, argv_, short_option_, long_options_, &opt_idx))!= -1) {
        switch (opt) {
            case 'i':
                iterations_ = std::stoi(optarg);
                break;
            case 'l':
                input_file_ = optarg;
                break;
            case 'o' :
                output_file_ = optarg;
                break;
            case 'h' :
                printHelp();
                exit(0);
            default:
                throw std::invalid_argument ("Usage:  ./GameOfLife [-p z] [--input=z] [-i x] [--iterations=x] [-o y] [--output=y]");
        }
    }
}

std::string ArgumentParser::GetInputFile() {
    if (input_file_ == nullptr) {
        std::cerr << kRED << "Error: input file was not specified." << kRESET << std::endl;
        return "";
    }
    return std::string(input_file_);
}

std::string ArgumentParser::GetOutputFile() {
    if (output_file_ == nullptr) {
        std::cerr << kRED << "Error: output file was not specified." << kRESET << std::endl;
        return "";
    }
    return std::string(output_file_);
}

int ArgumentParser::GetIterations() {
    return iterations_;
}


void printHelp() {
    std::cout << "Game of Life\n\n";
    std::cout << "Description:\n";
    std::cout << "The Game of Life is a cellular automaton devised by the British mathematician John Conway in 1970. The game takes place on an infinite two-dimensional grid of cells, each of which can be in one of two states: alive or dead. The state of the cells changes according to simple rules based on the state of neighboring cells.\n\n";
    std::cout << "Rules for the standard universe:\n";
    std::cout << "1. If a live cell has fewer than two or more than three live neighbors, it dies (underpopulation or overpopulation).\n";
    std::cout << "2. If a live cell has two or three live neighbors, it stays alive.\n";
    std::cout << "3. If a dead cell has exactly three live neighbors, it becomes alive (birth).\n\n";
    std::cout << "This implementation of the game supports loading a \"universe\" from a file in the following format:\n";
    std::cout << "```\n";
    std::cout << "#Life 1.06\n";
    std::cout << "#N My universe\n";
    std::cout << "#Size 45 20\n";
    std::cout << "#R B3/S23\n";
    std::cout << "0 2\n";
    std::cout << "1 0\n";
    std::cout << "1 2\n";
    std::cout << "2 1\n";
    std::cout << "2 2\n";
    std::cout << "```\n";
    std::cout << "For more details about the format, see the README.md file of the project.\n\n";
    std::cout << "Game launch options:\n";
    std::cout << "--help         Displays this help message.\n";
    std::cout << "-h             Displays this help message.\n";
    std::cout << "--load <file>  Loads the initial configuration of the universe from a file.\n";
    std::cout << "-l <file>      Загружает начальную конфигурацию вселенной из файла.\n";
    std::cout << "-i <x>         Specifies the number of iterations for offline mode.\n";
    std::cout << "--iterations=<x> Specifies the number of iterations for offline mode.\n";
    std::cout << "-o <filename>  Specifies the output file for offline mode.\n";
    std::cout << "--output=<filename> Specifies the output file for offline mode.\n\n";
    std::cout << "Online mode provides a graphical visualization of the universe's state, displaying the current iteration number in the top-left corner during rendering. In online mode, the game will terminate when the Game of Life window is closed, and the state of the \"universe\" will be saved to the file output.txt.\n\n";
    std::cout << "Offline mode is used to calculate the state of the universe after a specified number of iterations.\n\n";
    std::cout << "The game will inform the user about errors and provide instructions on how to fix them.\n\n";
    std::cout << "Examples of game launches and explanations:\n";
    std::cout << "\"./GameOfLife -p input.txt -i 10 -o output.txt\" - launches offline mode, which writes the state of the universe from the file \"input.txt\" to the file \"output.txt\" after 10 iterations of simulation.\n";
    std::cout << "\"./GameOfLife --input=input.txt --iterations=10 --output=output.txt\" - does the same thing.\n";
}