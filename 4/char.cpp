#include <iostream>

int main()
{
    char a { 'a' };
    char a_97 { 97 };

    std::cout << a << std::endl;

    std::cout << a_97 << std::endl;

    // char ch{};
    // std::cin >> ch; // ch = 'a', "bcd" is left queued.
    // std::cout << "You entered: " << ch << '\n';
    //
    // // Note: The following cin doesn't ask the user for input, it grabs queued input!
    // std::cin >> ch; // ch = 'b', "cd" is left queued.
    // std::cout << "You entered: " << ch << '\n';

    // char x {};
    // // char y {};
    //
    // std::cin >> x;
    //
    // std::cout << x;
    //
    // std::cin >> x;
    //
    // std::cout << x << std::endl;

    return 0;
}
