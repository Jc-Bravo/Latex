# Introduciton and Examples
## why hard / intereting
- efficient
- POWERFUL
- FLEXBLE
xv6 : Os
RISV - v : microprocessor (微处理器)
QEMU : mechine simulator(under linux)
>grep (global search regular expression(RE) and print out the line
cat（“ concatenate ”的缩写）命令是Linux / Unix等操作系统中最常用的命令之一。 cat命令允许我们创建单个或多个文件，查看文件包含，连接文件以及在终端或文件中重定向输出。
## system calls
```C
//wirtten by JC in 4.4/2022
//copy.c : copy input to output

#include"Kernel/types.h"
#include"user/user.h"

int 
main()
{
    char buf[64];

    while(1){
        int n = read(0 , buf , sizeof)(buf));//0 L console input
        if(n <= 0)
            break;
        write(1 , buf , n);//1 console output
    }

    exit(0);
}
```
```C
1	// Test that fork fails gracefully.
     2	// Tiny executable so that the limit can be filling the proc table.
     3	
     4	#include "kernel/types.h"
     5	#include "kernel/stat.h"
     6	#include "user/user.h"
     7	
     8	#define N  1000
     9	
    10	void
    11	print(const char *s)
    12	{
    13	  write(1, s, strlen(s));
    14	}
    15	
    16	void
    17	forktest(void)
    18	{
    19	  int n, pid;
    20	
    21	  print("fork test\n");
    22	
    23	  for(n=0; n<N; n++){
    24	    pid = fork();
    25	    if(pid < 0)
    26	      break;
    27	    if(pid == 0)
    28	      exit(0);
    29	  }
    30	
    31	  if(n == N){
    32	    print("fork claimed to work N times!\n");
    33	    exit(1);
    34	  }
    35	
    36	  for(; n > 0; n--){
    37	    if(wait(0) < 0){
    38	      print("wait stopped early\n");
    39	      exit(1);
    40	    }
    41	  }
    42	
    43	  if(wait(0) != -1){
    44	    print("wait got too many\n");
    45	    exit(1);
    46	  }
    47	
    48	  print("fork test OK\n");
    49	}
    50	
    51	int
    52	main(void)
    53	{
    54	  forktest();
    55	  exit(0);
    56	}
```