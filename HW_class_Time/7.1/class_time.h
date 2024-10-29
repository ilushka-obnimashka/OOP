#ifndef CLASS_TIME_H
#define CLASS_TIME_H

#include <iostream>

class Time;

class Watch {
    int format {24};
public:
    void SetFormat (int newFormat) {
        if (format != 12 && format !=24)  throw std::invalid_argument("format can be 12 or 24");
        format = newFormat;
    }

    void SetHours_Time(Time &t,int h);
    void SetMinutes_Time(Time &t, int m);
    void SetSeconds_Time(Time &t, int s);
    void PrintTime (const Time &t);
};


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

    friend class SimpleWatch;

    friend void Watch:: SetHours_Time(Time &t,int h);
    friend void Watch:: SetMinutes_Time(Time &t, int m);
    friend void Watch:: SetSeconds_Time(Time &t, int s);
    friend void Watch:: PrintTime (const Time &t);
};


class SimpleWatch {
    int format {24};
public:
    void SetFormat (int newFormat) {
        if (format != 12 && format !=24)  throw std::invalid_argument("format can be 12 or 24");
        format = newFormat;
    }
    void PrintTime (const Time &t) {
        if (format == 24) {
            std::cout << t.GetHours() << ":" << t.GetMinutes()
            << ":" << t.GetSeconds() << std::endl;
        }
        else {
            if (t.GetHours()>=1 && t.GetHours()<=11) {
                std::cout << t.GetHours() << ":" << t.GetMinutes()
            << ":" << t.GetSeconds() << " a.m." <<std::endl;
            }

            else if (t.GetHours()>=13 && t.GetHours()<=23) {
                std::cout << t.GetHours() - 12 << ":" << t.GetMinutes()
            << ":" << t.GetSeconds() << " p.m." <<std::endl;
            }

            else if (t.GetHours() == 0) {
                std::cout << "12:" << t.GetMinutes()
            << ":" << t.GetSeconds() << " a.m." <<std::endl;
            }

            else if (t.GetHours() == 12) {
                std::cout << "12:" << t.GetMinutes()
            << ":" << t.GetSeconds() << " p.m." <<std::endl;
            }
        }
    }

    void SetHours_Time(Time &t,int h) {
        if (h<0) throw std::invalid_argument("Hours can not be less 0");
        if (h > 24) throw std::invalid_argument("Hours can not be more 23");
        t.hours = h;
    }

    void SetMinutes_Time(Time &t, int m) {
        if (m<0) throw std::invalid_argument("Minutes can not be less 0");
        if (m > 59) throw std::invalid_argument("Minutes can not be more 60");;
        t.minutes = m;
    }

    void SetSeconds_Time(Time &t, int s) {
        if (s<0) throw std::invalid_argument("Seconds can not be less 0");
        if (s > 59) throw std::invalid_argument("Seconds can not be more 60");;
        t.seconds = s;
    }
};


void Watch:: SetHours_Time(Time &t,int h) {
    if (h<0) throw std::invalid_argument("Hours can not be less 0");
    if (h > 24) throw std::invalid_argument("Hours can not be more 23");
    t.hours = h;
}
void Watch:: SetMinutes_Time(Time &t, int m) {
    if (m<0) throw std::invalid_argument("Minutes can not be less 0");
    if (m > 59) throw std::invalid_argument("Minutes can not be more 60");;
    t.minutes = m;
}

void Watch:: SetSeconds_Time(Time &t, int s) {
    if (s<0) throw std::invalid_argument("Seconds can not be less 0");
    if (s > 59) throw std::invalid_argument("Seconds can not be more 60");;
    t.seconds = s;
}


void Watch:: PrintTime (const Time &t) {
    if (format == 24) {
        std::cout << t.GetHours() << ":" << t.GetMinutes()
        << ":" << t.GetSeconds() << std::endl;
    }
    else {
        if (t.GetHours()>=1 && t.GetHours()<=11) {
            std::cout << t.GetHours() << ":" << t.GetMinutes()
        << ":" << t.GetSeconds() << " a.m." <<std::endl;
        }

        else if (t.GetHours()>=13 && t.GetHours()<=23) {
            std::cout << t.GetHours() - 12 << ":" << t.GetMinutes()
        << ":" << t.GetSeconds() << " p.m." <<std::endl;
        }

        else if (t.GetHours() == 0) {
            std::cout << "12:" << t.GetMinutes()
        << ":" << t.GetSeconds() << " a.m." <<std::endl;
        }

        else if (t.GetHours() == 12) {
            std::cout << "12:" << t.GetMinutes()
        << ":" << t.GetSeconds() << " p.m." <<std::endl;
        }
    }
}

#endif // CLASS_TIME_H
