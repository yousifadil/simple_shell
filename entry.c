#include "shell.h"

/**
 * main - entry point
 *
 * Return: 0 - success.
 */

int main(void)
{
    char command[128];
    char *args[128];

    while (true)
    {
        show_prompt();
        check_commands(command, sizeof(command));

        int argnum = 0;
        char *token = strtok(command, " ");
        while (token != NULL)
        {
            args[argnum++] = token;
            token = strtok(NULL, " ");
        }
        args[argnum] = NULL;

        exe_commands(args[0], args);
    }

    return 0;
}
