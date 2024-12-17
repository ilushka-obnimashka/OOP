#pragma once
#include "creatures.h"
#include "food.h"

class fish : public ocean {
public:
    virtual void eat(food *name) override {
        std::cout << "fish eats :";
        if (dynamic_cast<worms *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class dolphin : public ocean {
public:
    virtual void eat(food *name) override {
        std::cout << "dolphin eats :";
        if (dynamic_cast<fishes *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class whale : public ocean {
public:
    virtual void eat(food *name) override {
        std::cout << "whale eats :" ;
        if (dynamic_cast<planktons *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};


class lion : public terrestrial {
public:
    virtual void eat(food *name) override {
        std::cout << "lion eats :";
        if (dynamic_cast<zebras *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class tiger : public terrestrial {
public:
    virtual void eat(food *name) override {
        std::cout << "tiger eats :" ;
        if (dynamic_cast<antelopes *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class monkey : public terrestrial {
public:
    virtual void eat(food *name) override {
        std::cout << "monkey eats :" ;
        if (dynamic_cast<bananas*>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class crocodile : public amphibious {
public:
    virtual void eat(food *name) override {
        std::cout << "crocodile eats :" ;
        if (dynamic_cast<arms *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class aligator : public amphibious {
public:
    virtual void eat(food *name) override {
        std::cout << "aligator eats :" ;
        if (dynamic_cast<legs *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class turtle : public amphibious {
public:
    virtual void eat(food *name) override {
        std::cout << "turtle eats :";
        if (dynamic_cast<frogs *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class parrot : public bird {
public:
    virtual void eat(food *name) override {
        std::cout << "parrot eats :";
        if (dynamic_cast<insects *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class eagle : public bird {
public:
    virtual void eat(food *name) override {
        std::cout << "eagle eats :" ;
        if (dynamic_cast<mice *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class owl : public bird {
public:
    virtual void eat(food *name) override {
        std::cout << "owl eats :" ;
        if (dynamic_cast<mice *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class duck : public waterfowl {
public:
    virtual void eat(food *name) override {
        std::cout << "duck eats :";
        if (dynamic_cast<fishes *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class penguin : public waterfowl {
public:
    virtual void eat(food *name) override {
        std::cout << "penguin eats :" ;
        if (dynamic_cast<fishes *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};

class swan : public waterfowl {
public:
    virtual void eat(food *name) override {
        std::cout << "swan eats :" ;
        if (dynamic_cast<fishes *>(name) == nullptr) {
            std::cout << "\033[31m nothing \033[0m" << std::endl;
        } else {
            name->PrintName();
        }
    }
};
