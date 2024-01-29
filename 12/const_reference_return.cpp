#include <iostream>
#include <string>

int& max(int& x, int& y)
{
    return (x > y) ? x : y;
}

// const std::string& bad_return()
// {
//     const std::string bad { "bad" };
//
//     return bad;
// }

// const std::string& bad_return2()
// {
//     const std::string bad { "bad" };
//
//     return bad;
// }

// const int& bad_int()
// {
//     return 5;
// }

const std::string& ref_return()
{
    static const std::string something { "something" };

    return something;
}

const std::string& max(const std::string& w1, const std::string& w2)
{
    return (w1 < w2) ? w1 : w2;
}

int main()
{
    std::cout << ref_return() << '\n';
    // std::cout << bad_return() << '\n'; // dangling

    // const int& bad { bad_int() }; // temporary object lifetime not extended
    // std::cout << bad << '\n';

    // std::string bad { bad_return2() }; // "bad" in bad_return2() destroyed, this is dangling
    // std::cout << bad << '\n';

    std::string tony { "Tony" };
    std::string matt { "Matt" };

    std::cout << max(tony, matt) << '\n'; // this is allowed, tony matt exist in scope of caller, not destroyed

    int x { 1 };
    int y { 2 };
    std::cout << x << y << '\n';
    max(x,y) = 0;
    std::cout << x << y << '\n';

    return 0;
}
