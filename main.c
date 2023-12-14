#include "shell.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * @env: An array of strings containing the environment variables.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv, char **env)
{
	char *buffer;
	cmd_t *cmds;

	init(&cmds, argv, argc);
	buffer = malloc(sizeof(char) * MAX_BUFFER_SIZE);
	if (buffer == NULL)
	{
		perror("./shell");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (!waitPrompt(buffer, "#cisfun ", 9))
			return (EXIT_SUCCESS);

		if (access(buffer, X_OK) == 0)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execve(buffer, NULL, env) == -1)
				{
					perror("./shell");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(NULL);

			}
		}
		else
		{
			perror("./shell");
		}
	}

	free(buffer);

	return (EXIT_SUCCESS);
}

