#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *realloc_boggda(void *ptr, size_t size)
{
  void *new_ptr;

  if (ptr == NULL) // if ptr is NULL, call malloc
    return malloc(size);

  if (size == 0) // if size is equal to zero, call free
  {
    free(ptr);
    return NULL;
  }

  new_ptr = malloc(size); // allocate new chunk of memory without initialization
  memcpy(new_ptr, ptr, size); // copy old content to the allocated memory

  free(ptr); // free old chunk
  ptr = NULL;

  return new_ptr; // return allocated chunk
}

int main()
{
  // Allows user to specify the original array size, stored in variable n1.
	printf("Enter original array size: ");
	int n1 = 0;
	scanf("%d", &n1);

	//Create a new array of n1 ints
	int* a1 = calloc(n1, sizeof(int));
	int i;
	for(i = 0; i < n1; i++)
  {
		//Set each value in a1 to 100
		a1[i] = 100;
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}

	//User specifies the new array size, stored in variable n2.
	printf("\nEnter new array size: ");
	int n2 = 0;
	scanf("%d", &n2);

	//Dynamically change the array to size n2
	a1 = realloc_boggda(a1, n2*sizeof(int));

	for(i = 0; i < n2; i++)
  {
		//Print each element out (to make sure things look right)
		printf("%d ", a1[i]);
	}
	printf("\n");

  return 0;
}
