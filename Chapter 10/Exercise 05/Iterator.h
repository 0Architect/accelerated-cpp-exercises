#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>

class Iterator
{
private:
    std::list<std::string>::iterator ptr_;

public:
    Iterator(std::list<std::string>::iterator ptr) : ptr_(ptr) {}

    std::string &operator*() const
    {
        return *ptr_;
    }

    std::string *operator->() const
    {
        return &(*ptr_);
    }

    Iterator &operator++()
    {
        ++ptr_;
        return *this;
    }

    Iterator operator++(int)
    {
        Iterator temp(*this);
        ++ptr_;
        return temp;
    }

    Iterator &operator--()
    {
        --ptr_;
        return *this;
    }

    Iterator operator--(int)
    {
        Iterator temp(*this);
        --ptr_;
        return temp;
    }

    bool operator==(const Iterator &other) const
    {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const Iterator &other) const
    {
        return !(*this == other);
    }
};

#endif
