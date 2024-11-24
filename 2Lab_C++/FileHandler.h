#pragma once
#include <iostream>


// class FileHandler: Обрабатывает чтение и запись файлов формата #Life 1.06.
class FileHandler {
public:
    // Method for reading the universe from the given file.
    // By reading the universe we mean:
    // initialization universe_.rows
    // initialization universe_.columns
    // initialize universe_.field
    // initialization universe_.birth_rules_
    // initialization universe_.survival_rules_
    void ReadingTheUniverseFromFile(class Simulation& simulation, const std::string& filename);

    // Method for writing the universe to a given file
    void WritingTheUniverseFromFile(Simulation& simulation, const std::string& filename);
};

// File format: Life 1.06 (http://conwaylife.com/wiki/Life_1.06)
// * edits have been made to comply with the technical specifications
/*
1) #Life 1.06
2) #N My universe
3) #Size 30 30
4) #R Bx/Sy
5) 0 2
6) 1 0
7) 1 2
8) 2 1
9) 2 2

1 line: Header indicating the file format.
Line 2: contains a comment with the name of the universe (arbitrary line).
Line 3: contains a field dimensions (amount of columns, amount of rows).
Line 4: contains a comment with the following transition rule:
            #R Bx/Sy , where x and y are sequences of different digits from the set {0...8}.
            The sequence under the letter B (birth) contains the number of living cells,
            necessary for the “birth” of a cell,
            under the letter S (survival) - cells necessary for the “survival” of the cell.
5th line - EOF: coordinates of living cells.
!! Important: (x,y) - correct coordinates, if x>=0, y>=0.
incorrwct coordinates will be ignored !!
*/


