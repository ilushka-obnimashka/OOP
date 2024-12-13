class Fence {
public:
    virtual ~Fence() = default;
    virtual void Build() const = 0;
};

class WoodFence : public Fence {
public:
    virtual void Build() const override {
        std::cout << "Wooden fence built" << std::endl;
    }
};

class BrickFence : public Fence {
public:
    virtual void Build() const override {
        std::cout << "Brick fence built" << std::endl;
    }
};

class ConcreteFence : public Fence {
public:
    virtual void Build() const override {
        std::cout << "Concrete fence built" << std::endl;
    }
};

