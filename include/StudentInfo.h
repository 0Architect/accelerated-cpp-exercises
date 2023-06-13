#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <algorithm>

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(std::vector<double> vec)
{
    if (vec.size() == 0)
        throw std::domain_error("median of an empty vector");
    std::sort(vec.begin(), vec.end());
    std::vector<double>::size_type mid = vec.size() / 2;
    return vec.size() % 2 ? vec[mid] : (vec[mid] + vec[mid - 1]) / 2;
}

std::istream &read_hw(std::istream &in, std::vector<double> &vec)
{
    if (in)
    {
        vec.clear();
        double temp;
        while (in >> temp)
            vec.push_back(temp);
        in.clear();
    }
    return in;
}

struct Student_info
{
    std::string name;
    double midterm, final;
    std::vector<double> homework;
    bool valid(){return !homework.empty();}
};

double grade(double midterm, double final, const std::vector<double> &homework)
{
    if (homework.size() == 0)
        throw std::domain_error("Student has done no homework");
    return grade(midterm, final, median(homework));
}

std::istream &read(std::istream &in, Student_info &s1)
{
    in >> s1.name >> s1.final >> s1.midterm;
    read_hw(in, s1.homework);
    return in;
}

double grade(const Student_info &s1)
{
    return grade(s1.midterm, s1.final, s1.homework);
}

bool compare(const Student_info &x, const Student_info &y)
{
    return x.name < y.name;
}