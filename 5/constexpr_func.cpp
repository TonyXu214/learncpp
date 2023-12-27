#include <iostream>
#include <type_traits>

consteval auto compile(auto val)
{
    return val;
}

constexpr char tern(int x, int y)
{
    if (std::is_constant_evaluated()) {
        return 'l';
    } else {
        return ((x > y) ? 'x' : 'y');
    }

}

int main()
{
    constexpr int x { 5 };
    constexpr int y { 6 };
    // int z { 7 };

    constexpr char greater { tern(x, y) }; // will evaluate at compile-time
    constexpr char compile_greater { compile(tern(x, y)) }; // will evaluate at compile-time
    // constexpr char greater_z { tern(x, z) }; // will not evaluate at compile-time


    std::cout << greater << '\n';
    std::cout << compile_greater << '\n';

    return 0;
}
