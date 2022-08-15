#include "sort.h"

/**
 * list_len - returns the length of a linked list
 * @h: pointer to the list
 *
 * Return: length of list
 */

int list_len(listint_t *h)
{
	int len = 0;

	while (h)
	{
		len++;
		h = h->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 *                       ascending order using the Insertion sort algorithm
 * @list: double pointer to list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *one = NULL, *two = NULL;
	listint_t *three = NULL, *four = NULL;

	if (!list || !(*list) || list_len(*list) < 2)
		return;

	current = *list;
	while (current)
	{
		if (current->prev && current->n < current->prev->n)
		{
			one = current->prev->prev;
			two = current->prev;
			three = current;
			four = current->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*list = three;
			two->prev = three;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			current = current->next;
	}
}
