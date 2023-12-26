#include <iostream>
#include <string>

int main()
{
    constexpr bool big { false };
    constexpr int num { big ? 30 : 20 };

    std::cout << num << std::endl;

    std::cout << (true ? -1 : 1u) << '\n'; // surprising result: -1 converted to unsigned int, result out of range

    // std::cout << (true ? 1 : "hello") << '\n'; // compile error: compiler can't find common type for constexpr int and C-style string literal
    std::cout << (true ? std::to_string(1) : std::string {"hello"} ) << '\n'; // convert expression result types to match
    return 0;
}
