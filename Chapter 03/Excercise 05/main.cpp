#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void read_student(std::vector<double> &grades, std::vector<std::string> &names)
{
    std::string name;
    double final_grade, midterm, homework_score, median;
    std::vector<double>::size_type mid;
    std::vector<double> homework;

    std::cout << "Enter name of student: ";
    std::cin >> name;

    std::cout << "Enter student's final: ";
    std::cin >> final_grade;

    std::cout << "Enter student's midterm: ";
    std::cin >> midterm;

    std::cout << "Enter student's homework scores. "
                 "To stop input enter the EOF marker (ctrl+z on windows): ";
    while (std::cin >> homework_score)
        homework.push_back(homework_score);

    std::cin.clear();

    std::sort(homework.begin(), homework.end());
    mid = homework.size() / 2;
    median = homework.size() % 2 ? homework[mid] : (homework[mid] + homework[mid - 1]) / 2;

    names.push_back(name);
    grades.push_back(0.4 * final_grade + 0.2 * midterm + 0.4 * median);
}

int main()
{
    std::vector<double> grades;
    std::vector<std::string> names;
    char new_student;

    do
    {
        read_student(grades, names);
        std::cout << std::endl
                  << "To stop hit EOF marker, else any other key: ";
    } while (std::cin >> new_student);
    return 0;
}