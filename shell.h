#ifndef SHELL_H_INCLUDED
#define SHELL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_BUFFER_SIZE 1024

int cmdStartsWithExit(const char *cmd);
int waitPrompt(char *buffer, char *prompt, int promptCount);

char *strsplit(char *strbegin, char *strend);

typedef struct commandsList
{
	char *op;
	char *cmd;
	char **args;
	cmd_t *next;
} cmd_t;





#endif // SHELL_H_INCLUDED

