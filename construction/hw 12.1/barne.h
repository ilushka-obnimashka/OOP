class Barne {
public:
    virtual ~Barne() = default;
    virtual void Build() const = 0;
};

class WoodBarne : public Barne {
public:
    virtual void Build() const override {
        std::cout << "Wooden barne built" << std::endl;
    }
};

class BrickBarne : public Barne {
public:
    virtual void Build() const override {
        std::cout << "Brick barne built" << std::endl;
    }
};

class ConcreteBarne : public Barne {
public:
    virtual void Build() const override {
        std::cout << "Concrete barne built" << std::endl;
    }
};

