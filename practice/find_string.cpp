#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle) {
    int idx { 0 };
    int needleIdx { 0 };


    while (idx < haystack.size())
    {
        if (haystack[idx] == needle[needleIdx])
        {
            needleIdx += 1;
        } else
        {
            idx -= needleIdx;
            needleIdx = 0;
        }

        if (needleIdx == needle.size())
        {
            return idx - (needleIdx - 1);
        }

        idx += 1;
    }

    return -1;
}

int main()
{
    std::cout << strStr("sadbutsad", "sad") << '\n';
    std::cout << strStr("leetcode", "leeto") << '\n';
    std::cout << strStr("mississippi", "issip") << '\n';

    return 0;
}

