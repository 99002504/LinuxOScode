#include <stdio.h> 
#include <sys/resource.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
  
int main() { 
  
    struct rlimit oldlimit, lim, newlimit; 
  
    // Get old limits 
    if( getrlimit(RLIMIT_NOFILE, &oldlimit) == 0) 
        printf("Old limits -> soft limit= %ld \t"
           " hard limit= %ld \n", oldlimit.rlim_cur,  
                                 oldlimit.rlim_max); 
    else
        fprintf(stderr, "%s\n", strerror(errno)); 
      
    // new value 
    lim.rlim_cur = 3; 
    lim.rlim_max = 1024; 
  
    // limits 
    if(setrlimit(RLIMIT_NOFILE, &lim) == -1) 
        fprintf(stderr, "%s\n", strerror(errno)); 
      
    // new limits 
    if( getrlimit(RLIMIT_NOFILE, &newlimit) == 0) 
        printf("New limits -> soft limit= %ld "
         "\t hard limit= %ld \n", newlimit.rlim_cur,  
                                  newlimit.rlim_max); 
    else
        fprintf(stderr, "%s\n", strerror(errno)); 
    return 0; 
} 