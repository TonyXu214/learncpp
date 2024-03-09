#include <iostream>

void print_arr(int* begin, int* end)
{
    for (; begin != end; ++begin)
    {
        std::cout << *begin << '\n';
    }
}

int main()
{
    int x {};
    auto addr { &x };

    int arr[] { 1, 2, 3 };
    int* begin { arr };
    int* end { arr + std::size(arr) };
    print_arr(begin, end);

    int* ptr { arr };

    std::cout << *ptr << '\n';
    ptr = &arr[1];
    std::cout << *(ptr + 1) << '\n';

    std::cout << arr << ' ' << arr + 1 << ' ' << arr + 2 << '\n';
    std::cout << *arr << ' ' << *(arr + 1) << ' ' << *(arr + 2) << '\n';

    std::cout << addr << ' ' << addr + 1 << '\n';

    return 0;
}

