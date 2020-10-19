#include <stdio.h>

#define FSIZE 100
 
int main()
{
    FILE *fptr, *fptr1, *p;
    int ctr = 0;
    int ch_count=0;
    int w=0;
    char fname[FSIZE];
    char c,ch; 
    printf("\n\n Read the file and count the number of lines :\n");
	printf("--------------------------------------------------\n"); 
	printf(" Input the file name to be opened : ");
	scanf("%s",fname);

    fptr = fopen(fname, "r");
    if (fptr == NULL)
    {
        printf("Could not open file %s", fname);
        return 0;
    }
    // Extract characters from file and store in character c
    for (c = getc(fptr); c != EOF; c = getc(fptr))
        if (c == '\n') // Increment count if this character is newline
            ctr = ctr + 1;

    fclose(fptr);

    fptr1 = fopen(fname, "r");
	while((ch=fgetc(fptr))!=EOF) 
    {
		ch_count++;
    }
   fclose(fptr1);

   p=fopen(fname,"r");
   ch=fgetc(p);
          while(ch!=EOF)
                 {
                       // printf("%c",ch);
                        if(ch==' '||ch=='\n')
                          {
                               w++;
                          }
                               ch=fgetc(p);
                 }
                               printf("\nWords in a file are=%d",w);
                              fclose(p);
    printf(" The lines in the file %s are : %d \n \n", fname, ctr);
    printf("\nNo. of characters in the file: %d",ch_count);
    //printf("\nNo. of words in the file: %d",word);
    return 0;
}
