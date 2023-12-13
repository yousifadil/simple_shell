#include "shell.h"

void execute_command(const char *command, char *args[]);

void exe_commands(const char *command, char *args[])
{
    if (args[0] != NULL && strcmp(args[0], "exit") == 0)
    {
        const char exitMessage[] = "Exiting shell.\n";

        write(1, exitMessage, sizeof(exitMessage) - 1);
        exit(EXIT_SUCCESS);
    }

    pid_t pid = fork();

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
    }
    else
    {
        /* Parent process */
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
}
