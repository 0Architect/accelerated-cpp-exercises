# Answer
---
```
void getline(std::istream& in)
{
    char ch;

    while(in.get(ch) && ch!='\n')
        append(ch);

    if(ch!='\n')
    {
        in.clear();
        return in;
    }
}
```