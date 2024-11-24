#pragma once
#include "Simulation.h"
#include "FileHandler.h"
#include "ArgumentParser.h"

// Game class: responsible for initializing, launching and managing various game modes.
class Game {
public:

    //Constructor for the Game class.
    //simulation Simulation object responsible for simulating the game.
    //file_handler A FileHandler object responsible for handling files.
    //argument_parser An ArgumentParser object responsible for parsing command line arguments.
    Game(Simulation simulation, FileHandler file_handler, ArgumentParser argument_parser)
        :simulation_(simulation), file_handler_(file_handler), argument_parser_(argument_parser){};
    // Launches the game and selects the required mode in accordance with the launch options and fulfillment of the necessary requirements
    void Start(int argc);

    // Methods responsible for online and offline game modes.
    void OnlineMode();
    void OfflineMode();

    //Handles errors parsing command line arguments.
    //Displays error messages and prompts the user to correct them.
    void ParseError();

private:
    Simulation simulation_;
    FileHandler file_handler_;
    ArgumentParser argument_parser_;
};
