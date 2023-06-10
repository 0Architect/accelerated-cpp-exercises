template <class Iter>
void swap(Iter a, Iter b)
{
    Iter temp = a;
    *a = *b;
    *b = *temp;
}