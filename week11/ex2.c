#include <stdio.h>
#include <stdlib.h>

int main()
{
  setvbuf(stdin, NULL, _IOLBF, 6); // set line buffer size to 6
  printf("H"); // print H
  sleep(1); // sleep 1 sec
  printf("e");
  sleep(1);
  printf("l");
  sleep(1);
  printf("l");
  sleep(1);
  printf("o");
  sleep(1);
  return 0;
}
