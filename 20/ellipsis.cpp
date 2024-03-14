#include <iostream>
#include <cstdarg>

int add(int count, ...)
{
    int sum { 0 };
    std::va_list list;

    // We initialize the va_list using va_start.  The first argument is
    // the list to initialize.  The second argument is the last non-ellipsis
    // parameter.
    va_start(list, count);

    for (int x { 0 }; x < count; ++x)
    {
        sum += va_arg(list, int);
    }

    va_end(list);

    return sum;
}

int main()
{
    std::cout << add(3, 1, 5, 7) << '\n';
    return 0;
}
