#include <cstdint>
#include <cstddef>
#include <iostream>

int main()
{
    std::int16_t x{};
    std::int32_t y{};

    std::cout << sizeof(x) << std::endl;
    std::cout << sizeof(y) << std::endl;

    std::cout << "least 8:  " << sizeof(std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  " << sizeof(std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof(std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof(std::int_fast32_t) * 8 << " bits\n";
	std::cout << "std::size_t: " << sizeof(std::size_t) * 8 << " bits\n";

    return 0;
}
