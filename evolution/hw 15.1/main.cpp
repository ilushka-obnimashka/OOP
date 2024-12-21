#include <iostream>
#include <vector>
#include <memory>
#include "creatures.h"
#include "visitor.h"


int main()
{
    std::vector<std::shared_ptr<generic>> creatures;

    creatures.emplace_back(std::make_shared<amphibious>());
    creatures.push_back(std::make_shared<terrestrial>());
    creatures.push_back(std::make_shared<bird>());
    creatures.push_back(std::make_shared<ocean>());
    creatures.push_back(std::make_shared<waterfowl>());


    std::vector<std::shared_ptr<Visitor>> visitors;
    visitors.emplace_back(std::make_shared<EatVisitor>());
    visitors.push_back(std::make_shared<FlyVisitor>());
    visitors.push_back(std::make_shared<WalkVisitor>());
    visitors.push_back(std::make_shared<CleanVisitor>());
    visitors.push_back(std::make_shared<SleepVisitor>());


    for (auto creature : creatures)
    {
        for (auto visit : visitors)
        {
            creature->accept(*visit);
        }
        std::cout <<"================================"<<std::endl;
    }
}
