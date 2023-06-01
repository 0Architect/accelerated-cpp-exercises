#include <vector>
#include "../../utilities/PrintUtils.h"
#include "../../utilities/StringUtlils.h"
#include <algorithm>
#include <cmath>
#include <string>

using std::vector;
using std::string;

typedef vector<string> vs;

vs center(const vs& vec)
{
    vs ret;
    string::size_type maxlen = 0;

    for(string i: vec)
    {
        maxlen = std::max(maxlen, i.size());
    }

    for(string i: vec)
    {
        int val = std::ceil((i.size() + maxlen) / 2.0);
        ret.push_back(string(val - i.size(), ' ') + i);
    }
    return ret;
}

int main()
{
    vs ans;
    vs ans2;
    Utils::split("i eye five Anthony Onamatope", std::back_inserter(ans));
    ans2 = center(ans);
    Utils::print(ans2.begin(), ans2.end());
    return 0;
}