#include "myutils.h"
 int factorial(int n)
{
    int i,factorial=1;
    for(i=1; i<=n; i++)
    {
        factorial=factorial*i;
    }
    return factorial;
}