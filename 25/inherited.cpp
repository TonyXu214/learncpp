#include <iostream>

class Base
{
    private:
        [[maybe_unused]] int m_x {};

    public:
        Base(int x) : m_x { x }
        {
        }

        friend std::ostream& operator<<(std::ostream& s, const Base& b);

        virtual std::string_view identify() const
        {
            return "Base";
        }
};

class Derived : public Base
{
    private:
        [[maybe_unused]] int m_y {};

    public:
        Derived(int y)
            : Base { 5 }
            , m_y { y }
        {
        }

        virtual std::string_view identify() const
        {
            return "Derived";
        }
};

std::ostream& operator<<(std::ostream& s, const Base& b)
{
    s << b.identify() << '\n';

    return s;
}

int main()
{
    Derived d { 5 };
    Base b { 10 };

    std::cout << d;
    std::cout << b;

    return 0;
}

