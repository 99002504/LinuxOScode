#include "mystring.h"
#include<string.h>
#include<stdio.h>
void mystrcat(char s1[100], char s2[100])
{
    int j,length = 0;
  while (s1[length] != '\0') {
    ++length;
  }

  // concatenate s2 to s1
  for (j = 0; s2[j] != '\0'; ++j, ++length) {
    s1[length] = s2[j];
  }

  // terminating the s1 string
  s1[length] = '\0';

  printf("After concatenation: ");
  puts(s1);
   
}
