#include "math.h"
#include <iostream>

void print() // lives in global namespace
{
    std::cout << "print" << '\n';
}

namespace Baz
{
    namespace Tony
    {
        void doo()
        {
            std::cout << "baz tony doo" << '\n';
        }
    }

    void doo();

    void print()
    {
        std::cout << "in baz" << '\n';
    }

    void dos()
    {
        print();
        ::print();
    }
}

namespace Baz::Tony
{
    void blah()
    {
        std::cout << "baz tony blah" << '\n';
    }
}

// namespace test
// {
//     int doSomething()
//     {
//         return 3;
//     }
// }
//
int main()
{
    // std::cout << test::doSomething() << '\n';
    // ::print();
    namespace a = Baz::Tony;
    Baz::dos();
    Baz::doo();
    Baz::Tony::doo();
    Baz::Tony::blah();
    a::doo();
    std::cout << math::one() << '\n';
    return 0;
}

