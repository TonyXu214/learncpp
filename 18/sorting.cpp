#include <algorithm>
#include <iostream>
#include <utility>

int main()
{
    int x { 4 };
    int y { 6 };
    std::cout << "x: " << x << " y: " << y << '\n';

    std::swap(x, y);
    std::cout << "x: " << x << " y: " << y << '\n';

    int arr[] { 5, 4, 3, 2, 1 };
    for (const auto& i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::sort(std::begin(arr), std::end(arr));
    for (const auto& i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

