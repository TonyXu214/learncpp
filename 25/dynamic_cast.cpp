#include <iostream>
#include <string>
#include <string_view>

class Base
{
    private:
        std::string m_s {};

    public:
        Base(std::string_view s)
            : m_s { s }
        {
        }

        virtual ~Base() = default;
        // virtual std::string_view getString() const
        // {
        //     return m_s;
        // }
};

class Derived: public Base
{
    private:
        std::string m_t {};

    public:
        Derived(std::string_view s, std::string_view t)
            : Base { s }, m_t { t }
        {
        }

        std::string_view getString() const
        {
            return m_t;
        }
};

Base* getObject(bool getDerived)
{
    if (getDerived)
    {
        return new Derived { "Base1", "Derived1" };
    } else {
        return new Base { "Base2" };
    }
}

int main()
{
    Base* b { getObject(false) } ;
    Derived* d { dynamic_cast<Derived*>(b) };
    if (d)
    {
        std::cout << d->getString() << '\n';
    } else
    {
        std::cout << "Is Base" << '\n';
    }

    delete b;

    return 0;
}
