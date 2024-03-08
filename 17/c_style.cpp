#include <iostream>

int main()
{
    int foo[] { 1, 2 };
    for (const auto& i : foo)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    std::cout << sizeof(foo) << '\n';
    std::cout << std::size(foo) << '\n';
    std::cout << std::ssize(foo) << '\n';

    return 0;
}
