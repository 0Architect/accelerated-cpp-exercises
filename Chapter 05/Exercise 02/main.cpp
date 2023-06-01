#include "../../include\StudentInfo.h"
#include "../../utilities/PerformaceUtils.h"
#include "../../utilities/PerformaceUtils.h"
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include <thread>

using std::cin;
using std::cout;
using std::list;
using std::string;
using std::vector;

bool fgrade(const Student_info &s)
{
    return grade(s) < 60;
}

vector<Student_info> extract_fails(vector<Student_info> &students)
{
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();
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

list<Student_info> extract_fails(list<Student_info> &students)
{
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();
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
    vector<Student_info> vec_students;
    list<Student_info> list_students;
    Student_info record;

    std::ifstream file("test_10000.txt");

    if (file.is_open())
    {
        std::streambuf *origCinBuffer = cin.rdbuf();
        cin.rdbuf(file.rdbuf());
        while (read(cin, record))
        {
            vec_students.push_back(record);
            list_students.push_back(record);
        }
        cin.rdbuf(origCinBuffer);
        file.close();

        cout << "List time: "
             << Utils::time_taken([](std::list<Student_info> &students)
                                  { extract_fails(students); },
                                  list_students)
             << " milliseconds" << std::endl;

        cout << "Vector time: "
             << Utils::time_taken([](std::vector<Student_info> &students)
                                  { extract_fails(students); },
                                  vec_students)
             << " milliseconds";
    }

    else
    {
        cout << "failed to open the file.";
    }

    return 0;
}