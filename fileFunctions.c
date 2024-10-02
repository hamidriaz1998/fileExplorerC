#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void list_directory(const char *path) {
  DIR *dir = opendir(path);
  if (dir == NULL) {
    fprintf(stderr, "Couldn't open the directory");
    return;
  }

  struct dirent **namelist;
  int n = scandir(path, &namelist, NULL, alphasort);
  if (n < 0) {
    fprintf(stderr, "Couldn't read the directory");
    closedir(dir);
    return;
  }

  printf("\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", namelist[i]->d_name);
    free(namelist[i]);
  }
  printf("\n");
  free(namelist);
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
