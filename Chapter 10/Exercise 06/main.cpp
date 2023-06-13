#include "../Exercise 04/String_list.h"
#include "../../utilities/StringUtils.h"
#include "../../utilities/PrintUtils.h"
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>

template <class Container>
void split(std::string input, Container& out)
{
    std::stringstream ss(input);
    std::string temp;
    while (ss >> temp)
    {
        out.push_back(temp);
    }
}

int main()
{
    String_list test;
    split("lorem ipsum lorem is an ipsum", test);
    Utils::print(test.begin(), test.end());
}