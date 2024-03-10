#include <array>
#include <iostream>

int main()
{
    std::array arr { 1, 2, 3, 4 };
    auto begin { arr.begin() };
    auto end { arr.end () };

    for (; begin != end; ++begin)
    {
        std::cout << begin << ' ' << *begin << '\n';
    }

    return 0;
}

