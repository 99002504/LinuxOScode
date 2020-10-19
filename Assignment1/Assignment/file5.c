#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret_stat;
    int status;
int execute;

    ret_stat=fork();
    if(ret_stat < 0)
    {
        perror("fork");
        exit(1);
    }
    if(ret_stat == 0)
    {
                                   
        execute = execl("/usr/bin/gcc","gcc","-c","test.c",NULL); 
	execl("/bin/gcc","gcc","test.o","-o",s,NULL); 

                            
        if(execute<0)
        {
            perror("execv");
            exit(2);
        }
        exit(0);

    }
    else
    {
        waitpid(-1,&status,0); 
        printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
		
    }
    return 0;

}