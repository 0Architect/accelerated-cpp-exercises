#include <iostream>
#include <vector>
#include <string>
#include "ReadVector.h"
#include <algorithm>

int main()
{
    std::vector<std::string> vec;
    read_vec(vec);
    std::sort(vec.begin(), vec.end());
    std::string temp = vec[0];
    std::string::size_type count = 0;
    for (std::string word : vec)
    {
        if (word != temp)
        {
            std::cout << temp << "\t" << count << std::endl;
            count = 1;
            temp = word;
        }
        else
            ++count;
    }
    std::cout << temp << "\t" << count << std::endl;
    return 0;
}