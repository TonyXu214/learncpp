#include <iostream>

enum Pet: int
{
    cat,
    dog,
};

enum Pet1
{
    cat1,
    dog1,
};

namespace Test
{
    enum Test
    {
        red,
        green,
    };
}

namespace Test1
{
    enum Test1
    {
        red,
        green,
    };
}

std::ostream& operator<<(std::ostream& out, Test::Test test)
{
    switch (test)
    {
    case (Test::red):   return out << "red";
    case (Test::green): return out << "green";
    default:            return out << "???";
    }
}

int main()
{
    Test::Test t { Test::red };
    Test1::Test1 t1 { Test1::red };

    Pet1 pet1 { static_cast<Pet1>(1) };
    std::cout << pet1 << '\n';
    Pet pet { 1 };

    std::cout << pet << '\n';

    std::cout << t << t1 << '\n';

    int input {};
    std::cin >> input;

    Pet1 pet12 {static_cast<Pet1>(input)};
    std::cout << pet12 << '\n';
    return 0;
}

