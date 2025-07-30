#include "holberton.h"

/**
 * wildcmp - Compare two strings, allowing '*' to match any string
 * @s1: First string
 * @s2: Second string, may contain the wildcard '*'
 *
 * Return: 1 if considered identical, otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
    // If both strings reach the end, they match
    if (*s1 == '\0' && *s2 == '\0')
        return (1);

    // If current character in s2 is '*'
    if (*s2 == '*')
    {
        // Move past multiple '*' (treat "***" as one '*')
        while (*s2 == '*')
            s2++;

        // If the '*' is at the end of s2, it matches the rest of s1
        if (*s2 == '\0')
            return (1);

        // Try all positions in s1 until a match is found
        while (*s1 != '\0')
        {
            if (wildcmp(s1, s2))
                return (1);
            s1++;
        }

        // If no match found, return false
        return (0);
    }

    // If characters match, move forward in both strings
    if (*s1 == *s2)
        return (wildcmp(s1 + 1, s2 + 1));

    // Otherwise, characters don't match and no '*', return false
    return (0);
}
