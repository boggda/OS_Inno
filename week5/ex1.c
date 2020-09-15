#include <stdio.h>
#include <pthread.h>

void *function(void *num)
{
  printf("Hello from thread %d!\n", (int) num);

  return NULL;
}


int main()
{
  int n = 6;
  pthread_t th;

  for (int i = 0; i < n; i++)
  {
    printf("Creating thread number: %d.\n", i);
    pthread_create(&th, NULL, function, (void *)i);
    pthread_join(th, NULL);
  }

  //pthread_join(th, NULL);
  return 0;
}
