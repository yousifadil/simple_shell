#include "shell.h"

/**
 * getting user input function and dealing with eof
 *
 * check_commands - checks user input commands
 *
 * @command : the command
 * @size : size of command
 */

void check_commands(char *command, size_t size)
{
	size_t len = strlen(command);

	if (getline(&command, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("input error");
			exit(EXIT_FAILURE);
		}
	}

	/*remove newline : */

	if (len > 0 && command[len - 1] == '\n')
	{
		command[len - 1] = '\0';
	}
}
