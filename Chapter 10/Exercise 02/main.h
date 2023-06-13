#ifndef MAIN_H
#define MAIN_H

#include <algorithm>
#include <stdexcept>

using namespace std;

template <class InputIterator, class Type>
Type median(InputIterator beg, InputIterator end)
{

    size_t size = end - beg;
    if (size == 0)
        throw domain_error("median of an empty vector");
        
    sort(beg, end);

    size_t mid = size / 2;
    return size % 2 == 0 ? (beg[mid] + beg[mid - 1]) / 2 : beg[mid];
}

#endif