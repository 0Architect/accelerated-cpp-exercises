#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string::size_type width(const vector<string> &vec)
{
    return (*max_element(vec.begin(), vec.end(),
                         [](string lhs, string rhs)
                         { return lhs.size() < rhs.size(); }))
        .size();
}

vector<string> frame(const vector<string> &vec)
{
    vector<string> ret;
    string::size_type max_length = width(vec);
    string border(max_length + 4, '*');

    ret.push_back(border);

    transform(vec.begin(), vec.end(), back_inserter(ret),
              [max_length](string line)
              {
                  return "* " +
                         line +
                         std::string(max_length - line.size(), ' ') +
                         " *";
              });

    ret.push_back(border);
    return ret;
}

vector<string> hcat(const vector<string> &left, const vector<string> &right)
{
    vector<string> ret;

    string::size_type left_width = width(left);

    vector<string>::const_iterator left_iter = left.begin(), right_iter = right.begin();

    while (left_iter != left.end() || right_iter != right.end())
    {

        string line;

        if (left_iter != left.end())
            line += *left_iter++;

        line += string(left_width + 1 - line.size(), ' ');

        if (right_iter != right.end())
            line += *right_iter++;

        *back_inserter(ret) = line;
    }
    return ret;
}

int main()
{
    return 0;
}