#include <cstdlib>
#include <iostream>

void cleanup()
{
    std::cout << "cleanup\n";
}

int main()
{
    // std::atexit(cleanup);

    std::cout << 1 << '\n';
    std::abort();
    // std::exit(0); // terminate and return status code 0 to os

    // the following never executes
    std::cout << 2 << '\n';

    return 0;
}
