#include <iostream>

class Time
{
    static int counter;
    int hours, minutes, seconds = 0;

public:
    Time() {
        counter++;
        std::cout << "Constructor called. Object count: " << counter << std::endl;
    } /* конструктор по умолчанию, не принимает никаких параметров.
    Cоздает объект класса Time с неинициализированными членами hours, minutes и seconds */

    ~Time() {
        counter--;
        std::cout << "Deconstructor called. Object count: " << counter << std::endl;
    };

    Time (int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        counter++;
        std::cout << "Constructor called. Object count: " << counter << std::endl;
        Normalize();
    } // конструктор класса

    Time (const Time& t) : Time(t.hours, t.minutes, t.seconds) {
        std::cout << "Copy constructor called. Object count: " << counter << std::endl;
    } // конструктор копирования, делегирование конструкторов

    //Time&: Возвращаемый тип оператора присваивания. Возвращается ссылка на текущий объект (*this)
    Time& operator= (const Time& other) {
        this->hours = other.hours;
        this->minutes = other.minutes;
        this->seconds = other.seconds;
        return *this;
    }

    Time& operator += (int s)  {
        this->seconds += s;
        Normalize();
        return *this;
    }

    Time& operator -= (int s)  {
        this->seconds -= s;
        Normalize();
        return *this;
    }

    bool operator == (int s)  {
        if (this->ToSeconds() == s) return 1;
        return 0;
    }

    bool operator == (const Time& t)  {
        if (this->ToSeconds() == t.ToSeconds()) return 1;
        return 0;
    }


    Time operator + (int s) const { // const - оператор не изменяет состояние текущего объекта
        return Time(hours, minutes, seconds + s);
    }

    Time operator - (int s) const {
        return Time(hours, minutes, seconds - s);
    }

    // методы доступа для членов класса 'Time'.
    // ключевое слово 'const' указывает на то, что метод не изменяет состояние объекта
    int GetHours() const { return hours; };
    int GetMinutes() const { return minutes; };
    int GetSeconds() const { return seconds; };

    // сеттеры
    void SetHours(int h) {
        hours = h;
        if(hours > 24) Normalize();

    } ;
    void SetMinutes(int m) {
        minutes = m;
        if(minutes > 59) Normalize();

    };
    void SetSeconds(int s) {
        seconds = s;
        if(seconds > 59) Normalize();
    };

    void PrintTime () {
        std:: cout << "H:" << this->GetHours() << " M:" << this->GetMinutes() << " S:" << this->GetSeconds() << std::endl;
    }

    void Normalize() {
        int totalSec = this->ToSeconds();

        if (totalSec < 0){
            this->SetHours(0);
            this->SetMinutes(0);
            this->SetSeconds(0);
        }
        else{
            int h = totalSec / 3600 % 24;
            totalSec -= 3600*(totalSec / 3600);
            int m = totalSec / 60 % 60;
            totalSec-= 60*(totalSec / 60);
            int s = totalSec;

            this->SetHours(h);
            this->SetMinutes(m);
            this->SetSeconds(s);
        }

    }

    int ToSeconds() const {
        int totalSec = 0;
        totalSec += this->GetSeconds();
        totalSec += this->GetMinutes() * 60;
        totalSec += this->GetHours() * 60 * 60;
        return totalSec;
    }

    friend std::ostream& operator << (std::ostream& out, const Time& t) {
        out<< t.GetHours() << ":" << t.GetMinutes() << ":" << t.GetSeconds() << std::endl;
        return out;
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


};

int Time:: counter = 0;

int main() {
    Time t;
    t.SetHours(1);
    Time t2 = t;
    t2.SetHours(2);
    t2.PrintTime();
    {
        t2.SetHours(12);
        t2.PrintTime();
        Time t2(22,22,22);
        t2.PrintTime();
    }
    t2.PrintTime();
    Time t3(3,3,3);
    t3 = t;
    t3.SetHours(3);
    t3.PrintTime();

}


