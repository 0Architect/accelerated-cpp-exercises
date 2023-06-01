#ifndef frame_H
#define frame_H

#include <string>
#include <vector>
#include <algorithm>

std::string::size_type width(const std::vector<std::string> &v)
{
    std::string::size_type maxlen = 0;
    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
        maxlen = std::max(maxlen, v[i].size());
    return maxlen;
}

std::vector<std::string> frame(const std::vector<std::string> &v)
{
    std::vector<std::string> ret;
    std::string::size_type maxlen = width(v);
    std::string border(maxlen + 4, '*');

    ret.push_back(border);

    for (std::vector<std::string>::size_type i = 0; i != v.size(); ++i)
    {
        ret.push_back("* " + v[i] +
                      std::string(maxlen - v[i].size(), ' ') + " *");
    }

    ret.push_back(border);
    return ret;
}

std::vector<std::string> vcat(const std::vector<std::string> &top,
                              const std::vector<std::string> &bottom)
{

    std::vector<std::string> ret = top;

    for (std::vector<std::string>::const_iterator it = bottom.begin();
         it != bottom.end(); ++it)
        ret.push_back(*it);
    return ret;
}

std::vector<std::string>
hcat(const std::vector<std::string> &left, const std::vector<std::string> &right)
{
    std::vector<std::string> ret;

    std::string::size_type width1 = width(left) + 1;

    std::vector<std::string>::size_type i = 0, j = 0;

    while (i != left.size() || j != right.size())
    {

        std::string s;

        if (i != left.size())
            s = left[i++];

        s += std::string(width1 - s.size(), ' ');

        if (j != right.size())
            s += right[j++];

        ret.push_back(s);
    }
    return ret;
}

#endif