#include <vector>
#include <memory>
#include "creatures.h"
#include "food.h"
#include "factory.h"


int main() {

    OceanCreatureFactory ocean_creature_factory;
    std::vector<std::shared_ptr<generic>> ocean_generics = ocean_creature_factory.CreateAll();
    std::vector<std::shared_ptr<food>> ocean_generics_foods =ocean_creature_factory.CreateFood();

    for (auto i : ocean_generics)
    {
        i->eat(ocean_generics_foods.front().get());
        ocean_generics_foods.erase(ocean_generics_foods.begin());
    }

}
