#include "lists.h"
#include <stdlib.h>

#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - Reverse a linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the linked list.
 *
 * Return: 1 if the linked list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head, *first_half, *second_half;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    /* 1. Trouver le milieu de la liste */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* 2. Inverser la seconde moitié */
    second_half = reverse_list(slow);
    first_half = *head;

    /* 3. Comparer les deux moitiés */
    while (second_half)
    {
        if (first_half->n != second_half->n)
            return (0);
        first_half = first_half->next;
        second_half = second_half->next;
    }

    return (1);
}
