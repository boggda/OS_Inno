#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *f = fopen("input_ok.txt", "r"); // open file

  if (!f)
  {
    puts("[!] Some error with file!");
    return -1;
  }

  int resources;
  fscanf(f, "%d", &resources); // get number of resources

  int processes;
  fscanf(f, "%d", &processes); // get number of processes

  int *res_existence = malloc(sizeof(int) * resources);
  for (int i = 0; i < resources; i++)
    fscanf(f, "%d", &res_existence[i]); // read the array of resources in existence

  int *res_available = malloc(sizeof(int) * resources);
  for (int i = 0; i < resources; i++)
    fscanf(f, "%d", &res_available[i]); // read the array of resources available

  int **C = malloc(sizeof(int *) * processes);
  for (int i = 0; i < processes; i++)
  {
    C[i] = malloc(sizeof(int) * resources);
    for (int j = 0; j < resources; j++)
      fscanf(f, "%d", &C[i][j]); // read current allocation matrix
  }

  int **R = malloc(sizeof(int *) * processes);
  for (int i = 0; i < processes; i++)
  {
    R[i] = malloc(sizeof(int) * resources);
    for (int j = 0; j < resources; j++)
      fscanf(f, "%d", &R[i][j]); // read request matrix
  }

  fclose(f);
  // Algo

  int *marked = malloc(sizeof(int) * processes);
  int n_marked = 0;

  for (int i = 0; i < processes; i++)
  {
    int temp_r = 0;
    for (int j = 0; j < resources; j++)
      if (R[i][j] == 0) // if process doesn't request resources
        temp_r++;
      else
        break;

    if (temp_r == resources)
    {
      for (int j = 0; j < resources; j++)
        res_available[j] += C[i][j]; // process terminated
      marked[i] = 1;
      n_marked++;
    }
    else
      marked[i] = 0;
  }

  for (int i = 0; i < processes; i++)
  {
    int flag = 0;
    if (!marked[i])
    {
      for(int j = 0; j < resources; j++)
      {
        if (R[i][j] > res_available[j]) // process requests more than available
        {
          flag = 0;
          break;
        }
        else
          flag = 1;
      }
      if (flag)
      {
        marked[i] = 1;
        n_marked++;
        for (int j = 0; j < resources; j++)
          res_available[j] += C[i][j]; // process terminated
      }
    }
  }

  // Output
  f = fopen("output_ok.txt", "w");

  if (n_marked == processes)
		fprintf(f, "There is no deadlocks\n");
	else
  {
		fprintf(f, "Deadlock processes:\n");
		for (int i = 0; i < processes; i++)
			if (!marked[i])
				fprintf(f, "%d\n", i);
	}
  return 0;
}
