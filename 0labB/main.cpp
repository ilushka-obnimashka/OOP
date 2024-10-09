#include <iostream>


class Time
{
int hours = 0;
int minutes = 0;
int sevonds = 0;

public:
    void InternalPrint()
    {
        std:: cout << "HH:MM::SS\n" << hours << ":"\
                   << minutes << ":" << seconds << std:: endl;
    }

    void SetHours (int hours) { this->hours = hours; };
    void SetMinutes (int minutes) { this->minutes = minutes; };
    void SetSeconds (int seconds) { this->seconds = seconds; };

    int GetHours () const { return hours; };
    int GetMinutes () const { return minutes; };
    int GetSeconds () const { return seconds; };

};