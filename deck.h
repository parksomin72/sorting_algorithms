#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/**
 * enum kind_e - Represents the kinds of cards
 * @SPADE: Spade cards
 * @HEART: Heart cards
 * @CLUB: Club cards
 * @DIAMOND: Diamond cards
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card
 * @value: The value of the card (Ace, 2-10, Jack, Queen, King)
 * @kind: The kind of the card (Spade, Heart, Club, Diamond)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in the deck of cards
 * @card: Pointer to the card in this node
 * @prev: Pointer to the previous node in the deck
 * @next: Pointer to the next node in the deck
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
