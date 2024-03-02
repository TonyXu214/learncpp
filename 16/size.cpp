#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec { 1, 2, 3, 4, 5 };
    std::cout << vec[0] << '\n'; // 0 is converted from int to size_t
    int idx { 0 };
    constexpr int constexpr_idx { 0 };
    std::size_t size_t_idx { 2 };
    std::cout << vec[idx] << '\n'; // possible warning
    std::cout << vec[constexpr_idx] << '\n'; // okay
    std::cout << vec[size_t_idx] << '\n'; // best solution
    std::cout << vec.size() << '\n';
    std::cout << std::size(vec) << '\n';
    int vec_size { static_cast<int>(std::size(vec)) }; // cast size_type (unsigned) to int (signed)
    std::cout << vec_size << '\n';
    int vec_size2 { static_cast<int>(std::ssize(vec)) };
    std::cout << vec_size2 << '\n';
    std::cout << vec.at(0) << '\n';
    // std::cout << vec.at(5) << '\n'; // runtime error
    return 0;
}
