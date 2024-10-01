#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
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
void print_current_path() {
  char buffer[256];
  printf("Current Path: %s\n", getcwd(buffer, sizeof(buffer)));
}

void change_directory(const char *path) {
  if (chdir(path) != 0) {
    fprintf(stderr, "Couldn't change directory\n");
  }
  print_current_path();
}
