#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    map<string, int> counter;
    map<int, vector<string> >
        counter_out;

    while (cin >> s)
        ++counter[s];

    for (const auto &[key, value] : counter)
        counter_out[value].push_back(key);

    for (const auto &[key, value] : counter_out)
    {
        for (const string word : value)
            cout << word << "\t" << key << endl;
    }

    return 0;
}