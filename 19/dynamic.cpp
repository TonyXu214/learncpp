#include <iostream>

int main()
{
    int* ptr { new (std::nothrow) int }; // value will be set to nullptr if the integer allocation fails
    if (!ptr) // handle case where new returned null
    {
        std::cerr << "Could not allocate memory\n";
    }

    *ptr = 8;
    std::cout << ptr << ' ' << *ptr << '\n';

    int* ptr_2 { new int { 5 } };
    std::cout << *ptr_2 << '\n';

    delete ptr;
    ptr = nullptr;
    delete ptr_2;
    ptr_2 = nullptr;

    int* array { new int[5] { 1, 2, 3, 4, 5 } };
    array[0] = 10;
    std::cout << array[0] << '\n';

    delete[] array;

    return 0;
}
