class House {
public:
    virtual void Build() const = 0;

    virtual ~House() = default;
};

class WoodHouse : public House {
public:
    virtual void Build() const override {
        std::cout << "Wooden house built" << std::endl;
    }
};

class BrickHouse : public House {
public:
    virtual void Build() const override {
        std::cout << "Brick house built" << std::endl;
    }
};

class ConcreteHouse : public House {
public:
    virtual void Build() const override {
        std::cout << "Concrete house built" << std::endl;
    }
};
