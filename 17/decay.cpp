#include <array>
#include <iostream>

int main()
{
    int arr[5] { 1, 2, 3, 4, 5 };
    for (auto const& i : arr)
    {
        std::cout << i << '\n';
    }

    auto ptr { arr };

    std::cout << ptr << ' ' << *ptr << '\n';

    return 0;
}

