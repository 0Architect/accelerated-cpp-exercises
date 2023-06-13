#include <string>
#include <vector>
#include "../../include/StudentInfo.h"
#include <algorithm>
#include <iomanip>

using namespace std;

string letterGrade(double score)
{
    static const double numbers[] = {
        97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0};

    static const char *const letters[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"};

    static const size_t ngrades = sizeof(numbers) / sizeof(*numbers);

    for (size_t i = 0; i < ngrades; ++i)
    {
        if (score >= numbers[i])
            return letters[i];
    }
    return "?\?\?";
}

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record))
    {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');
        try
        {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << letterGrade(final_grade)
                 << endl;
        }
        catch (domain_error e)
        {
            cout << e.what() << endl;
        }
    }
    return 0;
}