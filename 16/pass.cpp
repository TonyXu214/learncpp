#include <iostream>
#include <vector>

// void length(const std::vector& vec) // compile error, CTAD doesn't work with parameters
// {
// };

// std::size_t length(const std::vector<int>& vec)
// {
//     return std::size(vec);
// }

template <typename T>
std::size_t length(const std::vector<T>& vec)
{
    return std::size(vec);
}

// template <typename T>
// void print_0(const T& vec)
// {
//     std::cout << vec[0] << '\n';
// }

// In C++20, we can use an abbreviated function template (via an auto parameter) to do the same thing:
void print_0(const auto& vec)
{
    std::cout << vec[0] << '\n';
}

int main()
{
    std::vector<int> vec { 1, 2, 3 };
    std::vector vec_dbl { 1.1, 2.2, 3.3 };
    std::cout << length(vec) << '\n';
    std::cout << length(vec_dbl) << '\n';
    print_0(vec);
    print_0(vec_dbl);

    return 0;
}

