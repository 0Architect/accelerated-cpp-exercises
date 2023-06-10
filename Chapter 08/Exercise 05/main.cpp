#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include "../../utilities/StringUtils.h"

using namespace std;

template <class OutputIterator>
map<string, vector<int>>
xref(istream &in, OutputIterator out)
{
    string line;
    int line_number = 0;

    while (getline(in, line))
    {
        ++line_number;

        vector<string> words;
        Utils::string_split(line, back_inserter(words));

        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it)
        {
            *out++ = std::make_pair(*it, line_number);
        }
    }
    return ret;
}

// ======================================================
// Gen Sentence

typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;

int nrand(int n)
{
    if (n <= 0 || n > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    const int bucket_size = RAND_MAX / n;
    int r;
    do
        r = rand() / bucket_size;
    while (r >= n);
    return r;
}

bool bracketed(const string &s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

template <class OutputIterator>
void gen_aux(const Grammar &g, const string &word, OutputIterator out)
{
    if (!bracketed(word))
        *out++ = word;

    else
    {

        Grammar::const_iterator it = g.find(word);
        if (it == g.end())
            throw logic_error("empty rule");

        const Rule_collection &c = it->second;

        const Rule &r = c[nrand(c.size())];

        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
            gen_aux(g, *i, out);
    }
}

template <class OutputIterator>
void gen_sentence(const Grammar &g, OutputIterator out)
{
    gen_aux(g, "<sentence>", out);
}