#include "mystring.h"
#include<string.h>
#include<stdio.h>
void mystrcpy(char s1[100])
{   
    int i=0;
    char s2[100];
    for (i = 0; s1[i] != '\0'; ++i) {
        s2[i] = s1[i];
    }

    s2[i] = '\0';
    printf("String s2: %s", s2);

}
