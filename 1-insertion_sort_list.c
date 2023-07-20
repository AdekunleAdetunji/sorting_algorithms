#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list -  sorts a doubly linked list of integers in
 * ascending order
 * using the Insertion sort algorithm
 * @list: pointer to head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *next, *prev;

	if (!list || !*list || !(*list)->next)
		return;
	tmp = *list;
	while (tmp)
	{
		for (prev = tmp->prev; prev != NULL; prev = prev->prev)
		{
			if (prev->n > tmp->n)
			{
				prev = tmp->prev;
				next = tmp->next;
				tmp->prev = prev->prev;
				tmp->next = prev;
				prev->next = next;
				prev->prev = tmp;
				if (next)
					next->prev = prev;
				if (tmp->prev)
				{
					tmp->prev->next = tmp;
				}
				else if (tmp->next)
					*list = tmp;
				print_list(*list);
			}
		}
		tmp = tmp->next;
	}
}
