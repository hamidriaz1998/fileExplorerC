#include "fileFunctions.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int main() {
  char buffer[256];
  char *args[10];
  system("clear");
  while (1) {
    printf("file_explorer> ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
      break;
    }
    // Remove newline char
    buffer[strcspn(buffer, "\n")] = 0;

    // Tokenize
    int arg_count = 0;
    char *token = strtok(buffer, " ");
    while (token != NULL && arg_count < 10) {
      args[arg_count++] = token;
      token = strtok(NULL, " ");
    }
    if (strcmp(args[0], "ls") == 0) {
      list_directory(arg_count > 1 ? args[1] : ".");
    } else if (strcmp(args[0], "cd") == 0) {
      change_directory(arg_count > 1 ? args[1] : ".");
    } else if (strcmp(args[0], "cat") == 0) {
      display_file(args[1]);
    } else if (strcmp(args[0], "cp") == 0) {
      copy_file(args[1], args[2]);
    } else if (strcmp(args[0], "mv") == 0) {
      move_file(args[1], args[2]);
    } else if (strcmp(args[0], "rm") == 0) {
      delete_file(args[1]);
    } else if (strcmp(args[0], "mkdir") == 0) {
      create_directory(args[1]);
    } else if (strcmp(args[0], "rmdir") == 0) {
      remove_directory(args[1]);
    } else if (strcmp(args[0], "pwd") == 0) {
      print_current_path();
    } else if (strcmp(args[0], "clear") == 0) {
      system("clear");
    } else if (strcmp(args[0], "exit") == 0) {
      break;
    } else {
      printf("Unknown command: %s\n", args[0]);
    }
  }
  return 0;
}
