#include<stdio.h>
#include<string.h>

#define MAX_ARRAY_LEN 1024

void bubble_sort(int *array,int size);

int main()
{
  int array[MAX_ARRAY_LEN];
  int size = 0;
  puts("[!] Hello to bubble sort! [!]");
  printf("Enter size of an array: ");
  scanf("%d", &size);
  for(int i = 0; i < size; i++)
  {
    printf("array[%d]= ", i);
    scanf("%d", &array[i]);
  }

  puts("[+] Sorting array.");
  bubble_sort(array, size);

  puts("[+] Array after sorting:");
  for(int i = 0; i < size; i++)
  {
    printf("%d ", array[i]);
  }
  putchar('\n');

  return 0;
}

void bubble_sort(int *array, int size){
    int temp = 0;

    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1 ; ++j) {
            if( array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
