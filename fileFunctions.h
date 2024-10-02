#ifndef FILEFUNCTIONS_H
#define FILEFUNCTIONS_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * Lists the contents of the specified directory.
 * @param path The path of the directory to list.
 */
void list_directory(const char *path);

/**
 * Changes the current working directory to the specified path.
 * @param path The path of the directory to change to.
 */
void change_directory(const char *path);

/**
 * Displays the contents of the specified file.
 * @param filename The name of the file to display.
 */
void display_file(const char *filename);

/**
 * Copies the contents of the source file to the destination file.
 * @param source The path of the source file.
 * @param destination The path of the destination file.
 */
void copy_file(const char *source, const char *destination);

/**
 * Moves or renames the source file to the destination.
 * @param source The path of the source file.
 * @param destination The path of the destination file.
 */
void move_file(const char *source, const char *destination);

/**
 * Deletes the specified file.
 * @param filename The name of the file to delete.
 */
void delete_file(const char *filename);

/**
 * Creates a new directory with the specified name.
 * @param dirname The name of the directory to create.
 */
void create_directory(const char *dirname);

/**
 * Removes the specified directory.
 * @param dirname The name of the directory to remove.
 */
void remove_directory(const char *dirname);

/*
 * Prints current working directory on stout
 */
void print_current_path();

#endif // FILEFUNCTIONS_H
