#include "sort.h"

/**
 * swap_nodes - Swaps a node with its next neighbor in a doubly linked list.
 * @list: Double pointer to the head of the list.
 * @node: Pointer to the node to swap with its next neighbor.
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *next_node = node->next;

	if (node->prev)
		node->prev->next = next_node;
	else
		*list = next_node;

	if (next_node->next)
		next_node->next->prev = node;

	next_node->prev = node->prev;
	node->next = next_node->next;
	next_node->next = node;
	node->prev = next_node;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 * @list: Double pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (swapped)
	{
		swapped = 0;
		while (curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev);
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}
