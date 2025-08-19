#include "regex.h"

/**
 * char_match - checks if current pattern char matches current string char
 * @s: current char in the string (can be '\0')
 * @p: current char in the pattern (not '*')
 *
 * Return: 1 if it matches, 0 otherwise
 */
static int char_match(char s, char p)
{
	if (p == '.')
		return (s != '\0');
	return (s == p && s != '\0');
}

/**
 * regex_match - checks whether a given pattern matches a given string.
 * Supports '.' (any single char) and '*' (zero or more of the preceding char).
 *
 * @str: string to scan (may be empty)
 * @pattern: regex pattern (may be empty, may include '.' and '*')
 *
 * Return: 1 if pattern matches the entire string, 0 otherwise
 */
int regex_match(char const *str, char const *pattern)
{
	/* If pattern is empty, it matches only empty string */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Handle "x*" where '*' refers to preceding token */
	if (pattern[1] == '*')
	{
		/*
		 * Two options:
		 * 1) Use zero occurrence of preceding token -> skip "x*"
		 * 2) If first char matches, consume one char of str and keep "x*"
		 */
		if (regex_match(str, pattern + 2))
			return (1);

		if (char_match(*str, *pattern))
			return (regex_match(str + 1, pattern));

		return (0);
	}
	else
	{
		/* No star following: current chars must match, then advance both */
		if (char_match(*str, *pattern))
			return (regex_match(str + 1, pattern + 1));
		return (0);
	}
}
