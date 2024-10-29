#include "class_time.h"
#include <iostream>
#include <vector>
#include <list>
#include <memory>


#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int Time::counter = 0;

Time:: Time()  {
    counter++;
    std::cout << "Constructor called. Object count: " << counter << std::endl;
}

Time::~Time() {
    counter--;
    std::cout << "Deconstructor called. Object count: " << counter << std::endl;
}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    if (h<0) throw std::invalid_argument("Hours can not be less 0");
    if (m<0) throw std::invalid_argument("Minutes can not be less 0");
    if (s<0) throw std::invalid_argument("Seconds can not be less 0");
    if (h>23) throw std::invalid_argument("Hours can not be more 23");
    if (m>59) throw std::invalid_argument("Minutes can not be more 60");
    if (s>59) throw std::invalid_argument("Seconds can not be more 60");


    counter++;
    std::cout << "Constructor called. Object count: " << counter << std::endl;
    Normalize();
}

Time::Time(const Time& t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds) {
    counter++;
    std::cout << "Copy constructor called. Object count: " << counter << std::endl;
}

Time& Time::operator=(const Time& other) noexcept {;
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
    return *this;
}

Time& Time::operator+=(int s) noexcept {
    this->seconds += s;
    Normalize();
    return *this;
}

Time& Time::operator-=(int s) noexcept{
    this->seconds -= s;
    Normalize();
    return *this;
}

bool Time::operator==(int s) const noexcept {
    if (this->ToSeconds() == s) return true;
    return false;
}

bool Time::operator==(const Time& t) const noexcept {
    if (this->ToSeconds() == t.ToSeconds()) return true;
    return false;
}

Time Time::operator+(int s) const noexcept {
    return Time(hours, minutes, seconds + s);
}

Time Time::operator-(int s) const noexcept {
    return Time(hours, minutes, seconds - s);
}

int Time::GetHours() const noexcept { return hours; }
int Time::GetMinutes() const noexcept { return minutes; }
int Time::GetSeconds() const noexcept { return seconds; }
int Time::GetCounter() noexcept { return counter; };

void Time::SetHours(int h) {
    if (h<0) throw std::invalid_argument("Hours can not be less 0");
    hours = h;
    if (hours > 24) throw std::invalid_argument("Hours can not be more 23");
}

void Time::SetMinutes(int m) {
    if (m<0) throw std::invalid_argument("Minutes can not be less 0");
    minutes = m;
    if (minutes > 59) throw std::invalid_argument("Minutes can not be more 60");;
}

void Time::SetSeconds(int s) {
    if (s<0) throw std::invalid_argument("Seconds can not be less 0");
    seconds = s;
    if (seconds > 59) throw std::invalid_argument("Seconds can not be more 60");;
}

void Time::PrintTime() noexcept {
    std::cout << "H:" << this->GetHours() << " M:" << this->GetMinutes() << " S:" << this->GetSeconds() << std::endl;
}

void Time::Normalize() noexcept {
    int totalSec = this->ToSeconds();

    if (totalSec < 0) {
        this->SetHours(0);
        this->SetMinutes(0);
        this->SetSeconds(0);
    } else {
        int h = totalSec / 3600 % 24;
        totalSec -= 3600 * (totalSec / 3600);
        int m = totalSec / 60 % 60;
        totalSec -= 60 * (totalSec / 60);
        int s = totalSec;

        this->SetHours(h);
        this->SetMinutes(m);
        this->SetSeconds(s);
    }
}

int Time::ToSeconds() const noexcept {
    int totalSec = 0;
    totalSec += this->GetSeconds();
    totalSec += this->GetMinutes() * 60;
    totalSec += this->GetHours() * 60 * 60;
    return totalSec;
}

std::ostream& operator<<(std::ostream& out, const Time& t) noexcept {
    out << t.GetHours() << ":" << t.GetMinutes() << ":" << t.GetSeconds() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Time& t) noexcept {
    int h, m, s;
    char tmp;

    in >> h >> tmp;
    in >> m >> tmp;
    in >> s >> tmp;

    t = Time(h, m, s);
    return in;
}

int main() {
    try
    {
        Time t(10,20,30);
        std:: cout << t;
        try
        {
         t.SetHours(-10);
        }
        catch (std:: exception &ex)
        {
            std::cerr << "Error: " << ex.what() <<  std::endl;
        }
    }
    catch (std:: exception &ex)
    {
        std::cerr << "Error: " << ex.what() <<  std::endl;
    }

    /*try
    {
        Time t(-10,20,30);
        std:: cout << t;
    }
    catch (std:: exception &ex)
    {
        std::cerr<< "Error: " << ex.what() << std::endl;
    }

    try
    {
        Time t(10,-20,30);
        std:: cout << t;
    }
    catch (std:: exception &ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
    }*/

}
