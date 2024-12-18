#include <iostream>
#include <string>
#include "Products.h"
#include "Builder.h"
#include "Director.h"
#include "Products.h"


int main()
{
    Director director;

    director.SetBuilder("expensive");

    director.BuildHouse();

    auto result1 = director.getResult();

    std::cout << result1.first->PartsToString() << std::endl;
    std::cout << result1.second->PartsToString() << std::endl;

    std::cout << std::endl;

    director.SetBuilder("cheap");

    director.BuildHouse();

    auto result2 = director.getResult();

    std::cout << result2.first->PartsToString() << std::endl;
    std::cout << result2.second->PartsToString() << std::endl;



}