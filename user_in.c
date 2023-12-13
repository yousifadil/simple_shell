#include "shell.h"

/**
* getting user input function
*/
void check_commands(char *command, size_t size) 
{
	if (getline(&command, &size, stdin) == -1) 
	{
		if (feof(stdin))
		{
			const char newln[] = "\n";
			write(1, newln, sizeof(newln) - 1);
			exit(EXIT_SUCCESS);
		}
		else 
		{
			perror("input error");
			exit(EXIT_FAILURE);
		}
	}

	/*remove newline*/

	command[strcspn(command, "\n")] = '\0';
}
