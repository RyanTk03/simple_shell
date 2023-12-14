#include "shell.h"

/**
 * cmdStartsWithExit - Vérifie si une chaîne commence par "exit ".
 * @cmd: La chaîne à vérifier.
 *
 * Return: 1 si la chaîne commence par "exit ", 0 sinon.
 */
int cmdStartsWithExit(const char *cmd)
{
	const char *prefix = "exit ";
	int i;

	for (i = 0; prefix[i] != '\0'; i++)
	{
		if (cmd[i] != prefix[i])
			return (0);
	}

	return (1);
}

/**
 * waitPrompt - Attend une entrée utilisateur avec un message de prompt.
 * @buffer: Le tampon pour stocker l'entrée utilisateur.
 * @prompt: Le message de prompt à afficher.
 * @promptCount: Le nombre de caractères dans le message de prompt.
 *
 * Return: 1 si une entrée utilisateur valide est lue, 0 sinon.
 */
int waitPrompt(char *buffer, char *prompt, int promptCount)
{
	ssize_t read;
	size_t initSize = MAX_BUFFER_SIZE;

	write(1, prompt, promptCount);

	read = getline(&buffer, &initSize, stdin);
	if (read == -1 || cmdStartsWithExit(buffer))
	{
		write(1, "\n", 1);
		return (0);
	}

	buffer[read - 1] = '\0';
	return (1);
}

