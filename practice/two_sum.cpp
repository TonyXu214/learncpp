#include "timer.hpp"

#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> vec)
{
    for (T ele : vec)
    {
        s << ele << ' ';
    }
    s << '\n';

    return s;
}

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int, std::size_t> seen {};

    for (std::size_t idx { 0 }; idx < nums.size(); ++idx)
    {
        auto match_target { target - nums.at(idx) };
        auto matched_ele { seen.find(match_target) };
        if (matched_ele != seen.end())
            return { static_cast<int>(matched_ele->second), static_cast<int>(idx) };
        seen.try_emplace(nums.at(idx), idx);
    }

    return {};
}

int main()
{
    Timer t;
    std::vector<double> times {};
    std::vector v1 { 2, 7, 11, 15 };
    std::vector v2 { 3, 2, 4 };
    std::vector v3 { 3, 3 };

    for (int i { 0 }; i < 10; ++i)
    {
        std::cout << twoSum(v1, 9) << '\n';
        std::cout << twoSum(v2, 6) << '\n';
        std::cout << twoSum(v3, 6) << '\n';

        times.emplace_back(t.elapsed());
        t.reset();
    }

    for (double ele : times)
    {
        std::cout << ele << '\n';
    }

    return 0;
}

