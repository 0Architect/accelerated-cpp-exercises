#include <algorithm>

template <class inputIterator>
bool equal(inputIterator b, inputIterator e, inputIterator d)
{
    while (b != e)
    {

        if (*b++ != *d++)
            return false;
    }
    return true;
}

template <class inputIterator, class Type>
inputIterator find(inputIterator b, inputIterator e, Type t)
{
    while (b != e)
    {
        if (*b == t)
            return b;
        else
            ++b;
    }
    return e;
}

template <class inputIterator, class outputIterator>
outputIterator copy(inputIterator b, inputIterator e, outputIterator d)
{
    while (b != e)
    {
        *d = *b;
        ++d;
        ++b;
    }
    return d;
}

template <class inputIterator, class outputIterator, class Pred>
outputIterator remove_copy_if(inputIterator b, inputIterator e, outputIterator d, Pred p)
{
    while (b != e)
    {
        if (!p(*b))
            *d++ = *b;
        ++b;
    }
    return d;
}

template <class inputIterator, class outputIterator, class Func>
outputIterator transform(inputIterator b, inputIterator e, outputIterator d, Func f)
{
    while (b != e)
        *d++ = f(*b++);
    return d;
}

template <class inputIterator, class Type>
Type accumulate(inputIterator b, inputIterator e, Type t)
{
    Type obj = t;
    while (b != e)
        obj += *b++;
    return obj;
}

template <class forwardIterator>
forwardIterator search(forwardIterator b, forwardIterator e, forwardIterator b2, forwardIterator e2)
{
    while (b != e)
    {
        if (*b == *b2)
        {
            ForwardIterator it1 = first;
            ForwardIterator it2 = first2;
            while (it2 != last2 && it1 != last && *it1 == *it2)
            {
                ++it1;
                ++it2;
            }
            if (it2 == last2)
                return first;
        }
        ++b;
    }
    return e;
}

template <class inputIterator, class Pred>
Pred find_if(inputIterator b, inputIterator e, Pred p)
{
    while (b != e)
    {
        if (p(*b))
            return b;
        else
            ++b;
    }
    return e;
}

template <class inputIterator, class outputIterator, class Type>
outputIterator remove_copy(inputIterator b, inputIterator e, outputIterator d, Type t)
{
    while (b != e)
    {
        if (t != *b)
            *d++ = *b;
        b++;
    }
    return d;
}

template <class forwardIterator, class Pred>
forwardIterator remove(forwardIterator b, forwardIterator e, Pred p)
{
    forwardIterator s = b;
    while (b != e)
    {
        if (!p(*b))
        {
            *s = std::move(*b);
            ++s;
        }
        ++b;
    }
    return s;
}

template <class bidirectionalIterator, class Pred>
bidirectionalIterator partition(bidirectionalIterator b, bidirectionalIterator e, Pred p)
{
    bidirectionalIterator s = b;
    while (b != e)
    {
        if (p(*b))
        {
            if (s != b)
                std::iter_swap(s, b);
            ++s;
        }
        b++;
    }
    return s;
}