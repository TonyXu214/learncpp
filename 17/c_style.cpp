#include <iostream>
#include <iterator>
#include <cstring>

int main()
{
    char rolls[255] {};
    std::cout << "Enter rolls: ";
    std::cin.getline(rolls, std::size(rolls));
    std::cout << rolls << ' ' << std::strlen(rolls) << '\n';
    char str[] { "foo" };
    std::cout << str << '\n';

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
