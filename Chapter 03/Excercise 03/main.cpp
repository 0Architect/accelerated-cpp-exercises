#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::string input;
    std::vector<std::string> word;
    std::cout << "Enter your input: "
                 "(To end place an end of file marker -ctrl+z on windows)"
              << std::endl;
    while (std::cin >> input)
        word.push_back(input);
    std::sort(word.begin(), word.end());
    int count = 0;
    std::string mee = word[0];
    for (const std::string &temp : word)
    {
        if (temp == mee)
            count++;
        else
        {
            std::cout << mee << " " << count << std::endl;
            count = 1;
            mee = temp;
        }
    }
    return 0;
}