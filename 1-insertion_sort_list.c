#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort -  sorts a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: pointer to head node
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp, *tmp1, *next, *prev;

	if (!list || !*list || !(*list)->next)
		return;
	current = *list;
	current = current->next;
	while (current)
	{
		tmp = current;
		tmp1 = current->next;
		if (current->n < current->prev->n)
		{

			while (tmp && tmp->prev)
			{
				if (tmp->n < tmp->prev->n)
				{
					next = tmp->next;

					prev = tmp->prev;

					prev->next = next;

					next->prev = prev;

					tmp->next = prev;

					tmp->prev = prev->prev;
					puts("next");
					if (prev->prev)
					{
						prev->prev->next = tmp;
						puts("prev");
						prev->prev = tmp;
					}

					print_list(*list);
				}
			}
			current = tmp1;
		}
	}
}