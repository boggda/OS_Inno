#include <stdio.h>

void triangle1(int n)
{
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < n-i+1; j++)
      printf(" ");
    for(int j = 0; j < 2*i-1; j++)
      printf("*");
    printf("\n");
  }
}

void triangle2(int n)
{
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < i; j++)
      printf("*");
    printf("\n");
  }
}

void triangle3(int n)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j <= i; j++)
      printf("*");
    printf("\n");
  }
  for(int i = 0; i < n-1; i++)
  {
    for(int j = n-i-1; j > 0; j--)
      printf("*");
    printf("\n");
  }
}

void square(int n)
{
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j <= n; j++)
      printf("*");
    printf("\n");
  }
}

void menu()
{
  puts("Choose figure to print:");
  puts("[1] Triangle1");
  puts("[2] Triangle2");
  puts("[3] Triangle3");
  puts("[4] Square");
  puts("[99] EXIT");
  printf("#> ");
}

int main(int argc, char **argv)
{
  int fig, n;
  while (1)
  {
    menu();
    scanf("%d", &fig);

    if (fig == 1)
    {
      printf("Enter height of triangle: ");
      scanf("%d", &n);
      triangle1(n);
    } else if (fig == 2)
    {
      printf("Enter height of triangle: ");
      scanf("%d", &n);
      triangle2(n);
    } else if (fig == 3)
    {
      printf("Enter width of triangle: ");
      scanf("%d", &n);
      triangle3(n);
    } else if (fig == 4)
    {
      printf("Enter size of square: ");
      scanf("%d", &n);
      square(n);
    } else if (fig == 99)
    {
      puts("Goodbye!");
      break;
    }
  }
  return 0;
}


