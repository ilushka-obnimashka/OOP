#pragma once
#include <iostream>
#include <string>

class food {
public:
    virtual void PrintName() = 0;

    virtual std::string getName() = 0;

    virtual ~food() = default;
};


class human : public food {
public:
    virtual void PrintName() override {
        std::cout << "human" << std::endl;
    }

    virtual std::string getName() override {
        return "human";
    }
};


class arms : public human {
public:
    virtual void PrintName() override {
        std::cout << "arms" << std::endl;
    }

    virtual std::string getName() override {
        return "arms";
    }
};


class legs : public human {
public:
    virtual void PrintName() override {
        std::cout << "legs" << std::endl;
    }

    virtual std::string getName() override {
        return "legs";
    }
};


class worms : public food {
public:
    virtual void PrintName() override {
        std::cout << "worms" << std::endl;
    }

    virtual std::string getName() override {
        return "worms";
    }
};


class fishes : public food {
public:
    virtual void PrintName() override {
        std::cout << "fishes" << std::endl;
    }

    virtual std::string getName() override {
        return "fishes";
    }
};


class planktons : public food {
public:
    virtual void PrintName() override {
        std::cout << "planktons" << std::endl;
    }

    virtual std::string getName() override {
        return "planktons";
    }
};


class zebras : public food {
public:
    virtual void PrintName() override {
        std::cout << "zebras" << std::endl;
    }

    virtual std::string getName() override {
        return "zebras";
    }
};


class antelopes : public food {
public:
    virtual void PrintName() override {
        std::cout << "antelopes" << std::endl;
    }

    virtual std::string getName() override {
        return "antelopes";
    }
};


class bananas : public food {
public:
    virtual void PrintName() override {
        std::cout << "bananas" << std::endl;
    }

    virtual std::string getName() override {
        return "bananas";
    }
};

class frogs : public food {
public:
    virtual void PrintName() override {
        std::cout << "frogs" << std::endl;
    }

    virtual std::string getName() override {
        return "frogs";
    }
};


class insects : public food {
public:
    virtual void PrintName() override {
        std::cout << "insects" << std::endl;
    }

    virtual std::string getName() override {
        return "insects";
    }
};


class mice : public food {
public:
    virtual void PrintName() override {
        std::cout << "mice" << std::endl;
    }

    virtual std::string getName() override {
        return "mice";
    }
};
