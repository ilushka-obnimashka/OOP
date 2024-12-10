#include <iostream>
#include <vector>

class House{
public:
    virtual void Build() = 0;
    virtual ~House() = default;
};

class WoodHouse : public House {
public:
    void Build () override {
        std::cout << "Building a wood house" << std::endl;
    }
};

class BrickHouse : public House {
public:
    void Build () override {
        std::cout << "Building a brick house" << std::endl;
    }
};

class ConcreteHouse : public House {
public:
    void Build () override {
        std::cout << "Building a concrete house" << std::endl;
    }
};

class Developer {
public:
    virtual House* BuildHouse () = 0;
    virtual ~Developer() = default;
};

class WoodHouseDeveloper : public Developer {
public:
    House* BuildHouse() override {
        return new WoodHouse();
    }
};

class BrickHouseDeveloper : public Developer {
public:
    House* BuildHouse() override {
        return new BrickHouse();
    }
};

class ConcreteHouseDeveloper : public Developer {
public:
    House* BuildHouse() override {
        return new ConcreteHouse();
    }
};

void constructionQuarter (Developer* developer, int count_house=4) {
    /**
     *params : Developer* developer - фабричный объект, отвечающий за создание дома определнного типа,
     *          count_house - количество домов в кварталe
     */
    for (int i = 0; i<count_house; i++) {
        House* house = developer->BuildHouse();
        house->Build();
        delete house;
    }
}


int main(){
    WoodHouseDeveloper wood_house_developer;
    BrickHouseDeveloper brick_house_developer;
    ConcreteHouseDeveloper concrete_house_developer;

    std::vector <int> count_houses_in_quarter {4,8,16};
    constructionQuarter(&wood_house_developer, count_houses_in_quarter[1]);
}