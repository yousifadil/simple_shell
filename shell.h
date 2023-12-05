#ifndef SHELL_H
#define SHELL_H
/*
 * header files
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
/*
 * header file
 */
void show_prompt(void);
void check_commands(char *command, size_t size);
void exe_commands(const char *command, char *args[]);
void execvp_in_path(const char *file, char *args[]);

#endif /* SHELL_H */
