#include <iostream>

#ifndef PAIR
#define PAIR

template <typename T>
struct Pair
{
    T first {};
    T second {};
};

template <typename T>
void printPair(Pair<T> p)
{
    std::cout << p.first << p.second << '\n';
}

#endif
