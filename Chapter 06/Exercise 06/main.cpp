#include <iostream>
#include <vector>
#include "../../include/StudentInfo.h"

using namespace std;

double analysis(const vector<Student_info> &students, double func_action(const Student_info))
{
    vector<double> grades;
    transform(students.begin(), students.end(),
              back_inserter(grades), func_action);
    return median(grades);
}

int main()
{
    return 0;
}