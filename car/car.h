#ifndef CAR_H
#define CAR_H

#include "gears.h"

class Car
{
private:
    AbstractGear* gear_strategy_;
    int numb_gear_;
    int rpm_;
    int speed_;

public:
    Car()
    {
        gear_strategy_ = new NeutralGear;
        numb_gear_ = 0;
        rpm_ = 0;
    }

    ~Car()
    {
        delete gear_strategy_;
    }

    void SetRpm(int rpm)
    {
        rpm_= rpm;
    }

    int GetSpeed() const
    {
        return speed_;
    }

    int GetRpm() const
    {
        return rpm_;
    }

    void UpdateSpeed()
    {
        speed_ = gear_strategy_->CalculateSpeed(rpm_);
    }

    void SetGear(int gear)
    {
        switch (gear)
        {
        case(0):
            delete gear_strategy_;
            gear_strategy_ = new NeutralGear;
            SetRpmAfterSwitching(0);
            numb_gear_ =0 ;
            break;
        case(1):
            delete gear_strategy_;
            gear_strategy_ = new ForwardGear(1);
            SetRpmAfterSwitching(1);
            numb_gear_ =1 ;
            break;

        case(2):
            delete gear_strategy_;
            gear_strategy_ = new ForwardGear(2);
            SetRpmAfterSwitching(2);
            numb_gear_ =2 ;
            break;
        case(3):
            delete gear_strategy_;
            gear_strategy_ = new ForwardGear(3);
            SetRpmAfterSwitching(3);
            numb_gear_ =3 ;
            break;

        case(4):
            delete gear_strategy_;
            gear_strategy_ = new ForwardGear(4);
            SetRpmAfterSwitching(4);
            numb_gear_ =4 ;
            break;

        case(5):
            delete gear_strategy_;
            gear_strategy_ = new ForwardGear(5);
            SetRpmAfterSwitching(5);
            numb_gear_ =5 ;
            break;

        case(6):
            delete gear_strategy_;
            gear_strategy_ = new ForwardGear(6);
            SetRpmAfterSwitching(6);
            numb_gear_ =6 ;
            break;
        case(-1):
            delete gear_strategy_;
            gear_strategy_ = new ReverseGear();
            SetRpmAfterSwitching(-1);
            numb_gear_ =-1 ;
            rpm_ = 1000;
            break;

        default:
            std::cerr << "Incorrect gear meaning" << std::endl;
            delete gear_strategy_;
            gear_strategy_ = new NeutralGear;
            SetRpmAfterSwitching(0);
            numb_gear_ = 0;
            break;
        }
    }

    void SetRpmAfterSwitching(int gear)
    {
        if (gear > numb_gear_)
            rpm_ *= 0.8;
        else if (gear == 0 || gear == -1)
            rpm_ = 0;
        else
            rpm_ /= 0.8 ;
    }
};

#endif //CAR_H
