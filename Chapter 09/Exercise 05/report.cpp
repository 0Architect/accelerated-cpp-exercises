#include "main.h"
#include <iostream>
#include <vector>
#include <algorithm>

StudentCredit convertToStudentCredit(const Student_info &s)
{
    return StudentCredit(s);
}

int main()
{
    std::vector<Student_info> students;
    std::vector<StudentCredit> creditStudents(students.size());
    Student_info record;

    while (read(std::cin, record))
        students.push_back(record);

    sort(students.begin(), students.end(), compare);

    std::transform(students.begin(), students.end(),
                   creditStudents,
                   convertToStudentCredit);

    for (auto i : creditStudents)
        std::cout << i.name() << '\t' << i.grade() << std::endl;

    return 0;
}