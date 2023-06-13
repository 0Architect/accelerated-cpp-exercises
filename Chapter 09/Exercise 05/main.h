#ifndef Main_H
#define MAIN_H

#include "../../include/StudentInfo.h"
#include <string>

class StudentCredit
{
private:
    Student_info member;
    double calculateScore() const { return 0.5 * (member.final + member.midterm); }

public:
    StudentCredit(Student_info s) : member(s) {}
    char grade() const { return calculateScore() > 60 ? 'P' : 'F'; }
    std::string name() { return member.name; }
};

#endif