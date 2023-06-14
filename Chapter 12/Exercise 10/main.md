# Answer
---
```
template <class InputIterator>
    Vec(InputIterator begin, InputIterator end) {
        size_t size = std::distance(begin, end);

        data = alloc.allocate(size);
        limit = avail = data + size;

        std::uninitialized_copy(begin, end, data);
    }
```

for string:

```
template <class InputIterator>
    Str(InputIterator begin, InputIterator end) : data(begin, end) {}
```