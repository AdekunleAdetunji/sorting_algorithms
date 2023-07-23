#include "sort.h"
/**
 * swap_node - swaps 2 nodes of a doubli linked list
 * @h: address of address of head node
 * @a: address of address of 1st node
 * @b: address of address of 2nd node
 */
void swap_node(listint_t **h, listint_t **a, listint_t **b)
{
	listint_t *n1 = *a, *n2 = *b;

	if (n2->next)
		n2->next->prev = n1;
	n1->next = n2->next;
	n2->next = n1;
	n2->prev = n1->prev;
	if (n1->prev)
		n1->prev->next = n2;
	else
		*h = n2;
	n1->prev = n2;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: pointer to head node pointer
 */
void cocktail_sort_list(listint_t **list)
{
	int flag = 1;
	listint_t *h, *next, *prev, *end = NULL;

	if (!list || !*list || !(*list)->next)
		return;
	while (flag)
	{
		h = (*list)->next;
		flag = 0;
		while (h)
		{
			next = h->next;
			if (h->n < h->prev->n)
			{
				end = !next ? h->prev : NULL;
				swap_node(list, &(h->prev), &h);
				print_list(*list);
				flag = 1;
			}
			if (!next)
				end = end ? end : h;
			h = next;
		}

		if (!flag)
			break;
		flag = 0;
		h = end->prev;
		while (h)
		{
			prev = h->prev;
			if (h->n > h->next->n)
			{
				swap_node(list, &h, &(h->next));
				print_list(*list);
				flag = 1;
			}
			h = prev;
		}
	}
}
