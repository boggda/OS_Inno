#include<stdio.h>

int main()
{
  for(int i = 0; i < 3; i++)
  {
    fork();
    sleep(5);
  }

  return 0;
}

/*
   Firstly, initial process will create its copy.
   Next, will be created copy of copy and copy of intial process, and so on.
   In the end we will have 2^n processes. It means 8 process for 3 times loop,
   and 32 processes for 4 times.
*/
