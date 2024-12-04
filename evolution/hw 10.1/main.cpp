#include <iostream>
#include <vector>
#include <memory>
#include "creatures.h"

// Вопрос , нужно ли описывать деструкторы классов как virtual если можно использовать умные указатели?? Будет ли это эффективнее??


int main() {
    /* иллюстрируется не полиморфное поведение*/
    /*
    std::vector <generic> creatures;
    amphibious a;
    creatures.push_back(a);

    terrestrial t;
    creatures.push_back(t);

    bird b;
    creatures.push_back(b);

    ocean o;
    creatures.push_back(o);

    waterfowl w;
    creatures.push_back(w);

    system("clear");// очистить сообщения конструкторов

    for (size_t i =0 ; i<creatures.size(); i++) {
        creatures[i].eat();
    }
        /* будет вызываться generic:: eat();
    }*/

    /* иллюстрируется полиморфное поведение*/

    std::vector <std::shared_ptr<generic>> creatures;

    auto ptr_a = std::make_shared<amphibious>();
    creatures.push_back(ptr_a);

    auto ptr_t = std::make_shared<terrestrial>();
    creatures.push_back(ptr_t);

    auto ptr_b = std::make_shared<bird>();
    creatures.push_back(ptr_b);

    auto ptr_o = std::make_shared<ocean>();
    creatures.push_back(ptr_o);

    auto ptr_w = std::make_shared<waterfowl>();
    creatures.push_back(ptr_w);

    system("clear");// очистить сообщения конструкторов


    for (size_t i =0 ; i<creatures.size(); i++) {
        creatures[i]->eat();
        /* будет вызываться eat() оответсвтующий конкретному экземпляру;*/
    }

}