#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
  char *this_is_a_nice_day = "This is a nice day"; // buffer with string
  struct stat buffer; // struct with file stats
  void *ptr; // pointer to mmaped memory
  int len = strlen(this_is_a_nice_day) + 1; // length of the string

  int f = open("ex1.txt", O_RDWR); // open file with read/write access mode.

  fstat(f, &buffer); // get stats of file ex1.txt

  ptr = mmap(0, buffer.st_size, PROT_WRITE, MAP_SHARED, f, 0); // map file to the memory
  memset(ptr, 0, buffer.st_size); // clear mmaped file

  ftruncate(f, len); // truncate size of file to the length of string

  sprintf(ptr, "%s\n", this_is_a_nice_day); // write string to the mmaped file
  munmap(ptr, buffer.st_size); // free mmaped region

  close(f); // close file
  return 0;
}
