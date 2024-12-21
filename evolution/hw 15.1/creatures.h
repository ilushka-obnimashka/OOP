#pragma once
#include "visitor.h"
/*generic creature - общий родитель
ocean creature - наследник умеющий плавать
amphibious - наследник умеющий плавать и ходить
terrestrial creature - не умеет плавать, но умеет ходить
bird - умеет ходить и летать
waterfowl - водоплавающая птица. Умеет ходить, летать и плавать.*/


class generic
{
public:
    virtual ~generic() = default;
    virtual void accept(Visitor& visitor) = 0;
};

class ocean : virtual public generic
{
public:
    void swim()
    {
        std::cout << "I can swim" << std::endl;
    }

    virtual void accept(Visitor& visitor) override
    {
        visitor.Visit(*this);
    }
};

class terrestrial : virtual public generic
{
public:
    void walk()
    {
        std::cout << "I can walk" << std::endl;
    }

    virtual void accept(Visitor& visitor) override
    {
        visitor.Visit(*this);
    }
};

class amphibious : public ocean, public terrestrial
{
public:
    virtual void accept(Visitor& visitor) override
    {
        visitor.Visit(*this);
    }
};


class bird : virtual public terrestrial
{
public:
    void fly()
    {
        std::cout << "I can fly" << std::endl;
    }

    virtual void accept(Visitor& visitor) override
    {
        visitor.Visit(*this);
    }
};

class waterfowl : public bird, public ocean
{
public:
    virtual void accept(Visitor& visitor) override
    {
        visitor.Visit(*this);
    }
};
