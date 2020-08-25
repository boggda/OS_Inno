#include <stdio.h>

void swap_ints(int *a, int *b);

int main()
{
  int a,b;
  printf("Enter two numbers:\n");
  scanf("%d %d", &a, &b);
  printf("a=%d\tb=%d\n", a, b);
  swap_ints(&a, &b);
  printf("a=%d\tb=%d\n", a, b);
  return 0;
}

void swap_ints(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}


