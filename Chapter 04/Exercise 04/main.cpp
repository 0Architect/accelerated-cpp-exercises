#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    const double maxNumber = 999;
    const double colGap = static_cast<int>(std::log(maxNumber) / std::log(10) + 4);
    for (double i = 1; i < 1000; ++i)
    {
        std::cout << i;
        double space = static_cast<int>(std::log(i * i) / std::log(10));
        space -= static_cast<int>(std::log(i) / std::log(10));
        space += colGap;
        std::cout << std::setw(static_cast<int>(space))
                  << i * i << std::endl;
    }
    return 0;
}