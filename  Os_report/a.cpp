// #include<stdio.h>
// #include <unistd.h>
// #include <ctype.h>
// #include <limits.h>
// #include <string.h>
// #include <stdlib.h>
// #include <unistd.h> 
// int main()
// {
//     int pid = fork();
// if(pid > 0){
//   printf("parent: child = %d\n",pid);
//   pid = wait((int *) 0);
//   printf("child %d is done\n",pid);
// }else if(pid == 0){
//     printf("child : exiting \n");
//     exit(2);
// }
// else{
//     printf("fork error\n");
// }
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  
    // make two process which run same
    // program after this instruction
    fork();
  
    printf("Hello world!\n");
    return 0;
}
// char * argv[3];

// argv[0] = "echo";
// argv[1] = "hello";
// argv[2] = 0;
// exec("/bin/echo",argv);
// printf("exce error\");
// }