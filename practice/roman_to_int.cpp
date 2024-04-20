#include <iostream>
#include <string>
#include <unordered_map>
#include <optional>

namespace
{
    std::unordered_map<char, int> romanToIntMap {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 },
    };
}

std::optional<int> romanToInt(const std::string& s)
{
    int ret { 0 };
    for (auto idx { 0 }; idx < std::ssize(s); ++idx)
    {
        auto it { romanToIntMap.find(s[idx]) };
        if (it == romanToIntMap.end())
            return std::nullopt;

        int value { it->second };
        if (idx + 1 < std::ssize(s))
        {
            auto nextIt { romanToIntMap.find(s[idx+1]) };
            if (nextIt != romanToIntMap.end() && nextIt->second > value)
            {
                value = nextIt->second - value;
                ++idx;
            } else {
                return std::nullopt;
            }
        }

        ret += value;
    }

    return ret;
}

int main()
{
    std::string p1 { "III" };
    std::string p2 { "LVIII" };
    std::string p3 { "MCMXCIV" };

    std::cout << romanToInt(p1).value() << '\n';
    std::cout << romanToInt(p2).value() << '\n';
    std::cout << romanToInt(p3).value() << '\n';

    return 0;
}
