#include "shell.h"

/**
 * exe_commands - process the commands
 * @unused_command is intentionally unused command
 *
 * execute_command - execution function
 * @command is the command
 * @args is the arguments
 */
void execute_command(const char *command, char *args[]);
void exe_commands(const char *unused_command, char *args[])
{
	pid_t pid = fork();
	(void)unused_command;

	if (args[0] != NULL && strcmp(args[0], "exit") == 0)
	{
		const char exitMessage[] = "Exiting shell.\n";

		write(1, exitMessage, sizeof(exitMessage) - 1);
		exit(EXIT_SUCCESS);
	}
	if (pid == -1)
	{
		perror("forking error");
		_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* Child process */
		handle_cd(args);
		execute_command(args[0], args);
		_exit(EXIT_SUCCESS);
	}
	else
	{
		/* parent process */
		int status;

		waitpid(pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		{
			if (strcmp(args[0], "cd") == 0 && args[1] != NULL)
			{
				if (chdir(args[1]) != 0)
				{
					perror("chdir error");
				}
			}
		}
	}
	wait(NULL);
}
