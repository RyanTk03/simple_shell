#include "shell.h"

/**
 * cmd_add - that adds a new node at the beginning of a cmd_t list.
 *
 * @head: the head of the list.
 * @command: the string value of the command.
 * @args: the arguments.
 * @op: the operator used before this command.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *cmd_add(cmd_t **head, char *command, char **args, char *op)
{
	cmd_t *newCmd = malloc(sizeof(cmd_t));

	if (!newCmd)
		return (NULL);

	newCmd->str = strdup(str);
	newCmd->len = strlen(str);
	newCmd->next = *head;

	*head = newCmd;

	return (newCmd);
}

/**
 * cmd_next - retrives next elements.
 *
 * @head: the head of the list.
 */
cmd_t* cmd_next(cmd_t **head)
{
	cmd_t *next = *head;

	*head = next->next;

	return (next);
}

/**
 * cmd_free - free memory allocated for a cmd_t element.
 *
 * @elt:  elt.
 */
void cmd_free(cmd_t *elt)
{
	if (elt)
	{
		if (elt->args)
			free(elt->args);

		if (elt->cmd)
			free(elt->cmd);
		free(elt);
	}
}
