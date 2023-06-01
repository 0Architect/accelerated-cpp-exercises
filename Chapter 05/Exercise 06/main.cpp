#include <vector>
#include <string>
#include "../../include/StudentInfo.h"
#include <algorithm>

typedef std::vector<Student_info> container;

bool fgrade(const Student_info &s)
{
    return grade(s) < 60;
}

void extract_fails(container &students)
{
    container::iterator iter = students.begin();
    container::iterator success_iter = students.begin();
    container::size_type count = 0;
    while (iter != students.end())
    {
        if (fgrade(*iter))
        {
            std::swap(iter, success_iter);
            ++success_iter;
            ++count;
        }
        else 
            ++iter;
    }
    students.resize(count);
}