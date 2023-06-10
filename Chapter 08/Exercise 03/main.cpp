#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<class Iter>
double median(Iter start, Iter end)
{
    ptrdiff_t size = end - start;
    if (size == 0)
        throw domain_error("median of an empty vector");
    sort(start, end);

    ptrdiff_t mid = size / 2;
    return size % 2 == 0 ? (start[mid] + start[mid - 1]) / 2 : start[mid];
}