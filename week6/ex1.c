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
 *  Compute all metrics for FCFS algo
 */
void scheduler(int n, int burst_time[], int arrival_time[], int WT[], int CT[], int TAT[])
{
  int totalTAT = 0, totalWT = 0;

  // Compute waiting time for each process and total waiting time
  WT[0] = arrival_time[0];
  for (int i = 1; i < n; i++)
  {
    WT[i] =  burst_time[i-1] + WT[i-1];
    totalWT += WT[i];
  }

  // Compute turn around time for each process and total turn around time
  for (int i = 0; i < n; i++)
  {
      TAT[i] = burst_time[i] + WT[i];
      totalTAT += TAT[i];
  }

  // Compute completion time
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    sum += burst_time[i];
    CT[i] = sum;
  }

  // Compute avarge turn around time
  // and waiting time
  double avgTAT = totalTAT / n;
  double avgWT = totalWT / n;

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
  int burst_time[MAX_PROCS];
  int arrival_time[MAX_PROCS];
  int CT[MAX_PROCS];
  int TAT[MAX_PROCS];
  int WT[MAX_PROCS];

  puts("[FCFS algso simulator]");
  printf("[enter number of processes]> ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
  {
    printf("[enter arrival time of processes %d]> ", i+1);
    scanf("%d", &arrival_time[i]);
    printf("[enter burst time of processes %d]> ", i+1);
    scanf("%d", &burst_time[i]);
  }

  sortByTime(arrival_time, burst_time, n);

  scheduler(n, burst_time, arrival_time, WT, CT, TAT);

  return 0;
}
