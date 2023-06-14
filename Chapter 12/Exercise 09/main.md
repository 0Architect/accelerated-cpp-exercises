# Solution
---
```
std::ostream& operator<<(std::ostream& out, const Str& obj)
{
    std::ostream_iterator<char> iter(out);

    for (Str::const_iterator it = obj.begin(); it != obj.end(); ++it)
    {
        *iter = *it;
        ++iter;
    }

    return out;
}
```