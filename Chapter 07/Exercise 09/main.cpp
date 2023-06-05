#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

int nrand(int n)
{
    if (n <= 0)
        throw std::domain_error("Argument to nrand must be positive");

    const int max_allowed = RAND_MAX - RAND_MAX % n;

    int r;
    do
    {
        r = rand();
    } while (r >= max_allowed);

    return r % n;
}