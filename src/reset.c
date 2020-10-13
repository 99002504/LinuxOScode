#include "bitmask.h"
// Function to clear the kth bit of n
int clearBit(int n, int k)
{
    return (n & (~(1 << (k - 1))));
} 
