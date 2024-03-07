#include <array>
#include <iostream>

struct Hawse
{
    int address {};
    int feet {};
};

int main()
{
    std::array<Hawse, 5> hawse_arr {};
    hawse_arr[0] = { 7, 8 };

    for (const auto& i : hawse_arr)
    {
        std::cout << i.address << i.feet << ' ';
    }
    std::cout << '\n';

    std::array<Hawse, 2> hawse_arr_2 { Hawse { 2, 4 }, Hawse { 3, 5 } };
    for (const auto& i : hawse_arr_2)
    {
        std::cout << i.address << i.feet << ' ';
    }
    std::cout << '\n';

    // does not work, C style struct like
    // T implementation_defined_name[N]
    // std::array<Hawse, 2> hawse_arr_3 { { 3, 4 }, { 4, 5 } };
    // for (const auto& i : hawse_arr_3)
    // {
    //     std::cout << i.address << i.feet << ' ';
    // }
    // std::cout << '\n';

    std::array<Hawse, 2> hawse_arr_3 {{ { 3, 4 }, { 4, 5 } }};
    for (const auto& i : hawse_arr_3)
    {
        std::cout << i.address << i.feet << ' ';
    }
    std::cout << '\n';
    return 0;
}
