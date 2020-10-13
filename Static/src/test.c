#include <stdarg.h>
#include <stdio.h>
#include "bitmask.h"
#include "myutils.h"
#include "mystring.h"
int main() {
  int n,k;
  n = 10;
  k = 20;
  printf("concatenate string ");
  printf("\nstring compare ");
  mystrcmp("abc","abc");
   mystrcmp("abc","defg");
   printf("\nlength of string");
   mystrlen ("abcdef");
   printf("copy string");
   mystrcpy("test");

   printf("\nfactorial ");
   factorial(4);
   printf("\n 0 for palindrome ");
   isPalindrome(121);
   printf("\n 1 for prime ");
   isPrime(4);
    printf("Sum of 2, 3, 4, 5 = %f\n", vsum(4, 2,3,4,5,6));
    printf("Sum of 5, 10, 15 = %f\n", vsum(3, 5,10,15));
  printf("Sum of 2, 3, 4, 5 = %f\n", vsum(4, 2,3,4,5,6));

    printf("%d with %d-th bit Set: %d\n",
           n, k, setBit(n, k));
    printf("%d with %d-th bit Cleared: %d\n",
           n, k, clearBit(n, k));
    printf("%d with %d-th bit Toggled: %d\n",
           n, k, toggleBit(n, k));
 
 
   return 0; 
  
}
