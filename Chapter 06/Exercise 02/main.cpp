#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "url.h"

using namespace std;

bool test_url(string test_value, vector<string> correct_response)
{
    return correct_response == find_urls(test_value);
}

int main()
{
    struct testStructure
    {
        string name;
        string question;
        vector<string> solution;
    };
    
    vector<testStructure> Tests = {
        {"Test1",
         "Check out this website: https://www.example.com for more information.",
         {"https://www.example.com"}},

        {"Test2",
         "I found an interesting article on http://www.testsite.org",
         {"http://www.testsite.org"}},

        {"Test3",
         "http://www.testsite.org that you should read.",
         {"http://www.testsite.org"}},

        {"Test4",
         "://www.testsite.org that http://www.testsite.org you should read.",
         {"http://www.testsite.org"}},

        {"Test5",
         "://www.testsite.org that at https://www.fakeurl.com/path/to/page for http://",
         {"https://www.fakeurl.com/path/to/page"}}};

    for (testStructure test : Tests)
    {
        cout << test.name << (test_url(test.question, test.solution) ? ": Passed" : ": Failed") << endl;
    }

    return 0;
}