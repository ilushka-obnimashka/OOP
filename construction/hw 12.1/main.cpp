#include <iostream>
#include <vector>
#include "house.h"
#include "fence.h"
#include "barne.h"
#include "developer.h"

void construction(Developer* developer) {
    /**
     *params : Developer* developer - объект фабрики объектов, отвечающий за создание дома, забора, сарая определнного типа,
     */
    House* house = developer->BuildHouse();
    Fence* fence = developer->BuildFence();
    Barne* barne = developer->BuildBarne();

    house->Build();
    fence->Build();
    barne->Build();
}


int main(){
    WoodDeveloper wood_developer;
    construction(&wood_developer);
}