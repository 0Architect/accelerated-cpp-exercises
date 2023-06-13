#include "../../include/StudentInfo.h"

int main()
{
    Student_info student;

    try
    {
        double i_grade = grade(student);
        std::cout << "Student grade: " << i_grade << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }


    return 0;
}