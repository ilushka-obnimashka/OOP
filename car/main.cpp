#include <iostream>
#include "car.h"


int main ()
{
    Car car;
    car.SetRpm(1000);

    car.SetGear(1);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(2);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(3);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(4);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(5);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(6);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;


    car.SetRpm(2000);

    car.SetGear(5);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(4);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(3);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(2);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(1);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;

    car.SetGear(-1);
    car.UpdateSpeed();
    std::cout << "speed: " << car.GetSpeed() << "rpm: "<< car.GetRpm() << std::endl;


}




