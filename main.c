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
	char input[1024];
	//cmd_t *commands;
	//int status;

	//init(&commands, argv, argc);

	//status = shell_run(commands);
	for (int i = 0; i < argc; i++)
	{
        	printf("Argument %d: %s\n", i, argv[i]);
	}

	if (fgets(input, sizeof(input), stdin) != NULL)
	{
		// Afficher l'entrée
        	printf("Entrée reçue : %s", input);
	}

	return (0);
}

