#ifndef CLASS_TIME_H
#define CLASS_TIME_H

#include <iostream>

class Time
{
    static int counter;
    int hours = 0, minutes = 0, seconds = 0;

public:
    Time();
    ~Time();
    Time (int h, int m, int s);
    Time (const Time& t);
    Time& operator= (const Time& other);
    Time& operator += (int s);
    Time& operator -= (int s);
    bool operator == (int s) const;
    bool operator == (const Time& t) const;
    Time operator + (int s) const;
    Time operator - (int s) const;
    int GetHours() const;
    int GetMinutes() const;
    int GetSeconds() const;
    static int GetCounter();
    void SetHours(int h);
    void SetMinutes(int m);
    void SetSeconds(int s);
    void PrintTime ();
    void Normalize();
    int ToSeconds() const;
    friend std::ostream& operator << (std::ostream& out, const Time& t);
    friend std::istream& operator >> (std::istream& in, Time& t);
};

#endif // CLASS_TIME_H
