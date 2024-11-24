#include "Universe.h"
#include "raylib.h"
#include <iostream>

const std::string kRED = "\033[1;31m";
const std::string kRESET = "\033[0m";
const std::string kGREEN = "\033[32m";


int Universe::GetRows() {
    return rows_;
}

int Universe::GetColumns() {
    return columns_;
}

std::vector<int> Universe::GetBirthRules() {
    return birth_rules_;
}

std::vector<int> Universe::GetSurvivalRules() {
    return survival_rules_;
}

std::string Universe:: GetName() {
    return name_;
}

void  Universe::SetName(std::string name) {
    name_ = name;
}

void Universe:: SetBirthRule(std::vector<int> rule) {
    birth_rules_ = rule;
}
void Universe:: SetSurvivalRule(std::vector<int> rule) {
    survival_rules_ = rule;
}

void Universe::SetColumns(int columns) {
    if (columns <= 70) {
        columns_ = columns;
    }
    else {
        std::cerr << kRED << "Error: The number of columns should not exceed 70." << kRESET << std::endl;
    }
}

void Universe::SetRows(int rows) {
    if (rows <= 50) {
        rows_ = rows;
    }
    else {
        std::cerr << kRED << "Error: The number of rows should not exceed 50." << kRESET << std::endl;
    }
}

std::vector<std::vector<CellState>> Universe:: GetField() {
    return field_;
}

void Universe::SetField(int x, int y) {
    std::vector<std::vector<CellState>> temp_field(rows_, std::vector<CellState>(columns_, CellState::Dead));
    field_ = temp_field;
}




// The method will set the status of the cell with coordinates (x,y), if the coordinates are correct
// otherwise it will report an error
void Universe::SetCellValue(int x, int y, CellState status) {
    if (x >= 0 && x < rows_ && y >= 0 && y < columns_) {
        field_[x][y] = status;
    } else {
        std::cerr << kRED << "Error: Coordinates (" << x << ", " << y << ") are out of bounds." << kRESET << std::endl;
    }
}


// The method will get the status of the cell with coordinates (x,y), if the coordinates are correct
// otherwise it will report an error
CellState Universe::GetCellStatus(int x, int y) {
    if (x >= 0 && x < rows_ && y >= 0 && y < columns_) {
        return field_[x][y];
    }
    else {
        std::cerr << kRED << "Error: Coordinates (" << x << ", " << y << ") are out of bounds." << kRESET << std::endl;
        return CellState::Dead;
    }
}



void Universe::Draw() {
    for (int row = 0; row <rows_; row++) {
        for (int column = 0; column < columns_; column++) {
            Color color = field_[row][column] == CellState::Alive ? Color{0,255,0,255} : Color {55,55,55,255};
            DrawRectangle(column * 25, row * 25, 24, 24, color);
        }
        std::cout << std::endl;
    }
}

