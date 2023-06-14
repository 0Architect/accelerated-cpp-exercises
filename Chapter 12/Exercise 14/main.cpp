#include <iostream>
#include <string>
#include "../../Chapter 11/Exercise 06/Vec.h"

int main() {
    std::string str = "Hello, World!";
    
    Vec<char> vec(str.begin(), str.end());

    for (const auto& ch : vec) {
        std::cout << ch;
    }
    std::cout << std::endl;

    return 0;
}