#ifndef __CARD_H__
#define __CARD_H__
#include <stddef.h>

#define DECKSZ 52

typedef enum Suit{Spades, Diamonds, Clubs, Hearts}Suit;

typedef enum Rank {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
		    Jack, Queen, King, Ace}Rank;

typedef struct Cards
{
	int Cards[DECKSZ]; /* the deck*/
};
 
void CardPrint(Cards _card);


#endif  /*__CARD_H__*/


