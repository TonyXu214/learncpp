#include <iostream>
#include <string>
#include <vector>

class Foo
{
private:
    std::string m_s {};
    int m_x {};

public:
    Foo(const std::string& s, int x)
        : m_s { s }
        , m_x { x }
    {
    }

    explicit Foo(int x)
        : m_s {}
        , m_x {x}
    {
    }

    void print()
    {
        std::cout << m_s << m_x << ' ';
    }
};

template <typename T>
void printStack(const std::vector<T>& vec)
{
    if (vec.empty())
        std::cout << "Empty";

    for (auto ele : vec)
        std::cout << ele << ' ';

    std::cout << "\tCapacity: " << vec.capacity() << " Length: " << vec.size() << '\n';
}

template <typename T>
void printFoo(const std::vector<T>& vec)
{
    if (vec.empty())
        std::cout << "Empty";

    for (auto ele : vec)
        ele.print();

    std::cout << "\tCapacity: " << vec.capacity() << " Length: " << vec.size() << '\n';
}

int main()
{
    Foo f { "foo", 1 };
    f.print();
    std::cout << '\n';

    std::vector<Foo> vec_foo {};
    printFoo(vec_foo);

    vec_foo.push_back(f); // use push_back as f is created
    printFoo(vec_foo);

    vec_foo.emplace_back("bar", 2); // use emplace_back for perfect forwarding
    printFoo(vec_foo);

    vec_foo.emplace_back(3);
    printFoo(vec_foo);

    // vec_foo.emplace_back({ 4 }); // compile error Foo(int) is explicit
    // printFoo(vec_foo);

    std::vector<int> vec{};
    printStack(vec);

    vec.reserve(6); // does not change length unlike resize()
    printStack(vec);

    vec.push_back(1);
    printStack(vec);

    vec.push_back(2);
    printStack(vec);

    vec.push_back(3);
    printStack(vec);

    std::cout << "Top: " << vec.back() << '\n';
    vec.pop_back();
    printStack(vec);

    return 0;
}
