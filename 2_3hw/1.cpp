#include <iostream>
class Time
{
    int hours, minutes, seconds;
public:
    Time() {};
    Time(int h, int m, int s) :hours(h), minutes(m), seconds(s) {};
    Time(const Time& t) :Time(t.hours, t.minutes, t.seconds) {};
    Time& operator = (const Time & other)
    {
        this->hours = other.hours;
        this->minutes = other.minutes;
        this->seconds = other.seconds;
        return *this;
    }
    int GetHours() const { return hours; }
    int GetMinutes() const { return minutes; }
    int GetSeconds() const { return seconds; }
    int ToSeconds() const { return hours * 3600 + minutes * 60 + seconds; }
    Time operator + (int s)
    {
        return (Time(this->GetHours(), this->GetMinutes(), this->GetSeconds() + s));
    }
    Time operator - (int s)
    {
        return (Time(this->GetHours(), this->GetMinutes(), this->GetSeconds() - s));
    }
    Time operator+=(int s)
    {
        this->seconds += s;
        this->Normalize();
        return *this;
    }
    Time operator-=(int s)
    {
        this->seconds -= s;
        this->Normalize();
        return *this;
    }
    void Normalize()
    {
        this->minutes += this->seconds/60;
        this->seconds %= 60;
        this->hours += this->minutes/60;
        this->minutes %= 60;
        this->hours %= 24;
    }

    friend std::istream& operator >> (std::istream& in, Time& t) {
        int h,m,s;
        char tmp;

        in >> h >> tmp;
        in >> m >> tmp;
        in >> s >> tmp;

        t = Time(h,m,s);
        return in;

    }
    friend std::ostream& operator << (std::ostream& out, const Time& t) {
        out<< t.GetHours() << ":" << t.GetMinutes() << ":" << t.GetSeconds();
        return out;
    }

};
int main()
{
    Time t1(1, 1, 1);
    t1 -= 12345;
    t1.Normalize();
    std:: cout << t1;
}