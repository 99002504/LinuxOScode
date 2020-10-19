#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret;
    int stat;
    int cmd;
    char Com[10];
    printf("Enter your command:");
    scanf("%s", Com);                  
    ret=fork();
    
    if(ret<0)
    {
        perror("fork");
        exit(1);
    }
    if(ret==0)
    {
        cmd=execlp(Com,Com);
        if(cmd<0)
        {
            perror("execlp");
            exit(2);
        }
        exit(0);
    }
    else
    {
        waitpid(-1,&stat,0); //wait(&stat);
        printf("parent--child exit stat=%d\n",
			WEXITSTATUS(stat));
    }
}