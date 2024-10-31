#ifndef CREATURES_H
#define CREATURES_H

/*generic creature - общий родитель
ocean creature - наследник умеющий плавать
amphibious - наследник умеющий плавать и ходить
terrestrial creature - не умеет плавать, но умеет ходить
bird - умеет ходить и летать
waterfowl - водоплавающая птица. Умеет ходить, летать и плавать.*/


class canSwim {
public:
    virtual void swim () = 0;

};


class canFly{
public:
    virtual void fly () = 0;
};

class canWalk {
public:
    virtual void walk () = 0;
};


class generic {
public:
    generic() {
        std:: cout << "Generic Constructor called" << std:: endl;
    }
    ~generic() {
        std:: cout << "Generic Deconstructor called" << std:: endl;
    }
};

class ocean : public generic, canSwim{
public:
    ocean() {
        std:: cout << "Ocean creatures Constructor called" << std:: endl;
    }
    ~ocean() {
        std:: cout << "Ocean creatures Deconstructor called" << std:: endl;
    }

    void swim () override{
        std:: cout << "I am Ocean creatures and I can swim" << std:: endl;
    }
};

class amphibious : public generic, public canSwim, public canWalk{
public:
    amphibious() {
        std:: cout << "Amphibious creatures Constructor called" << std:: endl;
    }
    ~amphibious() {
        std:: cout << "Amphibious creatures Deconstructor called" << std:: endl;
    }
    void walk() {
        std:: cout << "I am amphibious creatures and I can walk" << std:: endl;
    }
    void swim () override{
        std:: cout << "I am amphibious creatures and I can swim" << std:: endl;
    }

};

class terrestrial : public generic, public canWalk{
public:
    terrestrial() {
        std:: cout << "Terrestrial creatures Constructor called" << std:: endl;
    }
    ~terrestrial() {
        std:: cout << "Terrestrial creatures Deconstructor called" << std:: endl;
    }
    void walk() override{
        std:: cout << "I am terrestrial creatures and I can walk" << std:: endl;
    }
};

class bird : public generic, public canFly{
public:
    bird() {
        std:: cout << "Bird creatures Constructor called" << std:: endl;
    }
    ~bird() {
        std:: cout << "Bird creatures Deconstructor called" << std:: endl;
    }
    void fly () override {
        std:: cout << "I am Ocean creatures and I can swim" << std:: endl;
    }
};

#endif //CREATURES_H
