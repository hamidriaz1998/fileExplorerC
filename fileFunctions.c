#include <dirent.h>
#include <libgen.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned char byte_t;

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
  printf("%s\n", getcwd(buffer, sizeof(buffer)));
}

void change_directory(const char *path) {
  if (chdir(path) != 0) {
    fprintf(stderr, "Error Changing directory\n");
  }
  print_current_path();
}

void display_file(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening the file: %s", filename);
    return;
  }
  char c;
  while (1) {
    c = fgetc(fp);
    if (c == EOF) {
      break;
    }
    printf("%c", c);
  }
  printf("\n");
  fclose(fp);
}

void copy_file(const char *source, const char *destination) {
  FILE *in = fopen(source, "r");
  FILE *out = fopen(destination, "w");
  byte_t buffer[128];
  size_t readBytes, writeBytes;
  while ((!feof(in))) {
    readBytes = fread(buffer, sizeof(byte_t), 128, in);
    if (readBytes > 0) {
      writeBytes = fwrite(buffer, sizeof(byte_t), readBytes, out);
    }
    if (readBytes != writeBytes) {
      fputs("Mismatch\n", stderr);
      return;
    }
  }
}

void delete_file(const char *filename) {
  if (remove(filename) != 0) {
    fprintf(stderr, "Error deleting the source file\n");
  }
}

void move_file(const char *source, const char *destination) {
  char src_path[256], dest_path[256];
  realpath(source, src_path);
  realpath(destination, dest_path);

  char *src_dir = dirname(strdup(src_path));
  char *dest_dir = dirname(strdup(dest_path));

  if (strcmp(src_dir, dest_dir) == 0) {
    if (rename(source, destination) != 0) {
      fprintf(stderr, "Error renaming file\n");
    }
  } else {
    copy_file(source, destination);
    delete_file(source);
  }
}
