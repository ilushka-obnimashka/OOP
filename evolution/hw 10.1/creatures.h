#pragma once
/*generic creature - общий родитель
ocean creature - наследник умеющий плавать
amphibious - наследник умеющий плавать и ходить
terrestrial creature - не умеет плавать, но умеет ходить
bird - умеет ходить и летать
waterfowl - водоплавающая птица. Умеет ходить, летать и плавать.*/



class generic {
public:
    generic() {
        std:: cout << "Generic Constructor called" << std:: endl;
    }
    virtual ~generic() {
        std:: cout << "Generic Deconstructor called" << std:: endl;
    }

    //virtual void eat() = 0; // закоментировано для 4 задания (не будет работать когда необходимо создать vector<generic> т.к.  данном случае generic - абстрактный класс)

    // когда иллюстрируется полиморфное поведение , то этот метод можно закоментировать и разкоментировть чисто виртуальный, тогда generic станет абстрактным классом
    virtual void eat() {
        std::cout << "\033[35m";
        std::cout << "generic eating" << std:: endl;
        std::cout << "\033[0m";
    }

};

class ocean : virtual public generic{
public:
    ocean() {
        std:: cout << "Ocean creatures Constructor called" << std:: endl;
    }
    virtual ~ocean() override{
        std:: cout << "Ocean creatures Deconstructor called" << std:: endl;
    }

    void swim () {
        std:: cout << "I can swim" << std:: endl;
    }

    void eat() override {
        std::cout << "\033[33m";
        std::cout << "ocean creature eating" << std:: endl;
        std::cout << "\033[0m";
    }
};

class terrestrial : virtual public generic{
public:
    terrestrial() {
        std:: cout << "Terrestrial creatures Constructor called" << std:: endl;
    }
    virtual ~terrestrial() override{
        std:: cout << "Terrestrial creatures Deconstructor called" << std:: endl;
    }
    void walk() {
        std:: cout << "I can walk" << std:: endl;
    }

    void eat() override {
        std::cout << "\033[33m";
        std::cout << "terrestrial creature eating" << std:: endl;
        std::cout << "\033[0m";
    }

};

class amphibious : public ocean, public terrestrial{
public:
    amphibious() {
        std:: cout << "Amphibious creatures Constructor called" << std:: endl;
    }
    virtual ~amphibious() override{
        std:: cout << "Amphibious creatures Deconstructor called" << std:: endl;
    }

    void eat() override {
        std::cout << "\033[33m";
        std::cout << "amphibious creature eating" << std:: endl;
        std::cout << "\033[0m";
    }
};


class bird : virtual public terrestrial{
public:
    bird() {
        std:: cout << "Bird creatures Constructor called" << std:: endl;
    }
    virtual ~bird() override{
        std:: cout << "Bird creatures Deconstructor called" << std:: endl;
    }
    void fly () {
        std:: cout << "I can fly" << std:: endl;
    }

    void eat() override {
        std::cout << "\033[33m";
        std::cout << "bird creature eating" << std:: endl;
        std::cout << "\033[0m";
    }
};

class waterfowl: public bird, public ocean{
public:
    waterfowl() {
        std:: cout << "Waterfowl creatures Constructor called" << std:: endl;
    }
    virtual ~waterfowl() override{
        std:: cout << "Waterfowl creatures Deconstructor called" << std:: endl;
    }
    void eat() override {
        std::cout << "\033[33m";
        std::cout << "waterflow creature eating" << std:: endl;
        std::cout << "\033[0m";
    }
};

