#include<stdio.h>
#include<stdlib.h>

struct entry {
  int number; // page number
  char age; // age counter
  int R; // refernce bit
};

/*
 * Function check if page in pageTabel.
 */
int checkPresence(int pageFrames, struct entry* pageTable, int p_number)
{
  for(int i = 0; i < pageFrames; i++) // iterate over all pages
  {
    if (pageTable[i].number == p_number) // if page is found
      return i; // reutrn index of its page in page table
  }
  return -1;
}

/*
 * Functions searche not frequently used page and swaps it with new page
 */
void replace_NFU(int pageFrames, struct entry* pageTable, int p_number)
{
  int min_index = 0;
  int min_age = 256; // max age value+1
  for(int i = 0; i < pageFrames; i++)
  {
    if(pageTable[i].number == -1) // if there are free space in page table
    {
      pageTable[i].number = p_number;
      pageTable[i].age = 0;
      pageTable[i].R = 1; // page was referenced
      return;
    }

    // search for minimal age
    if (pageTable[i].age < min_age)
    {
      min_index = i;
      min_age = pageTable[i].age;
    }
  }
  // replace page with minimal age
  pageTable[min_index].number = p_number;
  pageTable[min_index].age = 0;
  pageTable[min_index].R = 1;
}

/*
 * Functions updates page table
 */
void update_table(int pageFrames, struct entry* pageTable)
{
  for(int i = 0; i < pageFrames; i++)
  {
    if (pageTable[i].number != -1) // check if page in page table
    {
      pageTable[i].age >>= 1; // shift age by one
      if (pageTable[i].R == 1) // if page was refernced
        pageTable[i].age |= 128; // change most significant bit to 1
      pageTable[i].R = 0; // set refernce to 0
    }
  }
}

int main()
{
  int hits = 0, misses = 0, pageFrames = 0;
  struct entry *pageTable;

  puts("[+] NFU Aging simulator [+]");
  printf("Enter numer of page frames: ");
  scanf("%d", &pageFrames);

  // allocate memmory for page table
  pageTable = malloc(sizeof(struct entry)*pageFrames);

  // fill page table with empty pages.
  for (int i = 0; i < pageFrames; i++)
  {
    struct entry e = {-1, 0, 0};
    pageTable[i] = e;
  }

  // open file
  FILE * f = fopen("input.txt", "r");

  if (!f)
  {
    puts("[!] Some error with file!");
    return -1;
  }

  // read from file
  int p_number;
  while (fscanf(f, "%d", &p_number) != EOF)
  {
    // check if page in page table
    int index = checkPresence(pageFrames, pageTable, p_number);
    if (index == -1) // if not
    {
      replace_NFU(pageFrames, pageTable, p_number); // replace NFU page
      misses++; // increase misses
    }
    else
    {
      pageTable[index].R = 1;
      hits++; // increase hits
    }
    update_table(pageFrames, pageTable); // update page table
  }

  printf("[+] hits/misses = %d / %d\n", hits, misses);

  fclose(f);
  return 0;
}
