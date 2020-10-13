#include "bitmask.h"
// Function to toggle the kth bit of n
int toggleBit(int n, int k)
{
    return (n ^ (1 << (k - 1)));
} 
