#include <iostream>
#include <array>

template <typename T, std::size_t row, std::size_t col>
using TWO_D = std::array<T, row*col>;

template <typename T, std::size_t row, std::size_t col>
using TOO_D = std::array<std::array<T, col>, row>;

template <typename T, std::size_t row, std::size_t col>
void print(TOO_D<T, row, col>& arr)
{
    for (const auto& ro : arr)
    {
        for (const auto& ele : ro)
        {
            std::cout << ele << '\n';
        }
    }
}

int main()
{
    TWO_D<int, 2, 3> two_arr {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
    };

    std::mdspan mdView { two_arr.data(), 2, 3 };
    std::size_t rows { mdView.extents().extent(0) };
    std::size_t cols { mdView.extents().extent(1) };

    std::cout << "rows: " << rows << '\n';
    std::cout << "cols: " << cols << '\n';

    TOO_D<int, 3, 5> arr {{
        { 1, 2, 3, 4, 5 },
        { 1, 2, 3, 4, 6 },
        { 1, 2, 3, 4, 7 },
    }};

    print(arr);
    std::cout << "row: " << std::size(arr) << '\n';
    std::cout << "col: " << std::size(arr[0]) << '\n';
    // const char* const str { "foo" };
    // std::cout << str << '\n';
    //
    // int arr[][5] {
    //     { 1, 2, 3, 4, 5 },
    //     { 1, 2, 3, 4, 6 },
    //     { 1, 2, 3, 4, 7 },
    // };
    //
    // for (size_t size{0}; size < std::size(arr); ++size)
    // {
    //     for (size_t ssize{0}; ssize < std::size(arr[size]); ++ssize)
    //     {
    //         std::cout << arr[size][ssize] << '\n';
    //     }
    // }
    //
    // for (const auto& row : arr)
    // {
    //     for (const auto& ele : row)
    //     {
    //         std::cout << ele << '\n';
    //     }
    // }

    return 0;
}

