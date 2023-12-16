#include "shell.h"


void cmdsTokenizer(char *commands, cmd_t *head)
{
	char *lastToken = command;
	char *currentToken = strtok(command, "|&;");
	int i = 0;

	while (currentToken != NULL)
	{
		char *currentCommand = NULL;

		currentCommand = strsplit(lastToken, currentToken);
		argsTokenizer(head, currentCommand);
		
		lastToken = currentToken;
		currentToken = strtok(lastToken, "|&;");
		i++;
	}
	args[i] = NULL;
}


void argsTokenizer()
