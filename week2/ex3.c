#include <stdio.h>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: %s n\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);

  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < n-i+1; j++)
      printf(" ");
    for(int j = 0; j < 2*i-1; j++)
      printf("*");
    printf("\n");
  }
  return 0;
}
