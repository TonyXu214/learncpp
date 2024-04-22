#!/usr/bin/env python3

def strStr(haystack: str, needle: str):
    idx = 0
    needleIdx = 0

    while (idx < len(haystack)):
        if (haystack[idx] == needle[needleIdx]):
            needleIdx += 1
        else:
            idx -= needleIdx
            needleIdx = 0

        if (needleIdx == len(needle)):
            return idx - (needleIdx - 1)

        idx += 1

    return -1

def main():
    print(strStr('sadbutsad', 'sad'))
    print(strStr('leetcode', 'leeco'))
    print(strStr('mississippi', 'issip'))

if __name__ == '__main__':
    main()
