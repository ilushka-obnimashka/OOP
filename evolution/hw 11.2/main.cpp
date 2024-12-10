#include <vector>
#include <iostream>
#include "creator.h"
#include "creatures.h"
#include "creature squad.h"
#include "food.h"

std::vector<Creator *> makeVectorCreator() {

}


int main() {

    human h;
    arms a;
    legs l;
    worms w;
    fishes f;
    planktons p;
    zebras z;
    antelopes an;
    bananas b;
    frogs fr;
    insects i;
    mice m;

    std::vector<food*> foodItems = {
        &w, &f, &p, &z, &an, &b, &a, &l, &fr, &i, &m, &m, &f, &f, &f
    };

    CreatorFish fishCreator;
    CreatorDolphin dolphinCreator;
    CreatorWhale whaleCreator;
    CreatorLion lionCreator;
    CreatorTiger tigerCreator;
    CreatorMonkey monkeyCreator;
    CreatorCrocodile crocodileCreator;
    CreatorAligator aligatorCreator;
    CreatorTurtle turtleCreator;
    CreatorParrot parrotCreator;
    CreatorEagle eagleCreator;
    CreatorOwl owlCreator;
    CreatorDuck duckCreator;
    CreatorPenguin penguinCreator;
    CreatorSwan swanCreator;

    std::vector<Creator *> creators = {
        &fishCreator,
        &dolphinCreator,
        &whaleCreator,
        &lionCreator,
        &tigerCreator,
        &monkeyCreator,
        &crocodileCreator,
        &aligatorCreator,
        &turtleCreator,
        &parrotCreator,
        &eagleCreator,
        &owlCreator,
        &duckCreator,
        &penguinCreator,
        &swanCreator
    };


    for (size_t i = 0; i<16; i++) {
        for (size_t j = 0; j < 3; j++) {
            auto generic = creators[i]->create();
            generic->eat(foodItems[i]);
        }
    }

}
