# Answer
---
```
template <class T>
typename Vec<T>::iterator Vec<T>::insert(typename Vec<T>::iterator position, const T& value) {
    size_type index = position - begin();

    if (avail == limit)
        grow();

    iterator newPos = begin() + index;

    uninitialized_copy(position, avail, avail + 1);
    *(begin() + index) = value;

    ++avail;

    return newPos;
}
```

## Str
```
void insert(iterator pos, iterator first, iterator last)
    {
        sz new_size = size() + (last - first);
        iterator new_container = allocator.allocate(new_size);
        iterator new_pos = new_container;

        std::uninitialized_copy(container, pos, new_pos);
        new_pos += (pos - container);

        std::uninitialized_copy(first, last, new_pos);
        new_pos += (last - first);

        std::uninitialized_copy(pos, container + size(), new_pos);

        unCreate();
        container = new_container;
        dimension = new_size;
    }
```