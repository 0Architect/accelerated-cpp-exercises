#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../../utilities/StringUtils.h"

using namespace std;

map<string, vector<int>>
xref(istream &in)
{
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    while (getline(in, line))
    {
        ++line_number;

        vector<string> words;
        Utils::string_split(line, back_inserter(words));

        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it)
        {
            vector<int> &temp = ret[*it];
            vector<int>::iterator iter = find(temp.begin(), temp.end(), line_number);

            if (iter == temp.end())
            {
                temp.push_back(line_number);
            }
        }
    }
    return ret;
}

int main()
{

    // Updated
    const map<string, vector<int >>::size_type outputSize = 10;

    map<string, vector<int>> ret = xref(cin);
    int lineCount = 0;

    for (map<string, vector<int>>::const_iterator it = ret.begin();
         lineCount < outputSize && it != ret.end(); ++it, ++lineCount)
    {

        cout << it->first << " occurs on line(s): ";

        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it;
        ++line_it;

        while (line_it != it->second.end())
        {
            cout << ", " << *line_it;
            ++line_it;
        }

        cout << endl;
    }

    return 0;
}