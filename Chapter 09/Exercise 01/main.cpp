#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Student_info
{
public:
    Student_info();
    Student_info(std::istream&);
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
    std::istream &read(std::istream &);
    double grade() const;

private:
    std::string n;
    double midterm, final, final_grade;
    std::vector<double> homework;
};

double median(std::vector<double> vec)
{
    if (vec.size() == 0)
        throw std::domain_error("median of an empty vector");
    std::sort(vec.begin(), vec.end());
    std::vector<double>::size_type mid = vec.size() / 2;
    return vec.size() % 2 ? vec[mid] : (vec[mid] + vec[mid - 1]) / 2;
}

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const std::vector<double> &homework)
{
    if (homework.size() == 0)
        throw std::domain_error("Student has done no homework");
    return grade(midterm, final, median(homework));
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

std::istream &Student_info::read(std::istream &in)
{
    in >> n >> midterm >> final;
    read_hw(in, homework);
    final_grade = ::grade(midterm, final, homework);
    return in;
}

Student_info::Student_info(): midterm(0), final(0) { }
Student_info::Student_info(std::istream& is){ read(is); };

double median(std::vector<double> vec)
{
    if (vec.size() == 0)
        throw std::domain_error("median of an empty vector");
    std::sort(vec.begin(), vec.end());
    std::vector<double>::size_type mid = vec.size() / 2;
    return vec.size() % 2 ? vec[mid] : (vec[mid] + vec[mid - 1]) / 2;
}

double Student_info::grade() const
{
    return final_grade;
}