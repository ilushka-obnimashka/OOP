#include "FileHandler.h"
#include "Simulation.h"
#include <fstream>
#include <regex>



// This method is necessary to initialize the universe based on the input file
// The method throws exceptions reporting errors
void FileHandler::ReadingTheUniverseFromFile(Simulation& simulation, const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        throw std::invalid_argument("Could not open the file with the description of the universe");
    }

    std::string line;

    std::regex pattern_format(R"(#Life\s+1.06)");
    std::smatch match_format;
    std::getline(file, line);

    if (std::regex_search(line, match_format, pattern_format)) {
        if (match_format.size() != 1) {
            throw std::invalid_argument("Incorrect universe description file format");
        }
    } else {
        throw std::invalid_argument("Incorrect universe description file format");
    }

    std::regex pattern_name(R"(#N\s+(.+))");
    std::smatch match_name;
    std::getline(file, line);

    if (std::regex_search(line, match_name, pattern_name)) {
        if (match_name.size() == 2) {
            std::string name = match_name[1].str();
            simulation.SetUniverseName(name);
        } else {
            throw std::invalid_argument("The file does not contain the universe name");
        }
    } else {
        throw std::invalid_argument("The file does not contain the universe name");
    }

    std::regex pattern_size(R"(#Size\s+(\d+)\s+(\d+))");
    std::smatch match_size;
    std::getline(file, line);

    if (std::regex_search(line, match_size, pattern_size)) {
        if (match_size.size() == 3) {
            std::string columns_str = match_size[1].str();
            std::string rows_str = match_size[2].str();

            int columns = std::stoi(columns_str);
            simulation.SetUniverseColumns(columns);

            int rows = std::stoi(rows_str);
            simulation.SetUniverseRows(rows);

            simulation.SetUniverseField(rows, columns);
        } else {
            throw std::invalid_argument("Incorrect size field");
        }
    } else {
        throw std::invalid_argument("Incorrect size field");
    }

    std::regex pattern_rules(R"(#R\s+B(\d+)\/S(\d+))");
    std::smatch match_rules;
    std::getline(file, line);

    if (std::regex_search(line, match_rules, pattern_rules)) {
        if (match_rules.size() == 3) {
            std::string birth_rule_str = match_rules[1].str();
            std::string survival_rule_str = match_rules[2].str();

            std::vector<int> birth_rule;
            for (auto ch : birth_rule_str) {
                birth_rule.push_back(ch - '0');
            }

            simulation.SetUniverseBirthRule(birth_rule);

            std::vector<int> survival_rule;
            for (auto ch : survival_rule_str) {
                survival_rule.push_back(ch - '0');
            }

            simulation.SetUniverseSurvivalRule(survival_rule);
        } else {
            throw std::invalid_argument("Incorrect rules");
        }
    } else {
        throw std::invalid_argument("Incorrect rules");
    }

    std::regex pattern_cell(R"((\d+)\s+(\d+))");
    std::smatch match_cell;
    while (std::getline(file, line)) {
        if (std::regex_search(line, match_cell, pattern_cell)) {
            if (match_cell.size() == 3) {
                std::string x_str = match_cell[1].str();
                std::string y_str = match_cell[2].str();

                int x = std::stoi(x_str);
                int y = std::stoi(y_str);

                simulation.SetCellValue(y, x, CellState::Alive);
            } else {
                throw std::invalid_argument("Incorrect cell coordinates");
            }
        } else {
            throw std::invalid_argument("Incorrect cell coordinates");
        }
    }

    simulation.temp_universe_ = simulation.universe_;
    file.close();
}

void FileHandler:: WritingTheUniverseFromFile(Simulation& simulation, const std::string& filename) {
    std::ofstream file (filename);

    file << "#Life 1.06" << std::endl;

    file <<"#N "<<simulation.GetUniverseName() << std::endl;

    file <<"#Size " << simulation.GetUniverseColumns()<< ' ' << simulation.GetUniverseRows() << std::endl;

    file <<"#R ";

    file <<'B';
    auto birth_rule = simulation.GetUniverseBirthRules();
    for (auto rule : birth_rule) {
        file<<rule;
    }
    file <<'/';

    file <<"S";
    auto survival_rule = simulation.GetUniverseSurvivalRules();
    for (auto rule : survival_rule) {
        file<<rule;
    }
    file << std::endl;

    auto field = simulation.GetUniverseField();

    int rows = simulation.GetUniverseRows();
    int columns = simulation.GetUniverseColumns();
    for (size_t i = 0; i<rows; i++) {
        for (size_t j = 0; j<columns; j++) {
            if (field[i][j] == CellState::Alive) {
                file<<j<<' '<<i << std::endl;
            }
        }
    }
}
