#pragma once
#include <vector>
#include <string>


// Variable to describe the state of the cell
enum class CellState {
    Dead,
    Alive
};

// Class Universe: Stores the state of the universe, including the transition rule, field size, and cell states.
class Universe {
public:
    Universe(std::string name, int numb_rows, int numb_columns,
             std::vector<int> birth_rules,
             std::vector<int> survival_rules)
        : name_(name),
          rows_(numb_rows),
          columns_(numb_columns),
          birth_rules_(birth_rules),
          survival_rules_(survival_rules),
          field_(rows_, std::vector<CellState>(columns_, CellState::Dead)) {
    }

    //Method to set the status of a cell at coordinates (x, y) in the field attribute of the Universe class
    void SetCellValue(int x, int y, CellState status);

    //Methods to set name, birth_rules_, survival_rules_, columns_, rows_, field_ (size).
    void SetName(std::string name);
    void SetBirthRule(std::vector<int> rule);
    void SetSurvivalRule(std::vector<int> rule);
    void SetRows(int rows);
    void SetColumns(int columns);
    void SetField(int x, int y);

    //Method to get the status of a cell at coordinates (x, y) in the field attribute of the Universe class
    CellState GetCellStatus(int x, int y);

    //Methods to get name, birth_rules_, survival_rules_, columns_, rows_, field_.
    int GetRows();
    int GetColumns();
    std::vector<int> GetSurvivalRules();
    std::vector<int> GetBirthRules();
    std::string GetName();
    std::vector<std::vector<CellState>> GetField();

    // Method to display the current state of the this universe.
    void Draw();

private:
    std::string name_;
    int rows_; // ammount rows in field_
    int columns_; // ammount columns in field_
    std::vector<std::vector<CellState>> field_; // stores the state of the universe
    std::vector<int> birth_rules_;
    std::vector<int> survival_rules_;
};
