#include <stdlib.h>
#include "deck.h"

/**
 * compare_cards - Compare two cards for sorting
 * @a: First card
 * @b: Second card
 *
 * Return: Negative value if a should be before b, positive if after, 0 if equal
 */
static int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = (*(const deck_node_t **)a)->card;
    const card_t *card_b = (*(const deck_node_t **)b)->card;
    kind_t kind_a = card_a->kind;
    kind_t kind_b = card_b->kind;
    char value_a = card_a->value[0];
    char value_b = card_b->value[0];

    if (kind_a != kind_b)
        return kind_a - kind_b;

    if (value_a == 'A')
        return -1;
    if (value_b == 'A')
        return 1;
    if (value_a == 'K')
        return -1;
    if (value_b == 'K')
        return 1;
    return value_a - value_b;
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t count = 0;
    deck_node_t *curr = *deck;
    deck_node_t **arr = NULL;
    size_t i;

    /* Count the number of cards in the deck */
    while (curr)
    {
        curr = curr->next;
        count++;
    }

    /* Allocate memory for an array of deck_node_t pointers */
    arr = malloc(count * sizeof(*arr));
    if (!arr)
        return;

    /* Populate the array with pointers to deck nodes */
    curr = *deck;
    for (i = 0; i < count; i++)
    {
        arr[i] = curr;
        curr = curr->next;
    }

    /* Sort the array using the compare_cards function */
    qsort(arr, count, sizeof(*arr), compare_cards);

    /* Reconstruct the deck based on the sorted array */
    for (i = 0; i < count - 1; i++)
    {
        arr[i]->next = arr[i + 1];
        arr[i + 1]->prev = arr[i];
    }
    arr[count - 1]->next = NULL;

    /* Update the deck pointer to point to the sorted deck */
    *deck = arr[0];
    free(arr);
}
