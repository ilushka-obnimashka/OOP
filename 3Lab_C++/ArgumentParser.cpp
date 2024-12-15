#include "ArgumentParser.h"
#include <getopt.h>
#include <string>
#include <iostream>
#include <stdexcept>

const std::string kRED = "\033[1;31m";
const std::string kRESET = "\033[0m";
const std::string kGREEN = "\033[32m";

bool ArgumentParser::Parse() {
    int opt;
    int opt_idx;
    while ((opt = getopt_long(argc_, argv_, short_option_, long_options_, &opt_idx)) != -1) {
        switch (opt) {
            case 'c':
                config_file_ = std::string(optarg);
                break;
            case 'h':
                printHelp();
                return false;
            default:
                throw std::invalid_argument(
                    "Usage: ./sound_processor [-h] [-c config.txt] output.wav input1.wav [input2.wav ...]");
        }
    }

    if (optind < argc_) {
        output_file_ = std::string(argv_[optind++]);
    } else {
        throw std::invalid_argument("Output file is missing");
    }

    while (optind < argc_) {
        if (input_samples_.size() >= 10) {
            throw std::invalid_argument("Too many input samples");
        }
        input_samples_.push_back(std::string(argv_[optind++]));
    }
    return true;
}

std::vector<std::string> ArgumentParser::GetInputSamples() {
    return input_samples_;
}

std::string ArgumentParser::GetOutputFile() {
    return output_file_;
}

std::string ArgumentParser::GetConfigFile() {
    return config_file_;
}
