#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  

void sighup(); 
void sigint(); 
void sigquit(); 
  
 
void main() 
{ 
    int pid_n; 
  
    /* child */
    if ((pid_n = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid_n == 0) { /* child */
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; /* loop for ever */
    } 
    /* parent */
    else 
    { 
        printf("\nParent: sends SIGHUP signal\n\n"); 
        kill(pid_n, SIGHUP); 
  
        sleep(3); 
        printf("\nParent: sends SIGINT signal\n\n"); 
        kill(pid_n, SIGINT); 
  
        sleep(3); 
        printf("\nParent: sends SIGQUIT signal\n\n"); 
        kill(pid_n, SIGQUIT); 
        sleep(3); 
    } 
} 
  

void sighup() 
  
{ 
    signal(SIGHUP, sighup); /* reset signal */
    printf("Child  received a SIGHUP signal\n"); 
} 
  

void sigint() 
  
{   
    /* reset signal */
    signal(SIGINT, sigint); 
    printf("Child received a SIGINT signal\n"); 
} 
  

void sigquit() 
{ 
    printf("Killed!\n"); 
    exit(0); 
} 