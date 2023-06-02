#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    vector<string>test = {"het", "I", "just", "met", "you"};
    string result = accumulate(test.begin(), test.end(), string(""));
    cout << result;
}