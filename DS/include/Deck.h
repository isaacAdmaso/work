#ifndef __DECK_H_
#define __DECK_H_
#include "vector.h"
#include "Card.h"
#include<stddef.h>


typedef struct Deck
{
	Vector* m_deck;
	size_t m_magic;
}Deck;


Deck* DeckCreate();

void DeckDestroy(Deck* _deck);

void DeckShuffle(Deck* _deck);

void DeckGiveOneC(Deck* _deck,int* cardId);

#endif /*__DECK_H_*/
