#include <iostream>
#include <string>
#include "../Exercise 06/Vec.h"

Vec<std::string> frameStrings(const Vec<std::string>& input) {
    Vec<std::string> framedStrings;

    if (input.size() == 0)
        return framedStrings;

    size_t maxLength = 0;
    for (const auto& str : input) {
        if (str.length() > maxLength)
            maxLength = str.length();
    }

    std::string border(maxLength + 4, '*');

    framedStrings.push_back(border);
    for (const auto& str : input) {
        std::string framedStr = "* " + str;
        framedStr += std::string(maxLength - str.length(), ' ');
        framedStr += " *";
        framedStrings.push_back(framedStr);
    }
    framedStrings.push_back(border);

    return framedStrings;
}

int main() {
    Vec<std::string> inputStrings;
    inputStrings.push_back("Hello");
    inputStrings.push_back("World!");
    inputStrings.push_back("Welcome");
    inputStrings.push_back("to");
    inputStrings.push_back("Vec");
    Vec<std::string> framedStrings = frameStrings(inputStrings);

    for (const auto& str : framedStrings) {
        std::cout << str << std::endl;
    }

    return 0;
}
