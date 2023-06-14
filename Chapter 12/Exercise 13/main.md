# Answer
---
```
template <typename InputIterator>
    void assign(InputIterator first, InputIterator last) {
        clear();
        insert(begin(), first, last);
    }
```