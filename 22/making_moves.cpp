#include <iostream>
#include <memory>
#include <utility>

class Foo
{
public:
    Foo()
    {
        std::cout << "Created!" << '\n';
    }

    ~Foo()
    {
        std::cout << "Destroyed" << '\n';
    }
};

int main()
{
    std::unique_ptr<Foo> f { new Foo() };
    auto g { std::make_unique<Foo>() }; // nullptr

    std::cout << "f is " << (f ? "not null" : "null") << '\n';
    std::cout << "g is " << (g ? "not null" : "null") << '\n';

    g = std::move(f);
    std::cout << "f is " << (f ? "not null" : "null") << '\n';
    std::cout << "g is " << (g ? "not null" : "null") << '\n';

    auto ptr1 { std::make_shared<Foo>() };

    {
        auto ptr2 { ptr1 };
        std::cout << "killing ptr2" << '\n';
    }

    std::cout << "killing ptr1" << '\n';

    std::weak_ptr weak { ptr1 };
    std::cout << std::boolalpha;
    std::cout << weak.expired() << '\n';
    std::shared_ptr shared { weak.lock() };

    return 0;
}

