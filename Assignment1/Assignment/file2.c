#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int maxlen=50,nbytes;
	char buf[maxlen];
    int fd,fd1;
    ssize_t r_in,r_out;
	fd=open("new_abc.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}

	fd1=open("new_def.txt",O_WRONLY|O_CREAT, 0666);
    if(fd1<0)
	{
		perror("open");
		exit(1);
	}
    while((r_in = read (fd,&buf,maxlen))>0)
    {
        r_out= write(fd1,&buf,r_in);
        if(r_out !=r_in)
        {
            perror("write");
            return 2;
        }

    }
    
    
	close(fd);
    close(fd1);	
	return 0;	//exit(0);
}