#include <cctype>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>
#include "../../utilities/StringUtils.h"
#include <vector>

bool isUppercase(const std::string& str)
{
    for (char c : str)
    {
        if (!std::isupper(c))
            return false;
    }
    return true;
}

bool isLowercase(const std::string& str)
{
    for (char c : str)
    {
        if (!std::islower(c))
            return false;
    }
    return true;
}

int main()
{
    std::string input;
    std::vector<std::string> result;
    getline(std::cin, input);
    std::vector<std::string> temp;
    Utils::string_split(input, std::back_inserter(result)) ;
    for(std::string i: result)
    {
        if(isUppercase(i))
            temp.push_back(i);
        else
            std::cout << i << " ";
    }
    for(std::string i: temp)
    {
        std::cout << i << " ";
    }
    return 0;
}