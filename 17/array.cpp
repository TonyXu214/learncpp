#include <array>
#include <iostream>
#include <vector>

int main()
{
    std::array<int, 5> arr { 5, 4, 3, 2, 1 };
    std::cout << arr[2] << '\n';
    std::vector<int> vec(5);
    [[maybe_unused]] std::array<int, 5> arr_default; // members default initialized, int elements uninitialized
    [[maybe_unused]] std::array<int, 5> arr_value {}; // members value initialized, int elements zero initialized
    constexpr std::array arr_ctad { 2, 4, 6, 8 };
    constexpr auto arr_to_array_1 { std::to_array<int, 5>({ 9, 7, 6 }) }; // type and size
    std::cout << "arr_to_array_1: " << '\n';
    for (int i : arr_to_array_1)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    constexpr auto arr_to_array_2 { std::to_array<int>({ 9, 8 }) }; // deduce size
    std::cout << "arr_to_array_2: " << '\n';
    for (int i : arr_to_array_2)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    constexpr auto arr_to_array_3 { std::to_array({ 10, 9 }) }; // deduce type and size
    std::cout << "arr_to_array_3: " << '\n';
    for (int i : arr_to_array_3)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
    std::cout << "arr_ctad: " << '\n';
    for (int i : arr_ctad)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    constexpr int len { 8 };
    [[maybe_unused]] std::array<int, len> arr_b {};

    enum Colors
    {
        red,
        max_color,
    };
    [[maybe_unused]] std::array<int, max_color> arr_c {};

    // int k { 10 };
    // [[maybe_unused]] std::array<int, k> arr_d {};

    std::cout << "arr: " << '\n';
    for (int ele : arr)
    {
        std::cout << ele << ' ';
    }
    std::cout << '\n';

    std::cout << "Vec Capacity: " << vec.capacity() << " Size: " << vec.size() << '\n';
    for (int ele : vec)
    {
        std::cout << ele << ' ';
    }
    std::cout << '\n';

    return 0;
}

