#include "Simulation.h"
#include <random>

// The method will set the status of the cell with coordinates (x,y), if the coordinates are correct
// otherwise it will report an error.
void Simulation::SetCellValue(int x, int y, CellState status) {
    universe_.SetCellValue(x, y, status);
}


// The method will get the status of the cell with coordinates (x,y), if the coordinates are correct
// otherwise it will report an error.
CellState Simulation::GetCellStatus(int x, int y) {
    return universe_.GetCellStatus(x, y);
}

void Simulation::SetUniverseName(std::string name) {
    universe_.SetName(name);
}

void Simulation::SetUniverseBirthRule(std::vector<int> rule) {
    universe_.SetBirthRule(rule);
}

void Simulation::SetUniverseSurvivalRule(std::vector<int> rule) {
    universe_.SetSurvivalRule(rule);
}

void Simulation::SetUniverseColumns(int columns) {
    universe_.SetColumns(columns);
}
void Simulation::SetUniverseRows(int rows) {
    universe_.SetRows(rows);
}

std::string Simulation::GetUniverseName() {
    return universe_.GetName();
}

int Simulation::GetUniverseColumns() {
    return  universe_.GetColumns();
}

int Simulation::GetUniverseRows() {
    return  universe_.GetRows();
}

std::vector<int> Simulation::GetUniverseBirthRules() {
    return universe_.GetBirthRules();
}

std::vector<int> Simulation::GetUniverseSurvivalRules() {
    return universe_.GetSurvivalRules();
}

std::vector<std::vector<CellState>> Simulation::GetUniverseField() {
    return universe_.GetField();
}

void Simulation::SetUniverseField(int x, int y) {
    universe_.SetField(x,y);
}


// The method counts cells with the 'Live' status around
// For example, for cell[3][4] the neighbors are the following cells:
//Directly Above: cell[2][4] {-1,0}
//Directly Below: cell[4][4] {1,0}
//Left: cell[3][3] {0, -1}
//Right: cell[3][5] {0, 1}
//Diagonal Upper Left: cell[2][3] {-1, -1}
//Diagonal Upper Right: cell[2][5] {-1, 1}
//Diagonal Lower Left: cell[4][3] {0, -1}
//Diagonal Lower Right: cell[4][5] {1, 1}
// Important! universe_.field - closed field (toroidal).
//Thus, the neighbors on top of the first row of the field are the cells of the last row and vice versa,
//similarly for the left and right edges of the universe.

int Simulation::CountLiveNeighbours(int x, int y) {
    int live_neighbours = 0;

    std::vector<std::pair<int, int> > neighbours_offset =
    {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
        {-1, -1},
        {-1, 1},
        {1, -1},
        {1, 1}
    };

    int rows = universe_.GetRows();
    int columns = universe_.GetColumns();

    for (auto offset: neighbours_offset) {
        int neighbourse_row = (x + offset.first + rows) % rows;
        int neighbourse_column = (y + offset.second + columns) % columns;

        if (universe_.GetCellStatus(neighbourse_row, neighbourse_column) == CellState::Alive) {
            live_neighbours++;
        }
    }
    return live_neighbours;
}


// This method updates the state of universe_.field in accordance with universe_.birth_rules_ and universe_.survival_rules_ .
// Double buffering method is used.
// universe_ stores the current state, temp_universe_ stores the new state.
void Simulation::Update() {
    int rows = universe_.GetRows();
    int columns = universe_.GetColumns();

    temp_universe_ = universe_;

    for (size_t row = 0; row<rows; row++) {
        for (size_t column = 0; column<columns; column++) {

            int live_neighbours = CountLiveNeighbours(row,column);

            CellState cell_status = GetCellStatus(row, column);

            if (cell_status == CellState::Dead) {
                UpdateDead(row, column, live_neighbours);
            }
            else {
                UpdateAlive(row,column, live_neighbours);
            }
        }
    }
    universe_ = temp_universe_;
}


void Simulation::UpdateDead(int x, int y, int live_neighbours) {
    auto birth_rules = universe_.GetBirthRules();
    for (auto rule : birth_rules) {
        if (live_neighbours == rule) {
            temp_universe_.SetCellValue(x,y,CellState::Alive);
            break;
        }
    }
}

void Simulation::UpdateAlive(int x, int y, int live_neighbours) {
    bool flag = false;
    auto survival_rules = universe_.GetSurvivalRules();
    for (auto rule : survival_rules ) {
        if (live_neighbours == rule) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        temp_universe_.SetCellValue(x,y,CellState::Dead);
    }
}


void Simulation::Draw() {
    universe_.Draw();
}

void Simulation::RandomGenerationField() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(1, 100);

    int rows = universe_.GetRows();
    int columns = universe_.GetColumns();

    for (size_t row = 0; row<rows; row++) {
        for (size_t column = 0; column<columns; column++) {
            int random_value = dis(gen);
            if (random_value %2 == 0) {
                universe_.SetCellValue(row, column, CellState::Alive);
            }
        }
    }
}


