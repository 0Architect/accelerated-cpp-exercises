#include <iostream>
#include <iomanip>
#include <string>
#include <ios>

// Division by 0 causes the terminal to close without any warning
// (on my implementation). If the value is used for computation,
// it results in nan

int main()
{
    std::string name;
    double final_grade, midterm, homework_temp, sum = 0;
    int count = 0;

    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Hello, " << name << "!" << std::endl;

    std::cout << "Enter the final grade: ";
    std::cin >> final_grade;

    std::cout << "Enter the midterm result: ";
    std::cin >> midterm;

    std::cout << "Enter your homework grades: ";
    while (std::cin >> homework_temp)
    {
        sum += homework_temp;
        ++count;
    }

    std::streamsize prec = std::cout.precision(4);
    std::cout << "Your final grade is: " << 0.2 * midterm + 0.4 * final_grade + 0.4 * sum / (count ? count : 1) << std::setprecision(prec);

    return 0;
}