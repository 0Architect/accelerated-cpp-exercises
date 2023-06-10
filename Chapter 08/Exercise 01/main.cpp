#include <vector>
#include "../../include/StudentInfo.h"

using namespace std;

template<class T>
double analysis(const vector<Student_info> &students, T func_action)
{
    vector<double> grades;
    transform(students.begin(), students.end(),
              back_inserter(grades), func_action);
    return median(grades);
}