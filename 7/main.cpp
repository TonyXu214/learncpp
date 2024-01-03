#include "math.h"
#include <iostream>

void print() // lives in global namespace
{
    std::cout << "print" << '\n';
}

namespace Baz
{
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
    Baz::dos();
    std::cout << math::one() << '\n';
    return 0;
}

