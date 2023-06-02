#include <iostream>
#include <vector>
#include "../../include/StudentInfo.h"

using namespace std;

double optimistic_median(const Student_info &s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(),
                back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info> &students)
{
    vector<double> grades;
    transform(students.begin(), students.end(),
              back_inserter(grades), optimistic_median);
    return median(grades);
}

int main()
{
    return 0;
}