#include<stdio.h>

int main()
{
  int n = 0xdead;
  int pid = fork();
  if (pid > 0)
    printf("Hello from parent [%d - %d]\n", pid, n);
  else
    printf("Hello from child [%d - %d]\n", pid, n);
  return 0;

  /*
  PID 0 means that is child process.
  We have different pids in different versions for parrent process.
  */
}
