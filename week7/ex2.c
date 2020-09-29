#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n; // declare varible

  scanf("%d", &n); // enter number of elements in the array

  int *array = calloc(n, sizeof(int)); // allocate an array of n elements in the heap and fill it with zeros

  for (int i = 0; i < n; i++) // fill array with increasing numbers
  {
    array[i] = i;
    printf("%d ", array[i]); // print array content
  }
  putchar('\n');

  free(array); // deallocate memmory
  array = NULL; // null the pointer

  return 0;
}
