#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int f,buffer;
	f =open("file1.txt",O_RDONLY);
	if(f<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=300;
	char buf[maxlen];
    int f1,file_size;
	f1=open("file2.txt",O_WRONLY|O_CREAT, 0666);
	if(f1<0)
	{
		perror("open");
		exit(3);
	}
    while(buffer=read(f1,buf,maxlen))
    {
	    file_size =	write(f1, buf, maxlen);
        if(file_size<0)
	    {
		    perror("write");
		    exit(4);
	    }
    }

    
    close(f);
    close(f1);
    printf("Copy Successful \n");
}