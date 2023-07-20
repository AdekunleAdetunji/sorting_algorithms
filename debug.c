#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
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
            while (tmp && tmp->n < tmp->prev->n)
            {
                next = tmp->next;
                prev = tmp->prev;
                prev->next = next;
                next->prev = prev;
                tmp->next = prev;
                tmp->prev = prev->prev;

                if (prev->prev)
                {
                    prev->prev->next = tmp;
                    prev->prev = tmp;
                }
                else
                {

                    tmp = NULL;
                }

                print_list(*list);
            }
        }
        current = tmp1;
    }
}

listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}