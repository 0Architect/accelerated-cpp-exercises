#ifndef STR_H
#define STR_H

#include <memory>
#include <iostream>
#include <cstring>
#include <algorithm>

class Str
{

public:
    typedef char *iterator;
    typedef const char *const_iterator;
    typedef size_t sz;

    friend std::istream &operator>>(std::istream &, Str &);

    Str() : container(0), dimension(0) {}

    Str(sz ch_size, char ch) : dimension(ch_size)
    {
        create(ch, ch_size);
    }

    Str(const char *charArray)
    {
        sz arraySize = std::strlen(charArray);
        dimension = arraySize;
        create(charArray, arraySize);
    }

    Str(const Str &copy)
    {
        create(copy.begin(), copy.size());
        dimension = copy.size();
    }

    iterator begin() const
    {
        return container;
    }

    iterator end() const
    {
        return container + dimension;
    }

    sz size() const
    {
        return dimension;
    }

    ~Str()
    {
        unCreate();
    }

    Str &operator=(const Str &rhs)
    {
        if (begin() != rhs.begin())
        {
            unCreate();
            create(rhs.begin(), rhs.size());
            dimension = rhs.size();
        }
        return *this;
    }

    char &operator[](sz index)
    {
        c_str_ptr = 0;
        return container[index];
    }

    Str &operator+=(const Str &rhs)
    {
        for(sz j = 0; j < rhs.size(); ++j)
        {
            append(rhs.container[j]);
        }
        return *this;
    }

    void append(char ch)
    {
        sz Str_size = size();
        char temp[Str_size + 1];
        for (sz i = 0; i < size(); ++i)
            temp[i] = container[i];
        temp[Str_size] = ch;
        unCreate();
        create(temp, Str_size + 1);
        dimension = Str_size + 1;
    }

    const char* c_str()
    {
        c_str_ptr = new char[size() + 1];

        for(sz i = 0; i < size(); ++i) 
            c_str_ptr[i] = container[i];

        c_str_ptr[size() + 1] = '\0';
        return c_str_ptr;
    }

    const char* data()
    {
        c_str_ptr = new char[size()];

        for(sz i = 0; i < size(); ++i) 
            c_str_ptr[i] = container[i];

        return c_str_ptr;
    }

    void copy(char *ptr, sz n)
    {
        std::copy(begin(), begin() + n, ptr);
    }

private:
    iterator container;
    iterator c_str_ptr;
    sz dimension;
    void create(char, sz);
    void create(const_iterator, sz);
    void unCreate();
    std::allocator<char> allocator;
};

void Str::create(char ch, sz size)
{
    container = allocator.allocate(size);
    std::uninitialized_fill(container, container + dimension, ch);
}

void Str::create(const_iterator iter, sz size)
{
    container = allocator.allocate(size);
    std::uninitialized_copy(iter, iter + size, container);
}

void Str::unCreate()
{
    for (sz i = 0; i < dimension; ++i)
        allocator.destroy(container + i);
    allocator.deallocate(container, dimension);
    container = 0;
    dimension = 0;
    c_str_ptr = 0;
}

Str operator+(const Str &lhs, const Str &rhs)
{
    Str temp = lhs;
    temp += rhs;
    return temp;
}

bool operator==(const Str &lhs, const Str &rhs)
{
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator!=(const Str &lhs, const Str &rhs)
{
    return !std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

bool operator<(const Str &lhs, const Str &rhs)
{
    // Export task to string
    char temp_lhs[lhs.size() + 1];
    char temp_rhs[rhs.size() + 1];
    int i = 0;
    while (i < lhs.size())
    {
        temp_lhs[i] = lhs.begin()[i];
        ++i;
    }
    temp_lhs[lhs.size()] = '\0';

    int j = 0;
    while (j < rhs.size())
    {
        temp_rhs[j] = rhs.begin()[j];
        ++j;
    }
    temp_rhs[rhs.size()] = '\0';

    return (std::string(temp_lhs) < std::string(temp_rhs));
}

std::istream &operator>>(std::istream &in, Str &obj)
{
    obj.unCreate();
    char ch;
    while (in >> ch && isspace(ch))
        ;
    do
    {
        obj.append(ch);
    } while (in.get(ch) && !isspace(ch));

    if (in)
        in.putback(ch);

    in.clear();
    return in;
}

std::ostream &operator<<(std::ostream &out, Str &obj)
{
    for (Str::iterator iter = obj.begin(); iter != obj.end(); ++iter)
        out << *iter;
    return out;
}

#endif