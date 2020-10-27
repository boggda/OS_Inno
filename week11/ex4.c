#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

int main()
{
  struct stat buffer_src; // struct with file stats
  void *ptr_src; // pointer to mmaped memory
  void *ptr_dst; // pointer to mmaped memory

  int src = open("ex1.txt", O_RDWR); // open file with read/write access mode.
  fstat(src, &buffer_src); // get stats of source file
  ptr_src = mmap(0, buffer_src.st_size, PROT_READ, MAP_PRIVATE, src, 0); // map file to the memory

  int dst = open("ex1.memcpy.txt", O_RDWR | O_CREAT, 0644); // open destination file with r/w access mode

  ftruncate(dst, buffer_src.st_size); // truncate size of destination file to the size of source file

  ptr_dst = mmap(0, buffer_src.st_size, PROT_WRITE, MAP_SHARED, dst, 0); // map file to the memory

  memcpy(ptr_dst, ptr_src, buffer_src.st_size); // copy content of source file to the destination file

  munmap(ptr_src, buffer_src.st_size); // free mmaped region
  munmap(ptr_dst, buffer_src.st_size); // free mmaped region

  close(src); // close file
  close(dst); // close file
  return 0;
}
