#include <iostream>

std::string* foo_star();
const char& fooc();
std::string& foos()
const int foo()
{
    return 5;
}

int main()
{
    auto x { foo() }; // int, const dropped
    const auto y { foo() }; // const int, const reapplied
    auto z { foos() }; // std::string, ref dropped
    auto& c { fooc() }; // const char&, as low level const not dropped

    auto star { foo_star() }; // std::string*
    auto* star { foo_star() }; // std::string*

    return 0;
}

