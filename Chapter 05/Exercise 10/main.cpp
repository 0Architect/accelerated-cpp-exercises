#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "../../utilities/PrintUtils.h"

using namespace std;

int main()
{

    vector<string> dictionary = {
        "aba",
        "soap",
        "eba",
        "palindrome",
        "abba",
        "not"};

    vector<string> palindrome;
    vector<string>::iterator max_palindrome;

    copy_if(dictionary.begin(), dictionary.end(),
            back_inserter(palindrome),
            [](string word)
            {
                string reversed = word;
                reverse(reversed.begin(), reversed.end());
                return word == reversed;
            });

    max_palindrome = max_element(
        palindrome.begin(), palindrome.end(),
        [](string lhs, string rhs)
        { return lhs.size() < rhs.size(); });

    cout << "The palindromes are:" << endl;
    Utils::print(palindrome.begin(), palindrome.end());
    cout << "THe longest palindrome is: " << *max_palindrome;
    return 0;
}
