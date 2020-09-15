#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 32
int buffer[BUFFER_SIZE];
int count = 0;
pthread_cond_t buf_full, buf_empty;

void *consumer(void *n)
{
  while (1)
  {
    if (count == 0)
    {
      puts("Consumer goes sleep. Zzzzzzz.");
      sleep(1); // 10 sec
    }

    buffer[count--] = 0;
    printf("Item consumed: %d\n", count);
    if (count == BUFFER_SIZE - 1)
    {
      puts("Free space available in the buffer.\nWake up producer!");
      pthread_cond_signal(&buf_empty);
    }

  }
  return NULL;
}

void *producer(void *n)
{
  while (1)
  {
    if (count == BUFFER_SIZE)
    {
      puts("Producer goes sleep. Zzzzzzz.");
      sleep(1); // 10 sec
    }

    buffer[count++] = 1;
    printf("Item produced: %d \n", count);
    if (count == 1)
    {
      puts("Item available in the buffer.\nWake up consumer!");
      pthread_cond_signal(&buf_full);
    }
  }
  return NULL;
}

int main()
{
  pthread_t p, c;
  pthread_cond_init(&buf_full, 0);
  pthread_cond_init(&buf_empty, 0);

  pthread_create(&p, NULL, producer, NULL);
  pthread_create(&c, NULL, consumer, NULL);

  pthread_join(p, 0);
  pthread_join(c, 0);

  return 0;
}
