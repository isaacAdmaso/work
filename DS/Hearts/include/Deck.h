#ifndef __DECK_H_
#define __DECK_H_
#include "Card.h"
#include "vector.h"

typedef struct Deck Deck;

struct Deck
{
	Vector* v;
};



void DeckShuff(Deck* _deck);/*shuffle*/

void DeckDeal(Deck* _deck);


#endif /*__DECK_H_*/
