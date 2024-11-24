#include "raylib.h"
#include "Simulation.h"
#include "FileHandler.h"
#include "ArgumentParser.h"
#include "Game.h"

const std::string kRED = "\033[1;31m";
const std::string kRESET = "\033[0m";


const int kCELL_WIDTH_HEIGHT = 25;
const int kFPS = 12;
const Color kGREY = {29, 29, 29, 255};


int main(int argc, char *argv[]) {
    Simulation simulation = Simulation();
    FileHandler file_handler = FileHandler();
    ArgumentParser arg_parser = ArgumentParser(argc, argv);
    Game game = Game(simulation, file_handler, arg_parser);

    game.Start(argc);

}
