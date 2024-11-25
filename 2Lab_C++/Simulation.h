#pragma once
#include "Universe.h"


// class Simulation: The Simulation class provides an interface for managing and controlling the Game of Life simulation.
// It allows you to initialize the grid, update the state of the cells and display the current state of the grid
class Simulation {
public:
    Simulation(std::string name = "random", int numb_rows = 50, int numb_columns = 70,
               std::vector<int> birth_rules = {3},
               std::vector<int> survival_rules = {2, 3})
        : universe_(name, numb_rows, numb_columns, birth_rules, survival_rules),
          temp_universe_(name, numb_rows, numb_columns, birth_rules, survival_rules),
          run (true){};

    bool IsRunning(){return run;};
    void Run(){run = true;};
    void Pause(){run = false;};

    //Method to set the status of a cell at coordinates (x, y) in the universe_.field attribute of the Simulation class.
    // universe_.field[x][y] = status.
    void SetCellValue(int x, int y, CellState status);

    //Method to toggle the status of a cell at coordinates (x,y) in the universe_.field attribute of the simulation class.
    void ToggleCell(int x, int y);

    //Method to get the status of a cell at coordinates (x, y) in the universe_.field attribute of the Simulation class.
    CellState GetCellStatus(int x, int y);

    // The method implements counting cells with the 'Live' status around the cell universe_.field[x][y].
    int CountLiveNeighbours(int x, int y);

    // The method updates the state of universe_.field taking into account universe_.birth_rules_ and universe_.survival_rules_ .
    void Update();

    // Methods for updating the state of universe.field[x][y] according to universe_.birth_rules_ and universe_.survival_rules_ .
    void UpdateDead(int x, int y, int live_neighbours);
    void UpdateAlive(int x, int y, int live_neighbours);

    // Method to display the current state of the universe_ .
    void Draw();

    // Method for arbitrary initialization of universe_.field.
    // This method will be called for a class instance if a file with a description of the universe has not been received.
    void RandomGenerationField();

    //Methods to set universe_.name,  universe_.birth_rules_, universe_.survival_rules_, universe_.columns_, universe_.rows_, universe_.field_ (size).
    void SetUniverseName(std::string name);
    void SetUniverseBirthRule(std::vector<int> rule);
    void SetUniverseSurvivalRule(std::vector<int> rule);
    void SetUniverseColumns(int columns);
    void SetUniverseRows(int rows);
    void SetUniverseField(int x, int y);
    //Clear field
    void Clear();

    //Methods to get universe_.name,  universe_.birth_rules_, universe_.survival_rules_, universe_.columns_, universe_.rows_, universe_.field_ (size).
    std::string GetUniverseName();
    int GetUniverseRows();
    int GetUniverseColumns();
    std::vector<int> GetUniverseBirthRules();
    std::vector<int> GetUniverseSurvivalRules();
    std::vector<std::vector<CellState>> GetUniverseField();


    friend class FileHandler;

private:
    Universe universe_;
    Universe temp_universe_;
    bool run;
};


