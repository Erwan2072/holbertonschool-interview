#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * is_digit - Vérifie si une chaîne contient uniquement des chiffres
 * @s: chaîne à vérifier
 * Return: 1 si c'est valide, 0 sinon
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Calcule la longueur d'une chaîne
 * @s: chaîne
 * Return: longueur
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * print_result - Affiche le résultat, en ignorant les zéros en tête
 * @result: tableau d'entiers représentant le résultat
 * @size: taille du tableau
 */
void print_result(int *result, int size)
{
	int i = 0;

	while (i < size && result[i] == 0)
		i++;

	if (i == size)
		_putchar('0');
	else
	{
		for (; i < size; i++)
			_putchar(result[i] + '0');
	}
	_putchar('\n');
}

/**
 * main - Multiplie deux nombres positifs passés en arguments
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return: 0 si succès, 98 en cas d'erreur
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, mul, sum;
	int *result;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		printf("Error\n");
		exit(98);
	}

	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);

	result = calloc(len1 + len2, sizeof(int));
	if (!result)
		exit(98);

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			sum = result[i + j + 1] + mul;
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	print_result(result, len1 + len2);
	free(result);
	return (0);
}
