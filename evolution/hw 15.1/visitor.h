#pragma once

class Visitor
{
public:
    virtual void Visit(class ocean& ocean) = 0;
    virtual void Visit(class amphibious& amphibius) = 0;
    virtual void Visit(class waterfowl& waterfowl) = 0;
    virtual void Visit(class terrestrial& terrestrial) = 0;
    virtual void Visit(class bird& bird) = 0;
};


class EatVisitor : public Visitor
{
public:
    virtual void Visit(class ocean& ocean) override
    {
        std::cout << "\033[33m";
        std::cout << "ocean creature eating" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class amphibious& amphibius) override
    {
        std::cout << "\033[33m";
        std::cout << "amphibious creature eating" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class waterfowl& waterfowl) override
    {
        std::cout << "\033[33m";
        std::cout << "waterflow creature eating" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class terrestrial& terrestrial) override
    {
        std::cout << "\033[33m";
        std::cout << "terrestrial creature eating" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class bird& bird) override
    {
        std::cout << "\033[33m";
        std::cout << "bird creature eating" << std::endl;
        std::cout << "\033[0m";
    }
};

class WalkVisitor : public Visitor
{
public:
    virtual void Visit(class ocean& ocean) override
    {
        std::cout << "\033[31m";
        std::cout << "ocean creature went for a walk" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class amphibious& amphibius) override
    {
        std::cout << "\033[31m";
        std::cout << "amphibious creature went for a walk" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class waterfowl& waterfowl) override
    {
        std::cout << "\033[31m";
        std::cout << "waterflow creature went for a walk" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class terrestrial& terrestrial) override
    {
        std::cout << "\033[31m";
        std::cout << "terrestrial creature went for a walk" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class bird& bird) override
    {
        std::cout << "\033[31m";
        std::cout << "bird creature went for a walk" << std::endl;
        std::cout << "\033[0m";
    }
};

class SwimVisitor : public Visitor
{
    virtual void Visit(class ocean& ocean) override
    {
        return;
    }

    virtual void Visit(class amphibious& amphibius) override
    {
        std::cout << "\033[33m";
        std::cout << "amphibious creature went swimming" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class waterfowl& waterfowl) override
    {
        std::cout << "\033[33m";
        std::cout << "waterflow creature went swimming" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class terrestrial& terrestrial) override
    {
        return;
    }

    virtual void Visit(class bird& bird) override
    {
        return;
    }
};

class FlyVisitor : public Visitor
{
public:
    virtual void Visit(class ocean& ocean) override
    {
        return;
    }

    virtual void Visit(class amphibious& amphibious) override
    {
        return;
    }

    virtual void Visit(class waterfowl& waterfowl) override
    {
        std::cout << "\033[36m";
        std::cout << "waterfowl creature went flying" << std::endl;
        std::cout << "\033[0m";
    }

    virtual void Visit(class terrestrial& terrestrial) override
    {
        // Пустая реализация для Terrestrial
    }

    virtual void Visit(class bird& bird) override
    {
        std::cout << "\033[36m";
        std::cout << "bird creature went flying" << std::endl;
        std::cout << "\033[0m";
    }
};

class SleepVisitor : public Visitor
{
public:
    void Visit(class ocean& ocean) override
    {
        std::cout << "\033[35m";
        std::cout << "ocean creature went to sleep" << std::endl;
        std::cout << "\033[0m";
    }

    void Visit(class amphibious& amphibious) override
    {
        std::cout << "\033[35m";
        std::cout << "amphibious creature went to sleep" << std::endl;
        std::cout << "\033[0m";
    }

    void Visit(class waterfowl& waterfowl) override
    {
        std::cout << "\033[35m";
        std::cout << "waterfowl creature went to sleep" << std::endl;
        std::cout << "\033[0m";
    }

    void Visit(class terrestrial& terrestrial) override
    {
        std::cout << "\033[35m";
        std::cout << "terrestrial creature went to sleep" << std::endl;
        std::cout << "\033[0m";
    }

    void Visit(class bird& bird) override
    {
        std::cout << "\033[35m";
        std::cout << "bird creature went to sleep" << std::endl;
        std::cout << "\033[0m";
    }
};

class CleanVisitor : public Visitor
{
public:
    void Visit(class ocean& ocean) override
    {
        // Океанские существа не чистят перья
    }

    void Visit(class amphibious& amphibious) override
    {
        // Амфибии не чистят перья
    }

    void Visit(class waterfowl& waterfowl) override
    {
        std::cout << "\033[32m";
        std::cout << "waterfowl creature is cleaning its feathers" << std::endl;
        std::cout << "\033[0m";
    }

    void Visit(class terrestrial& terrestrial) override
    {
        // Наземные существа не чистят перья
    }

    void Visit(class bird& bird) override
    {
        std::cout << "\033[32m";
        std::cout << "bird creature is cleaning its feathers" << std::endl;
        std::cout << "\033[0m";
    }
};
