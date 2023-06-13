#ifndef VEC_H
#define VEC_H

#include <memory>

template <class T, class Alloc = std::allocator<T>>
class Vec {
private:
    T* elements;
    T* first_free;
    T* cap;
    Alloc alloc;

public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}

    Vec(const Vec& other) {
        range_initialize(other.begin(), other.end());
    }

    Vec& operator=(const Vec& other) {
        if (this != &other) {
            free();
            range_initialize(other.begin(), other.end());
        }
        return *this;
    }

    ~Vec() {
        free();
    }

    void push_back(const T& value) {
        if (size() == capacity())
            reallocate();
        alloc.construct(first_free++, value);
    }

    void erase(size_t index) {
        if (index >= size())
            return;
        alloc.destroy(elements + index);
        std::move(elements + index + 1, first_free, elements + index);
        --first_free;
    }

    void clear() {
        for (T* p = first_free; p != elements; /* empty */) {
            alloc.destroy(--p);
        }
        first_free = elements;
    }

    size_t size() const {
        return first_free - elements;
    }

    size_t capacity() const {
        return cap - elements;
    }

    T* begin() const {
        return elements;
    }

    T* end() const {
        return first_free;
    }

private:
    void range_initialize(T* first, T* last) {
        size_t new_size = last - first;
        elements = alloc.allocate(new_size);
        first_free = cap = elements + new_size;
        std::uninitialized_copy(first, last, elements);
    }

    void free() {
        if (elements) {
            for (T* p = first_free; p != elements; /* empty */) {
                alloc.destroy(--p);
            }
            alloc.deallocate(elements, cap - elements);
        }
    }

    void reallocate() {
        size_t new_capacity = (capacity() == 0) ? 1 : 2 * capacity();
        T* new_elements = alloc.allocate(new_capacity);
        T* new_first_free = std::uninitialized_copy(elements, first_free, new_elements);
        free();
        elements = new_elements;
        first_free = new_first_free;
        cap = elements + new_capacity;
    }
};
#endif