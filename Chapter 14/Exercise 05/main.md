#include <iostream>
#include <vector>
#include <cctype>
#include <algorithm>
#include "Str.h" // Assuming Str class is defined in Str.h

std::vector<Str> split(const Str& s) {
    std::vector<Str> words;
    typedef Str::size_type size_type;
    size_type i = 0;

    while (i < s.size()) {
        // Skip leading whitespace
        while (i < s.size() && isspace(s[i]))
            ++i;

        // Find the end of the current word
        size_type j = i;
        while (j < s.size() && !isspace(s[j]))
            ++j;

        // Extract the word from the Str and add it to the vector
        if (i != j)
            words.push_back(s.substr(i, j - i));

        i = j; // Move to the next word
    }

    return words;
}

int main() {
    Str input;
    std::cout << "Enter a sentence: ";
    std::cin >> input;

    std::vector<Str> words = split(input);

    // Print the words
    std::cout << "Words in the sentence:" << std::endl;
    for (const auto& word : words)
        std::cout << word << std::endl;

    return 0;
}