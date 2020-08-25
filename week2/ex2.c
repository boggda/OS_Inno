#include <stdio.h>
#include <string.h>
#define BUF_SIZE 1024

int main()
{
  char name[BUF_SIZE];

  puts("[!] Enter string: ");
  fgets(name, BUF_SIZE-1, stdin);

  puts("[+] Reversed string:");

  for(int i = strlen(name)-2; i >= 0; i--)
    putchar(name[i]);
  putchar('\n');

  return 0;
}
