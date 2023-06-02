#include <iostream>
#include <vector>
#include "../../include/StudentInfo.h"

using namespace std;

bool did_all_hw(const Student_info &s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

void classify(vector<Student_info> &did, vector<Student_info> &didnt)
{
    Student_info student;
    while (read(cin, student))
    {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }
}