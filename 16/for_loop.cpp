#include <iostream>
#include <type_traits>
#include <vector>
#include <ranges>

enum class StudentNames
{
    tony,
    matt,
    ping,
    max
};

// Overload the unary + operator to convert StudentNames to the underlying type
constexpr auto operator+(StudentNames a) noexcept
{
    return static_cast<std::underlying_type_t<StudentNames>>(a);
}

namespace Students
{
    enum Names : unsigned int
    {
        tony,
        matt,
        ping,
        max, // count enumerator
    };
}

int main()
{
    std::vector<int> vec { 1, 2, 3, 4 };
    std::vector<int> vec_names (Students::max);
    assert(std::size(vec_names) == Students::max);
    std::vector <int> vec_class (+StudentNames::max);

    std::cout << vec_names[Students::tony] << '\n';

    for (const auto& i : vec)
    {
        std::cout << i << '\n';
    }

    for (const auto& i : std::views::reverse(vec))
    {
        std::cout << i << '\n';
    }

    std::cout << vec[Students::tony] << '\n';

    return 0;
}

