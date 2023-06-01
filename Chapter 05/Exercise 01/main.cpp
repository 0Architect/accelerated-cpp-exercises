#include <iostream>
#include <numeric>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

bool space(char c)
{
    return isspace(c);
}

bool nospace(char c)
{
    return !isspace(c);
}

char lower_char(char c)
{
    return std::tolower(c);
}

bool caseInsensitiveCompare(std::string a, std::string b) {
    std::transform(a.begin(), a.end(), a.begin(), lower_char);
    std::transform(b.begin(), b.end(), b.begin(), lower_char);
    return a < b;
}

std::vector<std::string> split(std::string str)
{
    typedef std::string::const_iterator ci;
    std::vector<std::string> ret;
    ci end_iter, beg_iter = str.begin();
    while (beg_iter != static_cast<ci>(str.end()))
    {
        beg_iter = std::find_if(beg_iter, static_cast<ci>(str.end()), nospace);
        end_iter = std::find_if(beg_iter, static_cast<ci>(str.end()), space);
        ret.push_back(std::string(beg_iter, end_iter));
        beg_iter = end_iter;
    }
    return ret;
}

int getPad(std::vector<std::string> lines)
{
    int maxlen = 0;
    std::vector<std::string> smth;
    for(auto i: lines)
    {
        smth = split(i);
        smth.pop_back();
        std::string temp = std::accumulate(smth.begin(), smth.end(), std::string(""));
        int smth_size = smth.size() + temp.size();
        maxlen = maxlen > smth_size ? maxlen : smth_size;
    }
    return maxlen;
}

// Format prints a line
void print_line(std::string word, std::string line, int pad)
{
    std::vector<std::string> temp = split(line);
    int pos = word.back() - '0';
    for (int i = 0; i < temp.size(); ++i)
    {
        std::string before = std::accumulate(temp.begin(), temp.begin() + pos, std::string(""));
        int spaceSize= before.size() + pos;
        if (i == pos)
            std::cout << std::string(5 + pad - spaceSize, ' ');
        std::cout << temp[i]
                  << (i == temp.size() - 1 ? "" : " ");
    }
}

int main()
{
    std::string line;
    std::vector<std::string> lines;
    std::vector<std::vector<std::string>> words;
    while (std::getline(std::cin, line))
        lines.push_back(line);

    // Split the string lines in words
    for (std::string l : lines)
        words.push_back(split(l));

    // Annotate each word with their row and columns
    for (int row = 0; row < words.size(); ++row)
    {
        for (int col = 0; col < words[row].size(); ++col)
        {
            words[row][col] += std::to_string(row);
            words[row][col] += std::to_string(col);
        }
    }

    // Extract the words for sorting
    std::vector<std::string> toSort;
    for (auto vec : words)
        for (auto word : vec)
            toSort.push_back(word);

    // Sort the words
    std::sort(toSort.begin(), toSort.end(), caseInsensitiveCompare);

    // Print the words
    for (auto word : toSort)
    {
        int line_number = *(word.rbegin() + 1) - '0';
        int pad = getPad(lines);
        print_line(word, lines[line_number], pad);
        std::cout << std::endl;
    }
    return 0;
}