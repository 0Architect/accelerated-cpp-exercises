#ifndef READ_VECTOR_H
#define READ_VECTOR_H

#include <vector>
#include <string>
#include <iostream>

void read_vec(std::vector<std::string>& vec)
{
    std::string temp;
    while(std::cin >> temp)
        vec.push_back(temp);
}

#endif