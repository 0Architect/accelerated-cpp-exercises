#include <iostream>
#include <vector>
#include <string>
#include "ReadVector.h"

int main()
{
    std::vector<std::string> vec;
    read_vec(vec);
    std::cout << vec.size();
    return 0;
}