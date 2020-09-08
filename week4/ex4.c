#include<stdio.h>
#include<stdlib.h>
#define BUF_SIZE 1024

char command[BUF_SIZE];

void promt()
{
  printf("[root]#> ");
}

void exec_command(char *command)
{
  system(command); // Function system already use fork ana execv.
}


int main()
{
  char command[BUF_SIZE];
  while (1)
  {
    promt();
    fgets(command, BUF_SIZE, stdin);
    exec_command(command);
  }
  return 0;
}
