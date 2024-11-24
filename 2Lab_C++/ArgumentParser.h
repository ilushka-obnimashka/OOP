#pragma once
#include <getopt.h>


// class ArgumentParser : ArgumentParser provides a convenient interface for parsing command line arguments using the getopt_long(3) function.
class ArgumentParser {
public:
    ArgumentParser (int argc, char* argv[] )
        :argc_(argc), argv_(argv),short_option_("i:o:l:h"), input_file_(nullptr), output_file_(nullptr), iterations_(0) {
        long_options_[0] = {"iterations", 1, nullptr, 'i'};
        long_options_[1] = {"output", 1, nullptr, 'o'};
        long_options_[2] = {"load", 1, nullptr,'l'};
        long_options_[3] = {"help",0,nullptr,'h'};
        long_options_[4] = {nullptr,0,nullptr,0};
    }

    // Method for parsing **argv_ using getopt_long(3),
    // char * short_option_, struct option long_options_[4] -command line options that need to be supported.
    void Parse();

    //Methods to get input_file_, output_file_, iterations_.
    std::string GetInputFile();
    std::string GetOutputFile();
    int GetIterations();

private:
    int argc_;
    char ** argv_;
    const char * short_option_;
    struct option long_options_[6];
    const char* input_file_;
    const char* output_file_;
    int iterations_;
};


void printHelp();