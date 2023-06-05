#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "url.h"

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

        vector<string> words = find_urls(line);

        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it)
            {
                vector<int>& temp = ret[*it];
                vector<int>::iterator iter = find(temp.begin(), temp.end(), line_number);
                
                if(iter == temp.end())
                {
                    temp.push_back(line_number);
                }
            }
    }
    return ret;
}

int main()
{

    map<string, vector<int>> ret = xref(cin);

    for (map<string, vector<int>>::const_iterator it = ret.begin();
         it != ret.end(); ++it)
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