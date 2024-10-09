#include "module1.h"
#include "module2.h"
#include "module3.h"
#include <iostream>

using namespace std;// теперь можно использовать cout без явного указания простраснтва имен std

int main(int argc, char** argv)
{
    std::cout <<  "Hello world!" << "\n";

    cout << Module1::getMyName() << "\n";
    std::cout << Module2::getMyName() << "\n";

    using namespace Module1;
    std::cout << getMyName() << "\n"; // (A)
    /* using namespace Module1 позволяет использовать все имена, функции, классы и тд
    из Module1, без необходимости указывать его явно перед каждым именем */

    std::cout << Module2::getMyName() << "\n";


    using namespace Module2; // (B)
    std::cout << getMyName() << "\n"; // COMPILATION ERROR (C)
    /* ошибка возникает так как  вызов функции getMyName() неодназначен */

    using Module2::getMyName;
    std::cout << getMyName() << "\n"; // (D)
    /* Теперь компилятор знает о функции getMyName() из пространства имен Module2 и теперь будет использовать именно ее */


    {
        using Module3::getMyName;
        std::cout << getMyName() << "\n";
    }
}
