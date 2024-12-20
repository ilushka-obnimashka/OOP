#include "raylib.h"
#include "Game.h"

const std::string kRED = "\033[1;31m";
const std::string kRESET = "\033[0m";
const std::string kYELLOW = "\033[33m";

const int kCELL_WIDTH_HEIGHT = 10;
int FPS = 10;
const Color kGREY = {29, 29, 29, 255};

void Game::Start(int argc) {
    if (argc == 1) {
        simulation_.RandomGenerationField();
        OnlineMode();
    }
    else {
        try {
            argument_parser_.Parse();
        } catch (std::exception &ex) {
            std::cerr << kRED << "Error: " << ex.what() << kRESET << std::endl;
            ParseError();
        }
        if (!argument_parser_.GetInputFile().empty()) {
            try {
                file_handler_.ReadingTheUniverseFromFile(simulation_,argument_parser_.GetInputFile());
                if (argument_parser_.GetIterations()) {
                    OfflineMode();
                }
                else {
                    OnlineMode();
                }
            }
            catch (std::exception &ex) {
                std::cerr << kRED << "Error: " << ex.what() << std::endl;
                std::cerr << kYELLOW <<"The game will launch on a standard universe, with random initial generation.\n" << kRESET;
                simulation_ = Simulation();
                simulation_.RandomGenerationField();
                OnlineMode();
            }
        }
    }
}


void Game::OnlineMode() {
    InitWindow(simulation_.GetUniverseColumns() * kCELL_WIDTH_HEIGHT, simulation_.GetUniverseRows() * kCELL_WIDTH_HEIGHT,
               "Game of Life");
    SetTargetFPS(FPS);

    int iteration = 0;
    while (WindowShouldClose() == false) {

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse_possition = GetMousePosition();
            int row_cell = mouse_possition.y / kCELL_WIDTH_HEIGHT;
            int column_cell = mouse_possition.x / kCELL_WIDTH_HEIGHT;
            simulation_.ToggleCell(row_cell, column_cell);
        }

        if (IsKeyPressed(KEY_C)) {
            simulation_.Clear();
            iteration = 0;
            simulation_.Pause();
            SetWindowTitle("Game of life has stopped");
        }

        if (IsKeyPressed(KEY_ENTER)) {
            simulation_.Run();
            SetWindowTitle("Game of life");
        }

        if (IsKeyPressed(KEY_SPACE)) {
            simulation_.Pause();
            SetWindowTitle("Game of life has stopped");
        }

        if (IsKeyPressed(KEY_D)) {
            FPS+=2;
            SetTargetFPS(FPS);
        }

        if (IsKeyPressed(KEY_A)) {
            FPS-=2;
            SetTargetFPS(FPS);
        }
        simulation_.Update();
        BeginDrawing();
        ClearBackground(kGREY);
        std::string numberStr = std::to_string(iteration);
        simulation_.Draw();
        if (simulation_.IsRunning()) {
            DrawText(numberStr.c_str(), 10, 10, 30, WHITE);
            iteration++;
        }
        EndDrawing();
    }
    CloseWindow();
    file_handler_.WritingTheUniverseFromFile(simulation_, "output.txt");
}

void Game::ParseError() {
    std::cerr <<  kRED << kYELLOW << "Parameters:\n";
    std::cerr << "-l, --load=z Loads the initial configuration from a file.\n";
    std::cerr << "-i, --iterations=x Specify the number of iterations for offline mode.\n";
    std::cerr << "-o, --output=y Specify the path to the output file to save the final state of the grid in offline mode.\n";
    std ::cerr << kRED << "Important! For full instructions, see the project README.md.\n\n";
    std ::cerr << kYELLOW << "Examples:\n";
    std ::cerr << "./GameOfLife -p input.txt -i 10 -o output.txt\n";
    std ::cerr << "./GameOfLife --input=input.txt --iterations=10 --output=output.txt\n\n";
    std ::cerr << "Restart the Game with correct options\n" << kRESET;
}

void Game::OfflineMode() {
    int iteration = argument_parser_.GetIterations();
    while (iteration >= 0) {
        simulation_.Update();
        iteration--;
    }
    if (argument_parser_.GetOutputFile().empty()) {
        std::cerr << kRED << "Error: you didn't specify output file.\n";
        std::cerr << kYELLOW << "The game state will be written to output.txt.\n";
        file_handler_.WritingTheUniverseFromFile(simulation_, "output.txt");
    }
    else {
        file_handler_.WritingTheUniverseFromFile(simulation_, argument_parser_.GetOutputFile());
    }
}
