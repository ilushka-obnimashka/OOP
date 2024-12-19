#ifndef GEARS_H
#define GEARS_H

class AbstractGear
{
public:
    virtual double CalculateSpeed(int rpm) = 0;
};

class NeutralGear : public AbstractGear
{
public:
    virtual double CalculateSpeed(int rpm) override
    {
        return 0;
    }
};

class ReverseGear : public AbstractGear
{
public:
    virtual double CalculateSpeed(int rpm) override
    {
        return -rpm * 0.01;
    }
};

class ForwardGear : public AbstractGear
{
private:
    int gear_number_;

public:
    explicit ForwardGear(int gear_number)
        : gear_number_(gear_number)
    {
    };

    virtual double CalculateSpeed(int rpm) override
    {
        return rpm * gear_number_ * 0.05;
    }
};


#endif //GEARS_H
