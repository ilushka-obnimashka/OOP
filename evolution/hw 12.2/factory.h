#pragma once
#include <memory>
#include "creature squad.h"
#include "food.h"


class CreatureFactory {
public:
    virtual std::vector<std::shared_ptr<generic>> CreateAll () const = 0;
    virtual std::vector<std::shared_ptr<food>> CreateFood() const = 0;
    virtual ~CreatureFactory() = default;
};

class OceanCreatureFactory : public CreatureFactory {
public:
    generic* createDolphin() const {
        return new dolphin;
    }

    generic* createFish() const {
        return new fish;
    }

    generic* createWhale() const {
        return new whale;
    }
    virtual std::vector<std::shared_ptr<generic>> CreateAll() const override
    {
        std::vector<std::shared_ptr<generic>> all;

        all.emplace_back(std::make_unique<dolphin>());
        all.emplace_back(std::make_unique<fish>());
        all.emplace_back(std::make_unique<whale>());
        return all;
    }

    virtual std::vector<std::shared_ptr<food>> CreateFood() const override
    {
        std::vector<std::shared_ptr<food>> all_foods;

        all_foods.emplace_back(std::make_unique<fishes>());
        all_foods.emplace_back(std::make_unique<worms>());
        all_foods.emplace_back(std::make_unique<planktons>());
        return all_foods;
    }
};

class TerrestrialCreatureFactory : public CreatureFactory {
public:
    generic* createAmphibious() const {
        return new aligator;
    }

    generic* createCrocodile() const {
        return new crocodile;
    }

    generic* createLion() const {
        return new lion;
    }

    generic* createMonkey() const {
        return new monkey;
    }

    generic* createTiger() const {
        return new tiger;
    }

    std::vector<std::shared_ptr<generic>> CreateAll() const override
    {
        std::vector<std::shared_ptr<generic>> all;

        all.emplace_back(std::make_unique<aligator>());
        all.emplace_back(std::make_unique<crocodile>());
        all.emplace_back(std::make_unique<lion>());
        all.emplace_back(std::make_unique<monkey>());
        all.emplace_back(std::make_unique<tiger>());

        return all;
    }

    std::vector<std::shared_ptr<food>> CreateFood() const override
    {
        std::vector<std::shared_ptr<food>> all_foods;

        all_foods.emplace_back(std::make_unique<legs>());
        all_foods.emplace_back(std::make_unique<arms>());
        all_foods.emplace_back(std::make_unique<zebras>());
        all_foods.emplace_back(std::make_unique<bananas>());
        all_foods.emplace_back(std::make_unique<antelopes>());

        return all_foods;
    }
};

class BirdFactory : public CreatureFactory {
public:
    generic* createEagle() const {
        return new eagle;
    }

    generic* createOwl() const {
        return new owl;
    }

    generic* createParrot() const {
        return new parrot;
    }

    generic* createWaterfowl() const {
        return new duck;
    }

    generic* createPenguin() const {
        return new penguin;
    }

    generic* createSwan() const {
        return new swan;
    }

    std::vector<std::shared_ptr<generic>> CreateAll() const override
    {
        std::vector<std::shared_ptr<generic>> all;

        all.emplace_back(std::make_unique<eagle>());
        all.emplace_back(std::make_unique<owl>());
        all.emplace_back(std::make_unique<parrot>());
        all.emplace_back(std::make_unique<duck>());
        all.emplace_back(std::make_unique<penguin>());
        all.emplace_back(std::make_unique<swan>());

        return all;
    }

    std::vector<std::shared_ptr<food>> CreateFood() const override
    {
        std::vector<std::shared_ptr<food>> all;

        all.emplace_back(std::make_unique<mice>());
        all.emplace_back(std::make_unique<mice>());
        all.emplace_back(std::make_unique<insects>());
        all.emplace_back(std::make_unique<fishes>());
        all.emplace_back(std::make_unique<fishes>());
        all.emplace_back(std::make_unique<fishes>());

        return all;
    }
};
