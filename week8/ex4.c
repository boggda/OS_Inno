#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

int main()
{
  void *ptr; // pointer to memmory
  struct rusage usage; // struct declaration
  int size = 100 * 1024 * 1024; // 100 MB
  for(int i = 0; i < 10; i++)
  {
    ptr = malloc(size); // allocate 100 MB
    memset(ptr, '\0', size); // fill allocated memmory with zeros
    if (getrusage(RUSAGE_SELF, &usage)) // get usage of current proccess.
      printf("[!] Some error.\n");

    printf("[+] Mem usage: %ld\n", usage.ru_maxrss); // print mem usage
    sleep(1); // wait 1 second
  }
  printf("[+] Done\n");
  return 0;
}
