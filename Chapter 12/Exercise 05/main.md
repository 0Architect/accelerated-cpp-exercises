# Solution
---
This is short so I decided to just write it here

For const char* ch concatenation function:

```
Str temp;
while(*ch! = '\0')
{
    temp.append(*ch++);
}
return temp
```