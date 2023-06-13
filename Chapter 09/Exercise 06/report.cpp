#include "main.h"
#include <iostream>
#include <vector>
#include <algorithm>

StudentCredit convertToStudentCredit(const Student_info &s)
{
    return StudentCredit(s);
}

bool failurePredicate(const StudentCredit& s)
{
    return s.grade() == 'P';
}

int main()
{
    std::vector<Student_info> students;
    std::vector<StudentCredit> creditStudents(students.size());
    Student_info record;

    while (read(std::cin, record))
        students.push_back(record);

    std::transform(students.begin(), students.end(),
                   creditStudents,
                   convertToStudentCredit);
    
    std::stable_partition(creditStudents.begin(), creditStudents.end(), failurePredicate);

    for (auto i : creditStudents)
        std::cout << i.name() << '\t' << i.grade() << std::endl;

    return 0;
}