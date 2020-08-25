#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
  int a = INT_MAX;
  float b = FLT_MAX;
  double c = DBL_MAX;

  printf("Int a=%d\nSize of a: %ld\n", a, sizeof(a));
  printf("Float b=%f\nSize of b: %ld\n", b, sizeof(b));
  printf("Double c=%lf\nSize of c: %ld\n", c, sizeof(c));

  return 0;
}
