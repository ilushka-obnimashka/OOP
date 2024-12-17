class Developer
{
public:
    virtual House* BuildHouse() const = 0;

    virtual Fence* BuildFence() const = 0;

    virtual Barne* BuildBarne() const = 0;
};


class WoodDeveloper : public Developer
{
    virtual House* BuildHouse() const override
    {
        return new WoodHouse();
    }

    virtual Fence* BuildFence() const override
    {
        return new WoodFence();
    }

    virtual Barne* BuildBarne() const override
    {
        return new WoodBarne();
    }
};

class BrickDeveloper : public Developer
{
    virtual House* BuildHouse() const override
    {
        return new BrickHouse();
    }

    virtual Fence* BuildFence() const override
    {
        return new BrickFence();
    }

    virtual Barne* BuildBarne() const override
    {
        return new BrickBarne();
    }
};

class ConcreteDeveloper : public Developer
{
    virtual House* BuildHouse() const override
    {
        return new ConcreteHouse();
    }

    virtual Fence* BuildFence() const override
    {
        return new ConcreteFence();
    }

    virtual Barne* BuildBarne() const override
    {
        return new ConcreteBarne();
    }
};
