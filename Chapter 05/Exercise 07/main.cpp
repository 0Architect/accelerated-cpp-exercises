#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include "../../include/frame.h"
#include "../../utilities/StringUtils.h"
#include "../../utilities/PrintUtils.h"

using namespace std;

int main()
{
    vector<string> ret;
    ret = frame(ret);
    Utils::print(ret.begin(), ret.end());

    return 0;
}