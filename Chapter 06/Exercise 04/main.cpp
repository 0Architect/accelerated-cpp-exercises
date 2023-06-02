#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "../../utilities/PrintUtils.h"

using namespace std;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    
    //First Approach: .resize()
    v.resize(u.size());
    copy(u.begin(), u.end(), v.begin());

    //Second Approach: back_inserter()
    copy(u.begin(), u.end(), back_inserter(v));

    Utils::print(v.begin(), v.end());
    return 0;
}