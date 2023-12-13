
/**
 * handle_cd - handle cd command
 * @args : arguments
 */
void handle_cd(char *args[])
{
	if (strcmp(args[0], "cd") == 0)
	{
		if (args[1] != NULL)
		{
			if (chdir(args[1]) != 0)
			{
				perror("chdir error");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			const char *home = getenv("HOME");

			if (home == NULL)
			{
				perror("getenv error");
				_exit(EXIT_FAILURE);
			}

			if (chdir(home) != 0)
			{
				perror("chdir error");
				_exit(EXIT_FAILURE);
			}
		}
		_exit(EXIT_SUCCESS);
	}
}
