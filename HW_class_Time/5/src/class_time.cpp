#include "class_time.h"
#include <iostream>
#include <vector>
#include <list>
#include <memory>


#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int Time::counter = 0;

Time::Time() {
    counter++;
    std::cout << "Constructor called. Object count: " << counter << std::endl;
}

Time::~Time() {
    counter--;
    std::cout << "Deconstructor called. Object count: " << counter << std::endl;
}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    counter++;
    std::cout << "Constructor called. Object count: " << counter << std::endl;
    Normalize();
}

Time::Time(const Time& t) : hours(t.hours), minutes(t.minutes), seconds(t.seconds) {
    counter++;
    std::cout << "Copy constructor called. Object count: " << counter << std::endl;
}

Time& Time::operator=(const Time& other) {;
    this->hours = other.hours;
    this->minutes = other.minutes;
    this->seconds = other.seconds;
    return *this;
}

Time& Time::operator+=(int s) {
    this->seconds += s;
    Normalize();
    return *this;
}

Time& Time::operator-=(int s) {
    this->seconds -= s;
    Normalize();
    return *this;
}

bool Time::operator==(int s) const {
    if (this->ToSeconds() == s) return true;
    return false;
}

bool Time::operator==(const Time& t) const {
    if (this->ToSeconds() == t.ToSeconds()) return true;
    return false;
}

Time Time::operator+(int s) const {
    return Time(hours, minutes, seconds + s);
}

Time Time::operator-(int s) const {
    return Time(hours, minutes, seconds - s);
}

int Time::GetHours() const { return hours; }
int Time::GetMinutes() const { return minutes; }
int Time::GetSeconds() const { return seconds; }
int Time::GetCounter() { return counter; };

void Time::SetHours(int h) {
    hours = h;
    if (hours > 24) Normalize();
}

void Time::SetMinutes(int m) {
    minutes = m;
    if (minutes > 59) Normalize();
}

void Time::SetSeconds(int s) {
    seconds = s;
    if (seconds > 59) Normalize();
}

void Time::PrintTime() {
    std::cout << "H:" << this->GetHours() << " M:" << this->GetMinutes() << " S:" << this->GetSeconds() << std::endl;
}

void Time::Normalize() {
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

int Time::ToSeconds() const {
    int totalSec = 0;
    totalSec += this->GetSeconds();
    totalSec += this->GetMinutes() * 60;
    totalSec += this->GetHours() * 60 * 60;
    return totalSec;
}

std::ostream& operator<<(std::ostream& out, const Time& t) {
    out << t.GetHours() << ":" << t.GetMinutes() << ":" << t.GetSeconds() << std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, Time& t) {
    int h, m, s;
    char tmp;

    in >> h >> tmp;
    in >> m >> tmp;
    in >> s >> tmp;

    t = Time(h, m, s);
    return in;
}

int main() {
    return 0;
}