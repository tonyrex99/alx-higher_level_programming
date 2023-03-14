#include "lists.h"

/**
 * copy_list - copies linked list from one to other
 * @start1: start of list1.
 * Return: linked list 2
 */
listint_t *copy_list(listint_t *start1)
{
	listint_t *temp;

	if (start1 == NULL)
		return (NULL);
	temp = malloc(sizeof(listint_t));
	if (!temp)
		return (NULL);

	temp->n = start1->n;
	temp->next = copy_list(start1->next);

	return (temp);
}


/**
 * reverse_listint - reverses a linked list
 * @head: pointer to the first node in the list
 * Return: pointer to the first node in the new list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *current, *prev, *next;

	current = *head; /*setting the variable current to head*/

	prev = NULL; /*prev variable to null*/

	while (current != NULL)
	{
		next = current->next; /*storing current in next so we dont loose it*/
		current->next = prev; /*reversing the link and pointing &current to prev*/
		prev = current; /*moving the prev variable to current*/
		current = next; /*moving the current to next variable*/
	}

	*head = prev; /*setting the head to prev*/

	return (*head);
}

/**
 * free_list - frees the linked list from memory
 * @head: The pointer to the linked list
 * Return: nothing.
 */
void free_list(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * is_palindrome - Checks whether the list is palindrome
 * @head: head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
/**
 * is_palindrome - Checks whether the list is palindrome
 * @head: head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head;
	int count = 0, i;
	int *stack;

	if (*head == NULL || (*head)->next == NULL)
	{
		return (1);
	}

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		count++;
	}

	stack = malloc(sizeof(int) * count);

	if (!stack)
	{
		return (0);
	}

	for (i = 0; i < count; i++)
	{
		stack[i] = (*head)->n;
		*head = (*head)->next;
	}

	if (fast != NULL)
	{
		slow = slow->next;
	}

	while (slow)
	{
		if (slow->n != stack[--i])
		{
			free(stack);
			return (0);
		}
		slow = slow->next;
	}

	free(stack);
	return (1);
}

