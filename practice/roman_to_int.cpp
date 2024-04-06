#include <iostream>
#include <string>
#include <unordered_map>

namespace
{
    std::unordered_map<char, int> map {
        { 'I', 1 },
        { 'V', 5 },
        { 'X', 10 },
        { 'L', 50 },
        { 'C', 100 },
        { 'D', 500 },
        { 'M', 1000 },
    };
}

int romanToInt(std::string s)
{
    int ret { 0 };
    int size { static_cast<int>(s.size()) };
    std::cout << s << '\n';
    for (int idx { 0 }; idx < size; ++idx)
    {
        switch (s[idx])
        {
            case 'I':
                if (idx != size - 1 && (s[idx+1] == 'V' || s[idx+1] == 'X'))
                {
                    ret += (map.at(s[idx+1]) - map.at(s[idx]));
                    ++idx;
                }
                else
                    ret += map.at(s[idx]);
                break;
            case 'V':
                ret += map.at(s[idx]);
                break;
            case 'X':
                if (idx != size - 1 && (s[idx+1] == 'L' || s[idx+1] == 'C'))
                {
                    ret += (map.at(s[idx+1]) - map.at(s[idx]));
                    ++idx;
                }
                else
                    ret += map.at(s[idx]);
                break;
            case 'L':
                ret += map.at(s[idx]);
                break;
            case 'C':
                if (idx != size - 1 && (s[idx+1] == 'D' || s[idx+1] == 'M'))
                {
                    ret += (map.at(s[idx+1]) - map.at(s[idx]));
                    ++idx;
                }
                else
                    ret += map.at(s[idx]);
                break;
            case 'D':
                ret += map.at(s[idx]);
                break;
            case 'M':
                ret += map.at(s[idx]);
                break;
            default:
                throw "Invalid character";
        }
    }

    return ret;
}

int main()
{
    std::string p1 { "III" };
    std::string p2 { "LVIII" };
    std::string p3 { "MCMXCIV" };

    std::cout << romanToInt(p1) << '\n';
    std::cout << romanToInt(p2) << '\n';
    std::cout << romanToInt(p3) << '\n';

    return 0;
}
