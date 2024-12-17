#pragma once
#include "food.h"

/*generic creature - общий родитель
ocean creature - наследник умеющий плавать
amphibious - наследник умеющий плавать и ходить
terrestrial creature - не умеет плавать, но умеет ходить
bird - умеет ходить и летать
waterfowl - водоплавающая птица. Умеет ходить, летать и плавать.*/


class generic {
public:

    virtual ~generic() = default;

    virtual void eat(food *Name) = 0;
};

class ocean : virtual public generic {
public:
    void swim() {
        std::cout << "I can swim" << std::endl;
    }
};

class terrestrial : virtual public generic {
public:
    void walk() {
        std::cout << "I can walk" << std::endl;
    }
};

class amphibious : public ocean, public terrestrial {
};


class bird : virtual public terrestrial {
public:
    void fly() {
        std::cout << "I can fly" << std::endl;
    }
};

class waterfowl : public bird, public ocean {
public:
};
