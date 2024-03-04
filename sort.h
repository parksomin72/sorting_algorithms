#ifndef SORT_H
#define SORT_H

#include <stddef.h>

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
 * struct deck_node - Doubly linked list node for a deck
 *
 * @value: Integer value stored in the node
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node
{
	int value;
	struct deck_node *prev;
	struct deck_node *next;
} deck_node_t;
/* Function prototypes for sorting algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, int low, int high, size_t size);
void quicksort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void sort_deck(deck_node_t **deck);
void print_array(const int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list);

#endif /* SORT_H */
