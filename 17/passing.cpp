#include <array>
#include <iostream>

template<typename T, auto N>
void populate_arr(std::array<T, N>& arr)
{
    for (int i { 0 }; i < N; ++i)
    {
        arr[i] = i;
    }
}

template<typename T, auto N>
std::array<T, N> ret_arr()
{
    std::array<T, N> arr { 1, 2, 3 };
    return arr;
}

// T is standard type template parameter
// N is non-type template parameter, can use std::size_t or auto
template<typename T, auto N>
void print_array(const std::array<T, N>& arr)
{
    static_assert (N > 3);
    std::cout << std::get<3>(arr) << '\n';
    // static_assert (N > 6); // fails compile
    // std::cout << std::get<6>(arr) << '\n'; // fails compile
    for (int i : arr)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::array<int, 5> arr { 1, 2, 3, 4, 5 };
    print_array(arr);

    std::array<int, 5> arr_2 { ret_arr<int, 5>() };
    for (int i : arr_2)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::array<int, 10> arr_3 {};
    for (int i : arr_3)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    populate_arr(arr_3);
    for (int i : arr_3)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}

