#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  void *ptr; // pointer to memmory
  int size = 100 * 1024 * 1024; // 100 MB
  for(int i = 0; i < 10; i++)
  {
    ptr = malloc(size); // allocate 100 MB
    memset(ptr, '\0', size); // fill allocated memmory with zeros
    sleep(1); // wait 1 second
  }
  printf("[+] Done\n");
  return 0;
}
