#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::sort(vec.begin(), vec.end());
    int q1 = vec.size() * 0.25;
    int q2 = vec.size() * 0.5;
    int q3 = vec.size() * 0.75;
    int q4 = vec.size();
    std::cout << "Q1: " << vec[q1 - 1] << std::endl;
    std::cout << "Q2: " << vec[q2 - 1] << std::endl;
    std::cout << "Q3: " << vec[q3 - 1] << std::endl;
    std::cout << "Q4: " << vec[q4 - 1] << std::endl;
    return 0;
}