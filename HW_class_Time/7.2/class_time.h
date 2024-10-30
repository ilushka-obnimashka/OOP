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
    void PrintTime () const noexcept;
    void Normalize() noexcept;
    int ToSeconds() const noexcept;
    friend std::ostream& operator << (std::ostream& out, const Time& t) noexcept ;
    friend std::istream& operator >> (std::istream& in, Time& t) noexcept;

};



class Watch {
public:
    Watch() {
        std::cout << "Watch constructor called." << std::endl;
    };
    ~Watch() {
        std::cout << "Watch deconstructor called." << std::endl;
    };
    void setTime (const Time& time) {
        TimeOnWatch = time;
    }
    void showTime() const{
        TimeOnWatch.PrintTime();
    }

    void settingHours (int hours) {
        try{TimeOnWatch.SetHours(hours);}
        catch(std::exception &ex) {std::cerr << "Error: "<<ex.what()<< std::endl;}

    }
    void settingMinutes (int minutes) {
        try{TimeOnWatch.SetMinutes(minutes);}
        catch(std::exception &ex) {std::cerr << "Error: "<<ex.what()<< std::endl;}
    }

    void settingSeconds (int seconds) {
        try{TimeOnWatch.SetSeconds(seconds);}
        catch(std::exception &ex) {std::cerr << "Error: "<<ex.what()<< std::endl;}
    }


    void timeDifference(const Watch& other) {
        int dif = abs(this->TimeOnWatch.ToSeconds() - other.TimeOnWatch.ToSeconds());
        Time difTime (0,0,0);
        difTime+=dif;
        difTime.PrintTime();
    }

    bool operator == (const Watch& w) const {
        return this->TimeOnWatch == w.TimeOnWatch;
    }

protected:
    Time TimeOnWatch;
};

class WallClock : public Watch {
public:
    WallClock() {
        std::cout << "WallClock constructor called." << std::endl;
    }
    ~WallClock() {
        std::cout << "WallClock deconstructor called." << std::endl;
    }
    void setFormat (int newFormat) {
        if (format != 12 && format !=24)  throw std::invalid_argument("format can be 12 or 24");
        format = newFormat;
    }
    void showTime () const {
        if (format == 24) {
            std::cout << TimeOnWatch.GetHours() << ":" << TimeOnWatch.GetMinutes()
            << ":" << TimeOnWatch.GetSeconds() << std::endl;
        }
        else {
            if (TimeOnWatch.GetHours()>=1 && TimeOnWatch.GetHours()<=11) {
                std::cout << TimeOnWatch.GetHours() << ":" << TimeOnWatch.GetMinutes()
            << ":" << TimeOnWatch.GetSeconds() << " a.m." <<std::endl;
            }

            else if (TimeOnWatch.GetHours()>=13 && TimeOnWatch.GetHours()<=23) {
                std::cout << TimeOnWatch.GetHours() - 12 << ":" << TimeOnWatch.GetMinutes()
            << ":" << TimeOnWatch.GetSeconds() << " p.m." <<std::endl;
            }

            else if (TimeOnWatch.GetHours() == 0) {
                std::cout << "12:" << TimeOnWatch.GetMinutes()
            << ":" << TimeOnWatch.GetSeconds() << " a.m." <<std::endl;
            }

            else if (TimeOnWatch.GetHours() == 12) {
                std::cout << "12:" << TimeOnWatch.GetMinutes()
            << ":" << TimeOnWatch.GetSeconds() << " p.m." <<std::endl;
            }
        }
    }
protected:
    int format {24};
};

class CuckooClock : public WallClock {
public:
    CuckooClock() {
        std::cout << "WallClock constructor called." << std::endl;
    }
    ~CuckooClock() {
        std::cout << "WallClock deconstructor called." << std::endl;
    }
    void cuckooSound() {
        for (size_t i = 0; i<TimeOnWatch.GetHours(); i++) {
            std:: cout<<"Co-Co ";
        }
        std:: cout << "\n" ;
    }
};

class WristWatch : public WallClock {
public:
    WristWatch() {
        std::cout << "WristClock constructor called." << std::endl;
    };
    void setData(int year, int month, int day) {
        if (year<0) throw std::invalid_argument("Year can not be less 0");
        if (month<0) throw std::invalid_argument("Month can not be less 0");
        if (day<0) throw std::invalid_argument("Day can not be less 0");
        data.year = year;
        data.month = month;
        data.day = day;
    }
    void showTime () const {
        WallClock:: showTime();
        showData();
    }
    void showData() const {
        std:: cout << data.year << "." << data.month << "." << data.day<< std::endl;
    }

private:
    class Data {
    public:
        int year = 0;
        int month = 0;
        int day = 0;
    };
    Data data;
};

#endif // CLASS_TIME_H
