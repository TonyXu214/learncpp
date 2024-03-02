#include <iostream>
#include <vector>
#include <ranges>

int main()
{
    std::vector<int> vec { 1, 2, 3, 4 };

    for (const auto& i : vec)
    {
        std::cout << i << '\n';
    }

    for (const auto& i : std::views::reverse(vec))
    {
        std::cout << i << '\n';
    }

    return 0;
}

