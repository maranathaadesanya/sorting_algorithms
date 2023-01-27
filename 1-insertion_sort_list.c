#include "sort.h"

/**
 *insertion_sort_list - sort list
 *
 *@list: list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *behind, *temp;

	if (*list == NULL)
		return;

	current = *list;

	while (current)
	{
		behind = current->prev;

		while (behind && behind->n > current->n)
		{
			temp = behind->prev;
			if (temp)
				temp->next = current;

			if (current->next)
				current->next->prev = behind;

			behind->next = current->next;
			current->next = behind;
			behind->prev = current;
			current->prev = temp;
			behind = temp;

			if (!behind)
				*list = current;

			print_list(*list);
		}
		current = current->next;
	}
}
