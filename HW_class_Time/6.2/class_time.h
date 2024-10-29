#ifndef CLASS_TIME_H
#define CLASS_TIME_H

#include <iostream>

class Time
{
    static int counter;
    int hours = 0, minutes = 0, seconds = 0;

public:
    Time() ;
    ~Time() ;
    Time (int h, int m, int s);
    Time (const Time& t) ;
    Time& operator= (const Time& other) noexcept;
    Time& operator += (int s) noexcept;
    Time& operator -= (int s) noexcept;
    bool operator == (int s) const noexcept;
    bool operator == (const Time& t) const noexcept;
    Time operator + (int s) const noexcept;
    Time operator - (int s) const noexcept;
    int GetHours() const noexcept;
    int GetMinutes() const noexcept;
    int GetSeconds() const noexcept;
    static int GetCounter() noexcept;
    void SetHours(int h);
    void SetMinutes(int m);
    void SetSeconds(int s);
    void PrintTime () noexcept;
    void Normalize() noexcept;
    int ToSeconds() const noexcept;
    friend std::ostream& operator << (std::ostream& out, const Time& t) noexcept ;
    friend std::istream& operator >> (std::istream& in, Time& t) noexcept;


};

#endif // CLASS_TIME_H
