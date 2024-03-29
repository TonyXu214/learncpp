#include <iostream>

class IInterface
{
public:
    virtual void print() const = 0;
    virtual ~IInterface() {} // make virtual destructor in case we delete IInterface pointer, so the proper derived destructor is called
};

class Base : public IInterface
{
protected:
    int m_x {};
    Base(int x) : m_x { x }
    {
    }

public:
    // a pure virtual function
    // virtual void print() const = 0;
    virtual ~Base() = default;
};

// void Base::print() const
// {
//     std::cout << "From base: " << m_x << '\n';
// }

class Derived : public Base
{
public:
    Derived(int x) : Base(x)
    {
    }

    // commenting this function makes Derived an abtract class
    virtual void print() const override final
    {
        // Base::print();
        std::cout << "From Derived: " << m_x << '\n';
    }
};

int main()
{
    Derived d { 5 };
    d.print();

    return 0;
}
