#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc <= 1)
    {
        std::cout << argv[0] << '\n';
    }

    std::stringstream extract { argv[1] };
    int convert {};

    if (!(extract >> convert))
    {
        convert = 1;
    }

    std::cout << convert << '\n';

    return 0;
}

