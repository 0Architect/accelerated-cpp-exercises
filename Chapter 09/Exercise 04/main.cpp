#include "../../include/StudentInfo.h"

int main()
{
    Student_info student;
    if(student.valid())
    {
        double i_grade = grade(student);
        std::cout << "Student grade: " << i_grade << std::endl;
    }
    return 0;
}