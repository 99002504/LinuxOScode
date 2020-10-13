#include "mystring.h"
int mystrlen (char str[100]) 
{
   int len = 0;
   while (str[len] != '\0')
      len++;
   return (len);
}