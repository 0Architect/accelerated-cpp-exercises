#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    for(int i = 1; i < 101; ++i)
    {
        std::cout << i;
        int space = std::log(i * i) / std::log(10) + 4;
        space -= static_cast<int>(std::log(i) / std::log(10));
        std::cout << std::setw(space) << i * i << std::endl;
    }
    return 0;
}