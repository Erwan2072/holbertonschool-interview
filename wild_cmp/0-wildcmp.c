#include "holberton.h"

/**
 * wildcmp - Compare two strings with support for '*' wildcard
 * @s1: First string
 * @s2: Second string (may contain '*')
 *
 * Return: 1 if strings can be considered identical, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    if (*s2 == '*')
    {
        // Skip all '*' characters recursively
        while (*s2 == '*')
            return (wildcmp(s1, s2 + 1));

        if (*s2 == '\0')
            return (1);

        if (*s1 == '\0')
            return (0);

        // Try to match current s1 with the rest of s2
        if (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1))
            return (1);

        return (0);
    }

    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    return (0);
}
