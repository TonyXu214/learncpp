#include <array>
#include <functional>
#include <iostream>

int main()
{
    // std::array<int&, 5> arr {}; // compile error
    int x { 1 };
    int y { 2 };
    int z { 3 };
    std::array<std::reference_wrapper<int>, 3> arr {{ x, y , z }};
    for (const auto& i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    arr[1].get() = 5;
    for (const auto& i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}
