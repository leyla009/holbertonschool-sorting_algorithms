#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		tmp = current->next;
		insertion_point = current->prev;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			/* Detach current */
			if (current->next != NULL)
				current->next->prev = insertion_point;
			insertion_point->next = current->next;

			/* Attach current before insertion_point */
			current->prev = insertion_point->prev;
			current->next = insertion_point;

			if (insertion_point->prev != NULL)
				insertion_point->prev->next = current;
			else
				*list = current;

			insertion_point->prev = current;
			insertion_point = current->prev;

			print_list(*list);
		}
		current = tmp;
	}
}
