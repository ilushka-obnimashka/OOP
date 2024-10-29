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
    // Задание 6:
    // a)Дополнительно создать объекты класса Time  в динамической памяти (как один экземпляр, так и массив небольшого размера).
    std:: cout << GREEN << "creating one object in dynamic memory:\n" << RESET;
    {
        Time* t = new Time(10,22,34);
        /*конструктор класса будет вызван.
        деструктор класса не будет вызван автоматически , т.к.
        деструкторы автоматически вызываются только для  объектов созданных на стеке.
        объекты созданные динамически нужно принудительно удалять delete#1#
        delete t;*/
    }
    std:: cout << GREEN << "creating array in dynamic memory:\n" << RESET;
    auto size = 10;

    {
        Time* t = new Time[size];
        /*вызовется size конструкторов.
        деструктор класса не будет вызван автоматически т.к. деструкторы автоматически вызываются для  объектов созданных на стеке.
        объекты созданные динамически нужно принудительно удалять delete.#1#
        delete[] t;*/
    }



    std:: cout << GREEN << "creating vector<Time> with Defolt Constructor:\n" << RESET;
    // б) Создать стандартные контейнеры (vector, list и т.д.), содержащие объекты типа Time.
    {
        std:: vector<Time> t(size);
        /*вызовется size конструкторов.
        деструктор класса будет вызван автоматически т.к. деструкторы автоматически вызываются  для  объектов являющихся элементами контейнеров.
        */
    }
    std:: cout << GREEN << "creating vector<Time>with Copy Constructor:\n" << RESET;
    {
        std:: vector<Time> t = {Time(1,2,3), Time(4,5,6)};
        /*вызовется 2 конструктора для временных объектов.
        вызовется 2 конструктора создания копированием, для копирования в элементы вектора временных объектов.
        деструктор класса будет вызван автоматически
        т.к. деструкторы автоматически вызываются  для  объектов являющихся элементами контейнеров и временных объектов.
        */
    }

    std:: cout << GREEN << "creating list<Time>with Copy Constructor:\n" << RESET;
    {
        std:: list<Time> t = {Time(1,2,3), Time(4,5,6)};
        /*
         вызовется 2 конструктора для временных объектов.
        вызовется 2 конструктора создания копированием, для копирования в элементы вектора временных объектов
        деструктор класса будет вызван автоматически
        т.к. деструкторы автоматически вызываются  для  объектов являющихся элементами контейнеров и временных объектов.
        */
    }

    std:: cout << GREEN << "creating unique_ptr:\n" << RESET;
    // в)Создать умные указатели (shared и unique) на объекты класса Time.
    {
        std:: unique_ptr<Time> t1(new Time (10,11,12));
        //auto t2(t1); - не скомпилируется, так как t1 - единственный владелец ресурса
        // копирование запрещено!

        auto t2 = move(t1); // если хотим, чтобы t2 стал владельцем ресурса
        // auto t2.swap(t1);

        // вызовется один конструктор создания временного объекта
        // автоматически вызовется деструкторы для Time и unique_ptr
    }
    std:: cout << GREEN << "creating shared_ptr:\n" << RESET;
    {
        std:: shared_ptr<Time> t1(new Time(10,11,12));
        // t1  -
        auto t2 = t1;// копирование разрешено
        // теперь t1,t2 разделяю владение одним и тем де объектом динамической памяти
        t1.reset();
        // t2 - все еще указывает на временный объект
        // будет вызван один раз констурктор для временного объекта класса Time
        // все деструкторы будут вызваны автоматически

    }

}
