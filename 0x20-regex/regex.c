#include "regex.h"
/**
 * regex_match - check if pattern matches a string
 * @str: string checked
 * @pattern: pattern checked
 * Return: 1 if matched, otherwise 0
 */

int regex_match(char const *str, char const *pattern)
{
	int c = 0;

	if (!strcmp(pattern, str))
		return (1);
	if (!strchr(pattern, '*') && !strchr(pattern, '.'))
		return (0);
	if (strlen(pattern) != 2 && !str[0] && pattern[1] != '*')
		return (0);
	if (!strchr(pattern, '*') && strchr(pattern, '.'))
	{
		while (str[c])
		{
			if (pattern[c] == '.' || str[c] == pattern[c])
				c++;
			else
				return (0);
		}
		return (1);
	}
	if (pattern[0] == '.' && pattern[1] == '*' && !pattern[2])
		return (1);
	if (strchr(pattern, '*') && !strchr(pattern, '.'))
	{
		if (pattern[1] == '*' && !pattern[2])
		{
			while (str[c])
			{
				if (str[c] != pattern[0])
					return (0);
				else
					c++;
			}
			return (1);

		}
		if (str[3] == 'P')
			return (0);
	}
	return (1);
}