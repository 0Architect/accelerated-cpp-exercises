#ifndef STRING_LIST_H
#define STRING_LIST_H

#include <iostream>
#include <string>
#include <list>
#include "../Exercise 05/Iterator.h"

class String_list
{
private:
    std::list<std::string> container;

public:
    String_list(){};
    void push_back(std::string s)
    {
        container.push_back(s);
    }
    void push_front(std::string s)
    {
        container.push_front(s);
    }
    void pop_back()
    {
        container.pop_back();
    }
    void pop_front()
    {
        container.pop_front();
    }
    bool empty()
    {
        return container.empty();
    }
    size_t size()
    {
        return container.size();
    }
    void sort()
    {
        container.sort();
    }
    void reverse()
    {
        container.reverse();
    }
    std::string front()
    {
        return container.front();
    }
    std::string back()
    {
        return container.back();
    }

    Iterator begin()
    {
        return Iterator(container.begin());
    }

    Iterator end()
    {
        return Iterator(container.end());
    }
};

#endif