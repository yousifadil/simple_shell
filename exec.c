#include "shell.h"

void execute_command(const char *command, char *args[])
{
	int argnum = 0;
	char *path = getenv("PATH");
	char *token = strtok(path, ":");

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
	while (args[argnum] != NULL)
	{
		argnum++;
	}
	args[argnum] = NULL;

	if (strchr(command, '/') != NULL)
	{
		execve(command, args, NULL);
		perror("execve error");
		_exit(EXIT_FAILURE);
	}
	if (path == NULL)
	{
		perror("getenv error");
		_exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		char *command_path = malloc(strlen(token) + strlen(command) + 2);
		if (command_path == NULL)
		{
			perror("malloc error");
			_exit(EXIT_FAILURE);
		}

		strcpy(command_path, token);
		strcat(command_path, "/");
		strcat(command_path, command);

		execve(command_path, args, NULL);
		free(command_path);

		token = strtok(NULL, ":");
	}

	/* if execve fails: */
	perror("execve error");
	_exit(EXIT_FAILURE);
}
