#include <iostream>

template <typename T, int size>
class Foo
{
private:
    T m_arr[size] {};

public:
    T* getArray();

    T& operator[](int idx)
    {
        return m_arr[idx];
    }
};

template <typename T, int size>
T* Foo<T, size>::getArray()
{
    return m_arr;
}

int main()
{
    Foo<int, 4> f {};
    for (int i { 4 }; i > 0; --i)
    {
        f[i] = i;
    }

    for (int i { 4 }; i > 0; --i)
    {
        std::cout << f[i] << '\n';
    }

    Foo<double, 5> d {};
    for (double i { 5.0 }; i > 0; --i)
    {
        d[i] = i;
    }

    for (int i { 5 }; i > 0; --i)
    {
        std::cout << d[i] << '\n';
    }

    return 0;
}

