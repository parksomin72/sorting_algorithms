#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL)
        return;

    do {
        swapped = 0;
        /* Forward pass */
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, list);
                swapped = 1;
                print_list(*list);
            }
        }
        if (!swapped)
            break;

        swapped = 0;
        /* Backward pass */
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(current->prev, list);
                swapped = 1;
                print_list(*list);
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @node: pointer to the node to swap with its next node
 * @list: pointer to the head of the doubly linked list
 */
void swap_nodes(listint_t *node, listint_t **list)
{
    listint_t *prev_node, *next_node;

    prev_node = node->prev;
    next_node = node->next;

    if (prev_node != NULL)
        prev_node->next = next_node;
    else
        *list = next_node;

    if (next_node != NULL)
        next_node->prev = prev_node;

    node->prev = next_node;
    node->next = next_node == NULL ? NULL : next_node->next;

    if (next_node != NULL && next_node->next != NULL)
        next_node->next->prev = node;

    next_node->next = node;
}
