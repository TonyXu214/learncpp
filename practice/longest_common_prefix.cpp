#include <array>
#include <iostream>
#include <string>

template <typename T, std::size_t N>
std::string longest_common_substring(const std::array<T, N>& arr)
{
    std::string ret { "" };
    bool isEqual { true };
    int idx { 0 };

    while (isEqual)
    {
        try
        {
            char c { std::get<0>(arr).at(idx) };

            for (auto i { 0 }; i < std::ssize(arr); ++i)
            {
                if (c != arr.at(i).at(idx))
                {
                    isEqual = false;
                }
            }

            if (isEqual)
            {
                ret.append(1, c);
            }
            ++idx;

        }
        catch(std::out_of_range const& exc)
        {
            isEqual = false;
        }
    }

    return ret;
}

int main()
{
    std::array<std::string, 3> p1 { { "flower","flow","flight" } };
    std::array<std::string, 3> p2 { { "dog","racecar","car" } };

    std::cout << longest_common_substring(p1) << '\n';
    std::cout << longest_common_substring(p2) << '\n';

    return 0;
}
