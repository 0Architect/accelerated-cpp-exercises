#include "../Exercise 02/main.h"
#include <vector>
#include <list>
#include <iostream>
#include "../../utilities/PrintUtils.h"

using namespace std;

int main()
{
    vector<int> test1 = {1,2,3,4,5,6,7,8,9,10};
    vector<double> test2 = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.3,9.8,10.4};
    int array[] = {1,2,3,4,5,6,7,8,9,10};

    Utils::print(test1.begin(), test1.end());
    Utils::print(test2.begin(), test2.end());
    Utils::print(array, array);

    median<decltype(test1.begin()), int>(test1.begin(), test1.end());
    median<decltype(test2.begin()), double>(test2.begin(), test2.end());
    median<decltype(array), int>(array, array + 11);

    Utils::print(test1.begin(), test1.end());
    Utils::print(test2.begin(), test2.end());
    Utils::print(array, array + 10);
}