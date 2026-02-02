#include "deck.h"
#include <string.h>

/**
 * get_value - Assigns a numerical weight to a card value string.
 * @card: Pointer to the card.
 *
 * Return: Integer 1 (Ace) through 13 (King).
 */
int get_value(const card_t *card)
{
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
			  "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(card->value, values[i]) == 0)
			return (i + 1);
	}
	return (0);
}

/**
 * card_cmp - Comparison function for qsort.
 * @a: First node.
 * @b: Second node.
 *
 * Return: Difference in kind or value.
 */
int card_cmp(const void *a, const void *b)
{
	const deck_node_t *node1 = *(const deck_node_t **)a;
	const deck_node_t *node2 = *(const deck_node_t **)b;
	int val1, val2;

	if (node1->card->kind != node2->card->kind)
		return (node1->card->kind - node2->card->kind);

	val1 = get_value(node1->card);
	val2 = get_value(node2->card);
	return (val1 - val2);
}

/**
 * sort_deck - Sorts a doubly linked list deck of cards.
 * @deck: Double pointer to the head of the list.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *nodes[52];
	deck_node_t *curr;
	int i;

	if (!deck || !*deck)
		return;

	/* Load nodes into an array */
	curr = *deck;
	for (i = 0; i < 52; i++)
	{
		nodes[i] = curr;
		curr = curr->next;
	}

	/* Sort the pointer array */
	qsort(nodes, 52, sizeof(deck_node_t *), card_cmp);

	/* Re-link the nodes */
	for (i = 0; i < 52; i++)
	{
		nodes[i]->prev = (i == 0) ? NULL : nodes[i - 1];
		nodes[i]->next = (i == 51) ? NULL : nodes[i + 1];
	}

	*deck = nodes[0];
}
