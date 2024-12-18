#ifndef DIRECTOR_H
#define DIRECTOR_H
#include "Builder.h"

class Director
{
private:
    Builder* builder;
public:
    Director() : builder(nullptr) {}

    void SetBuilder(std::string cost)
    {
        if (cost == "expensive") builder = new ExpensiveHouseBuilder;
        else if (cost == "cheap") builder = new CheapHouseBuilder;
        else
        {
            exit (-1);
        };
    }

    void BuildHouse()
    {
        if(dynamic_cast<ExpensiveHouseBuilder*>(builder) == nullptr)
        {
            builder->BuildFloor();
            builder->BuildWalls();
            builder->BuildRoof();
            builder->BuildDoors();
            builder->BuildWindows();
        }
        else
        {
            builder->BuildFloor();
            builder->BuildWalls();
            builder->BuildRoof();
            builder->BuildDoors();
            builder->BuildWindows();
            dynamic_cast<ExpensiveHouseBuilder*>(builder)->BuildFence();
        }
    }

    std::pair<House*, Documentation*> getResult()
    {
        auto result = builder->getResult();
        builder->Reset();
        return result;
    }
};


#endif //DIRECTOR_H
