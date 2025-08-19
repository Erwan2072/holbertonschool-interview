#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * check_substring - check if substring starting at index is valid
 * @s: full string
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 * @start: starting index
 *
 * Return: 1 if valid substring, 0 otherwise
 */
static int check_substring(const char *s, const char **words,
			   int nb_words, int word_len, int start)
{
	int i, j, found;
	int *used = calloc(nb_words, sizeof(int));

	if (!used)
		return (0);

	for (i = 0; i < nb_words; i++)
	{
		found = 0;
		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
			    strncmp(s + start + (i * word_len), words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}
		if (!found)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

/**
 * same_len_words - ensure all words share the same length
 * @words: array of words
 * @nb_words: number of words
 * @len: expected length
 *
 * Return: 1 if all same length, 0 otherwise
 */
static int same_len_words(const char **words, int nb_words, int len)
{
	int i;

	for (i = 0; i < nb_words; i++)
	{
		if ((int)strlen(words[i]) != len)
			return (0);
	}
	return (1);
}

/**
 * collect_indices - scan string for valid substrings
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of words
 * @word_len: length of each word
 * @len_s: length of string
 * @sub_len: total length of concatenated substring
 * @indices: array to store results
 *
 * Return: number of matches found
 */
static int collect_indices(const char *s, const char **words, int nb_words,
			   int word_len, int len_s, int sub_len, int *indices)
{
	int i, count = 0;

	for (i = 0; i <= len_s - sub_len; i++)
	{
		if (check_substring(s, words, nb_words, word_len, i))
			indices[count++] = i;
	}
	return (count);
}

/**
 * find_substring - find all starting indices of substrings
 * containing all words exactly once
 * @s: string to scan
 * @words: array of words
 * @nb_words: number of words
 * @n: address to store number of indices found
 *
 * Return: allocated array of indices, or NULL
 */
int *find_substring(const char *s, const char **words, int nb_words, int *n)
{
	int len_s, word_len, sub_len, *indices, count, max_candidates;

	if (n)
		*n = 0;
	if (!s || !words || nb_words <= 0 || !n)
		return (NULL);

	word_len = (int)strlen(words[0]);
	if (word_len == 0 || !same_len_words(words, nb_words, word_len))
		return (NULL);

	len_s = (int)strlen(s);
	sub_len = word_len * nb_words;
	if (len_s < sub_len)
		return (NULL);

	max_candidates = len_s - sub_len + 1;
	indices = malloc(sizeof(int) * max_candidates);
	if (!indices)
		return (NULL);

	count = collect_indices(s, words, nb_words,
		word_len, len_s, sub_len, indices);

	if (count == 0)
	{
		free(indices);
		return (NULL);
	}

	*n = count;
	return (indices);
}
