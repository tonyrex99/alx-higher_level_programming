#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* print_listint - Prints all the elements of a listint_t list */
size_t print_listint(const listint_t *h);

/* add_nodeint_end - Adds a new node at the end of a listint_t list */
listint_t *add_nodeint_end(listint_t **head, const int n);

/* free_listint - Frees a listint_t list */
void free_listint(listint_t *head);

/* is_palindrome - Checks whether a listint_t list is a palindrome */
int is_palindrome(listint_t **head);

#endif /* LISTS_H */

