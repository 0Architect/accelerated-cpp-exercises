#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include "../../include/StudentInfo.h"
#include "../../utilities/PerformaceUtils.h"

using std::list;
using std::vector;

bool fgrade(const Student_info &s)
{
    return grade(s) < 60;
}

// typedef vector<Student_info> container;
typedef list<Student_info> container;

container extract_fails(container &students)
{
    container fail;
    container::iterator iter = students.begin();
    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
            ++iter;
    }
    return fail;
}

int main()
{
    container students;
    Student_info record;

    std::ifstream file("test_1000.txt");

    if (file.is_open())
    {
        std::streambuf *origCinBuffer = std::cin.rdbuf();
        std::cin.rdbuf(file.rdbuf());
        while (read(std::cin, record))
        {
            students.push_back(record);
        }
        std::cin.rdbuf(origCinBuffer);
        file.close();
    }
    
    else
    {
        std::cout << "failed to open the file.";
    }
    container failures = extract_fails(students);
    for(auto i: failures)
    {
        std::cout << i.name << " " << grade(i) << std::endl;
    }
}