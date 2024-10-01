#include <dirent.h>
#include <stdio.h>
#include <string.h>
void list_directory(const char *path) {
  struct dirent *de;
  DIR *dir = opendir(path);
  if (dir == NULL) {
    fprintf(stderr, "Couldn't open the directory");
    return;
  }
  while ((de = readdir(dir)) != NULL) {
    printf("%s\n", de->d_name);
  }
  closedir(dir);
  return;
}

void change_directory(const char *path) {
    
}
