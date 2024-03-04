#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Insertion Sort algorithm.
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev_node, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current;
		next_node = current->next;

		while (temp->prev != NULL && temp->prev->n > temp->n)
		{
			prev_node = temp->prev;
			prev_node->next = temp->next;

			if (temp->next != NULL)
				temp->next->prev = prev_node;

			temp->prev = prev_node->prev;
			temp->next = prev_node;

			if (prev_node->prev != NULL)
				prev_node->prev->next = temp;
			else
				*list = temp;

			prev_node->prev = temp;

			print_list(*list);
		}

		current = next_node;
	}
}
