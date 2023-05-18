#include <iostream>

int main()
{
    int a, b;
    std::cout << "Enter two numbers: ";
    std::cin >> a >> b;
    a == b  ? std::cout << "They are equal"
    : a > b ? std::cout << "First number is larger"
            : std::cout << "Second number is larger";
    return 0;
}