#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev)
        node1->prev->next = node2;
    if (node2->next)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;

    if (!node2->prev)
        *list = node2;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using the Cocktail shaker sort algorithm
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *start = NULL;
    listint_t *end = NULL;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    do {
	    listint_t *current;
        swapped = 0;
        for (current = start ? start->next : *list; current && current->next != end; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            }
        }
        if (!swapped)
            break;
	/*listint_t *current;*/
        end = end ? end->prev : (*list)->prev;
        for (current = end ? end->prev : (*list)->prev; current && current->prev != start; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list);
            }
        }
        start = start ? start->next : *list;
    } while (swapped);
}
