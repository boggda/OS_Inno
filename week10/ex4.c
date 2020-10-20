#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/*
 * Find file in current direcory with same i-node and different name.
 */
void find_same(ino_t inode, char *name)
{
  struct stat statbuf;
  DIR *dirp;
  struct dirent *dp;

  dirp = opendir("."); // open currnt directory
  if (dirp == NULL)
    return;

  while ((dp = readdir(dirp)) != NULL) // check files one by one
  {
    if (lstat(dp->d_name, &statbuf) == -1) // get stat structure for a file
    {
      puts("ERROR!");
      continue;
    }
    if (statbuf.st_mode & S_IFMT != S_IFDIR) // check if file is directory
      continue;

    if ((statbuf.st_ino == inode) && (strcmp(dp->d_name, name)))
      printf("\t%s\n", dp->d_name); // print filename
  }
  closedir(dirp); // close dir
}

/*
 * Iterate over all files in tmp directory.
 */
void iterate()
{
  DIR *dirp;
  struct dirent *dp;
  struct stat statbuf;

  dirp = opendir("./tmp/"); // open tmp directory
  if (dirp == NULL)
    return;

  chdir("./tmp/"); // enter tmp directory
  while ((dp = readdir(dirp)) != NULL)
  {
    if (lstat(dp->d_name, &statbuf) == -1) // get stat structure for a file
    {
      puts("ERROR!");
      continue;
    }
    if (statbuf.st_mode & S_IFMT != S_IFDIR) // check if file is directory
      continue;

    if (statbuf.st_nlink > 1) // check if hard link counter greater then 1
    {
      printf("%s:\n", dp->d_name); // print filename
      find_same(statbuf.st_ino, dp->d_name); // find file with same inode
    }
  }
  closedir(dirp); // close tmp directory
}

/*
 * Main function.
 */
int main()
{
  iterate();
  return 0;
}
