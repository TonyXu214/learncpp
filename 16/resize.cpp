#include <iostream>
#include <vector>

template <typename T>
void print_vec(const std::vector<T>& v)
{
    std::cout << "Capacity: " << v.capacity() << "  Length: " << v.size() << '\n';
    for (auto i : v)
    {
        std::cout << i;
    }
    std::cout << '\n';
}

int main()
{
    std::vector v { 0, 1, 2 };
    print_vec(v);
    v.resize(5);
    print_vec(v);
    v.resize(2); // does not reallocate memory
    v.shrink_to_fit();
    print_vec(v);
    v.resize(6); // does not reallocate memory
    print_vec(v);

    return 0;
}
