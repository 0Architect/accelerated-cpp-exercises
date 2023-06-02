#include <vector>
#include <iostream>
#include <algorithm>
#include "../../utilities/PrintUtils.h"

using namespace std;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());

    Utils::print(v.begin(), v.end());
    return 0;
}