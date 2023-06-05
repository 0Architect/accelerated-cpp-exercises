#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include "../../include/StudentInfo.h"

using namespace std;

int A = 0;
int B = 0;
int C = 0;
int D = 0;
int F = 0;

char letter_grade(double grade)
{
    if (grade < 60)
    {
        F++;
        return 'F';
    }

    else if (grade < 70)
    {
        D++;
        return 'D';
    }
    else if (grade < 80)
    {
        C++;
        return 'C';
    }
    else if (grade < 90)
    {
        B++;
        return 'B';
    }
    else if (grade <= 100)
    {
        A++;
        return 'A';
    }
    else
        throw domain_error("Out of Bounds");
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
            char letter = letter_grade(final_grade);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                 << setprecision(prec) << "  "
                 << letter;
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }
    cout << "The number of A:\t" << A << endl;
    cout << "The number of B:\t" << B << endl;
    cout << "The number of C:\t" << C << endl;
    cout << "The number of D:\t" << D << endl;
    cout << "The number of F:\t" << F << endl;
    
    return 0;
}