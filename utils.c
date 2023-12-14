#include "shell.h"

/**
 * strsplit - Extracts a substring from a given range in a string
 *
 * @strbegin: Pointer to the beginning of the range
 * @strend: Pointer to the end of the range (excluded)
 *
 * Return: A newly allocated string containing the extracted substring,
 *         or NULL if an error occurred
 */
char *strsplit(char *strbegin, char *strend)
{
	char *result = NULL;
	int length = strend - strbegin;

	if (length > 0)
	{
		result = malloc((length + 1) * sizeof(char));
		if (result != NULL)
		{
			int i;

			for (i = 0; i < length; i++)
			{
				result[i] = strbegin[i];
			}
			result[length] = '\0';
		}
	}

	return (result);
}
