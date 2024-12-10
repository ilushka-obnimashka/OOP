#pragma once
#include "creature squad.h"
#include "creatures.h"

class Creator {
public:
    virtual generic* create () = 0;
    virtual ~Creator() = default;
};

class CreatorFish : public Creator {
public:
    virtual generic* create() override {
        return new fish;
    }
};

class CreatorDolphin : public Creator {
public:
    virtual generic* create() override {
        return new dolphin;
    }
};

class CreatorWhale : public Creator {
public:
    virtual generic* create() override {
        return new whale;
    }
};

class CreatorLion : public Creator {
public:
    virtual generic* create() override {
        return new lion;
    }
};

class CreatorTiger : public Creator {
public:
    virtual generic* create() override {
        return new tiger;
    }
};

class CreatorMonkey : public Creator {
public:
    virtual generic* create() override {
        return new monkey;
    }
};

class CreatorCrocodile : public Creator {
public:
    virtual generic* create() override {
        return new crocodile;
    }
};

class CreatorAligator : public Creator {
public:
    virtual generic* create() override {
        return new aligator;
    }
};

class CreatorTurtle : public Creator {
public:
    virtual generic* create() override {
        return new turtle;
    }
};

class CreatorParrot: public Creator {
public:
    virtual generic* create() override {
        return new parrot;
    }
};

class CreatorEagle : public Creator {
public:
    virtual generic* create() override {
        return new eagle;
    }
};

class CreatorOwl : public Creator {
public:
    virtual generic* create() override {
        return new owl;
    }
};

class CreatorDuck : public Creator {
public:
    virtual generic* create() override {
        return new duck;
    }
};

class CreatorPenguin : public Creator {
public:
    virtual generic* create() override {
        return new penguin;
    }
};

class CreatorSwan : public Creator {
public:
    virtual generic* create() override {
        return new swan;
    }
};



