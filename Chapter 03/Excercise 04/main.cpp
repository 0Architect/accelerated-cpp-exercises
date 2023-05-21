#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string input;
    std::string smallest;
    std::cout << "Enter your input: "
                 "(To end place an end of file marker -ctrl+z on windows)"
              << std::endl;
    std::cin >> smallest;
    std::string largest = smallest;
    std::vector<std::string> word;
    while (std::cin >> input)
    {
        smallest = input.size() < smallest.size() ? input : smallest; 
        largest = input.size() > largest.size() ? input : largest; 
    }
    std::cout << "Smallest string: " << smallest << std::endl;
    std::cout << "Largest string: " << largest << std::endl;
    
    return 0;
}