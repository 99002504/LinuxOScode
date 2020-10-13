#include "myutils.h"
int isPalindrome(int number)
 {
   int temp, remainder, sum=0;

   temp = number;

   while( number!=0 )
   {
       remainder = number % 10;
       sum = sum*10 + remainder;
       number /= 10;
   }

   if ( sum == temp ) 
    {return 0;}

   else return 1;
 }