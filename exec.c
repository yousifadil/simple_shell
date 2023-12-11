#include "shell.h"

void execute_command(const char *command, char *args[])
{
//execute other commands using execve
if (strcmp(command,"env") == 0)
{
char **env = environ;
while (*env != NULL)
{
write(STDOUT_FILENO, *env, strlen(*env));
write(STDOUT_FILENO, "\n", 1);
env++;
}
exit(EXIT_SUCCESS);
}
int argnum = 0;
while (args[argnum] != NULL)
{
argnum++;
}
args[argnum] = NULL;// Ensure args is terminated with a NULL pointer

if (strchr(command, '/') != NULL)
{
execve(command, args, NULL);
perror("execve error");
_exit(EXIT_FAILURE);
}
char *path = getenv("PATH");
if (path == NULL)
{
perror("getenv error");
_exit(EXIT_FAILURE);
}

char *token = strtok(path, ":");
while (token != NULL)

char *command_path = malloc(strlen(token) + strlen(command) + 2);
if (command_path == NULL)
{
perror("malloc error");
_exit(EXIT_FAILURE);
}

strcmp(command_path, token);
strcat(command_path, "/");
strcat(command_path, command);

execve(command_path, args, NULL);
free(command_path);

token = strtok(NULL, ":");
}

//if execve fails
perror("execve error");
_exit(EXIT_FAILURE);
}
