#include <iostream>
#include <iomanip>
#include <cmath>

//If we neglect to change the arguments to setw() as it grows, our output becomes misaligned and wrongly formatted.


int main()
{
    const int maxNumber = 999;
    const int colGap = std::log(maxNumber) / std::log(10) + 4;
    for(int i = 1; i < 1000; ++i)
    {
        std::cout << i;
        int space = std::log(i * i) / std::log(10);
        space -= static_cast<int>(std::log(i) / std::log(10));
        space += colGap;
        std::cout << std::setw(space) << i * i << std::endl;
    }
    return 0;
}