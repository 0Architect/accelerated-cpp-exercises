#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool hasAscender(const string &str)
{
    const static string ascenders = "bdfhklt";

    string::const_iterator iter = find_if(str.begin(), str.end(),
                                          [](char ch)
                                          {
                                              return ascenders.find(tolower(ch)) != string::npos;
                                          });

    return iter != str.end();
}

bool hasDescender(const string &str)
{
    const static string descenders = "gjpqy";

    string::const_iterator iter = find_if(str.begin(), str.end(),
                                          [](char ch)
                                          {
                                              return descenders.find(tolower(ch)) != string::npos;
                                          });

    return iter != str.end();
}

int main()
{
    vector<string> output;
    vector<string>::iterator max_output;

    vector<string> dictionary = {
        "aman",
        "isadog",
        "butis",
        "adog",
        "aweruio",
        "aweruiosz",
        "awerxcuiosz",
    };

    copy_if(dictionary.begin(), dictionary.end(),
            back_inserter(output), [](string word)
            { return !hasAscender(word) && !hasDescender(word); });

    max_output = max_element(output.begin(), output.end(), 
    [](string lhs, string rhs)
    {
        return lhs.size() < rhs.size();
    });

    std::cout << *max_output;
    return 0;
}