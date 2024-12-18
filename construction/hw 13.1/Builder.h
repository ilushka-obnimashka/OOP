#ifndef BUILDER_H
#define BUILDER_H
#include "Products.h"

class Builder
{
public:
    virtual ~Builder() = default;
    virtual void BuildWalls() const = 0;
    virtual void BuildRoof() const = 0;
    virtual void BuildFloor() const = 0;
    virtual void BuildDoors() const = 0;
    virtual void BuildWindows() const = 0;
    virtual std::pair<House*, Documentation*> getResult()  = 0;
    virtual void Reset() = 0;
};

class CheapHouseBuilder : public Builder
{
private:
    House* house_;
    Documentation* documentation_;

public:
    CheapHouseBuilder()
    {
        this->Reset();
    }

    ~CheapHouseBuilder()
    {
        delete house_;
        delete documentation_;
    }

    void Reset()
    {
        house_ = new House;
        documentation_ = new Documentation;
    }

    void BuildWalls() const override
    {
        house_->AddParts("Cheap Walls");
        documentation_->AddParts("Cheap Walls Documentation");
    }

    void BuildFloor() const override
    {
        house_->AddParts("Cheap Floor");
        documentation_->AddParts("Cheap Floor Documentation");
    }

    void BuildRoof() const override
    {
        house_->AddParts("Cheap Roof");
        documentation_->AddParts("Cheap Roof Documentation");
    }

    void BuildWindows() const override
    {
        house_->AddParts("Cheap Windows");
        documentation_->AddParts("Cheap Windows Documentation");
    }

    void BuildDoors() const override
    {
        house_->AddParts("Cheap Doors");
        documentation_->AddParts("Cheap Doors Documentation");
    }

    std::pair<House*, Documentation*> getResult() override
    {
        auto result = std::make_pair(house_, documentation_);
        this->Reset();
        return result;
    }

};

class ExpensiveHouseBuilder : public Builder
{
private:
    House* house_;
    Documentation* documentation_;

public:
    ExpensiveHouseBuilder()
    {
        this->Reset();
    }

    ~ExpensiveHouseBuilder()
    {
        delete house_;
        delete documentation_;
    }

    void Reset()
    {
        house_ = new House;
        documentation_ = new Documentation;
    }

    void BuildWalls() const override
    {
        house_->AddParts("Expensive Walls");
        documentation_->AddParts("Expensive Walls Documentation");
    }

    void BuildFloor() const override
    {
        house_->AddParts("Expensive Floor");
        documentation_->AddParts("Expensive Floor Documentation");
    }

    void BuildRoof() const override
    {
        house_->AddParts("Expensive Roof");
        documentation_->AddParts("Expensive Roof Documentation");
    }

    void BuildWindows() const override
    {
        house_->AddParts("Expensive Windows");
        documentation_->AddParts("Expensive Windows Documentation");
    }

    void BuildDoors() const override
    {
        house_->AddParts("Expensive Doors");
        documentation_->AddParts("Expensive Doors Documentation");
    }

    void BuildFence() const
    {
        house_->AddParts("Expensive Fence");
        documentation_->AddParts("Expensive Fence Documentation");
    }

    std::pair<House*, Documentation*> getResult() override
    {
        auto result = std::make_pair(house_, documentation_);
        Reset();
        return result;
    }

};

#endif //BUILDER_H
