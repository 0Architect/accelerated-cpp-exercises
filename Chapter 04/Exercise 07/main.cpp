#include <iostream>
#include <vector>
#include <numeric>

double average (const std::vector<double>& vec)
{
    return std::accumulate(vec.begin(), vec.end(), 0.0)/vec.size();
}