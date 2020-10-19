#include <stdio.h> 
#include <time.h> 
  
int main() 
{ 
    time_t s, val = 1; 
    struct tm* currenttime; 
  
    s = time(NULL); 
  
    currenttime = localtime(&s); 
  
    printf("%02d:%02d:%02d", 
           currenttime->tm_hour, 
           currenttime->tm_min, 
           currenttime->tm_sec); 
  
    return 0; 
} 