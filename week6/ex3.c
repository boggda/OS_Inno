#include <stdio.h>

#define MAX_PROCS 1024

/*
 * Print all computed metrics
 */
void print_stats(int n, int WT[], int CT[], int TAT[], double avgTAT, double avgWT)
{
  printf("[P#]\t[WT]\t[CT]\t[TAT]\n");
  for (int i = 0; i < n; i++)
    printf("P%d\t%d\t%d\t%d\n", i+1, WT[i], CT[i], TAT[i]);
  printf("Avg turn around time = %f\n", avgTAT);
  printf("Avg waiting time = %f\n", avgWT);
}

/*
 *  Compute all metrics for round robin algo
 */
void scheduler(int n, int quantum, int burst_time[], int arrival_time[], int WT[], int CT[], int TAT[])
{
  int totalTAT = 0, totalWT = 0;
  int temp[MAX_PROCS];

  // remainig time
  for (int i = 0; i < n; i++)
    temp[i] = burst_time[i];

  // simulate round robin
  int totalTime = 0, i = 0, flag = 0, p = n;
  while(p != 0)
  {
    if(temp[i] <= quantum && temp[i] > 0)
    {
      totalTime += temp[i];
      temp[i] = 0;
      flag = 1;
    }
    else if(temp[i] > 0)
    {
      temp[i] -= quantum;
      totalTime += quantum;
    }

    if(temp[i] == 0 && flag == 1)
    {
      p--;
      // compute TAT, CT and WT for currnet process
      TAT[i] = totalTime - arrival_time[i];
      WT[i] = totalTime - arrival_time[i] - burst_time[i];
      CT[i] = totalTime;
      totalWT += totalTime - arrival_time[i] - burst_time[i];
      totalTAT += totalTime - arrival_time[i];
      flag = 0;
    }

    if(i == n - 1)
      i = 0;
    else if(arrival_time[i + 1] <= totalTime)
      i++;
    else
      i = 0;
  }

  // compute avarge TAT and WT
  double avgTAT = totalTAT * 1.0 / n;
  double avgWT = totalWT * 1.0 / n;

  print_stats(n, WT, CT, TAT, avgTAT, avgWT);
}

/*
 * Sort processes by arrival time
 */
void sortByTime(int arrival_time[], int burst_time[], int n)
{
   int i, j, temp;
   for (i = 0; i < n-1; i++)
   {
     for (j = 0; j < n-i-1; j++)
     {
       if (arrival_time[j] > arrival_time[j+1])
       {
         temp = arrival_time[j];
         arrival_time[j] = arrival_time[j+1];
         arrival_time[j+1] = temp;
         temp = burst_time[j];
         burst_time[j] = burst_time[j+1];
         burst_time[j+1] = temp;
       }
     }
   }
}

int main()
{
  int n;
  int quantum;
  int burst_time[MAX_PROCS];
  int arrival_time[MAX_PROCS];
  int CT[MAX_PROCS];
  int TAT[MAX_PROCS];
  int WT[MAX_PROCS];

  puts("[round robin algo simulator]");
  printf("[enter number of processes]> ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("[enter arrival time of processes %d]> ", i+1);
    scanf("%d", &arrival_time[i]);
    printf("[enter burst time of processes %d]> ", i+1);
    scanf("%d", &burst_time[i]);
  }

  printf("[enter time quantum]> ");
  scanf("%d", &quantum);

  sortByTime(arrival_time, burst_time, n);

  scheduler(n, quantum, burst_time, arrival_time, WT, CT, TAT);

  return 0;
}
