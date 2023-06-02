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

bool passed_optimistic_media(const Student_info &s)
{
    return optimistic_median(s) > 60;
}

bool did_all_hw(const Student_info &s)
{
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

bool fgrade(const Student_info& s)
{
 return grade(s) < 60;
}

void classify(vector<Student_info> &met_criteria, vector<Student_info> &failed_criteria, bool criteria(const Student_info&))
{
    Student_info student;
    while (read(cin, student))
    {
        if (criteria(student))
            met_criteria.push_back(student);
        else
            failed_criteria.push_back(student);
    }
}

int main()
{
    vector<Student_info> passed_extract_fails;
    vector<Student_info> failed_extract_fails;
    classify(passed_extract_fails, failed_extract_fails, fgrade);


    vector<Student_info> passed_optimistic_median;
    vector<Student_info> failed_optimistic_median;
    classify(passed_optimistic_median, failed_optimistic_median, passed_optimistic_media);


    return 0;
}