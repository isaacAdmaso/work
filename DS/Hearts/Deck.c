/**
 * @brief represent of a deck of cards
 * 
 * @file Deck.c
 */
#include "Deck.h"
#include <stdlib.h>/**for malloc() */
#include <stdio.h> /**for printf() */
#include <time.h> /**random shuffle cards using time as seed  */

#define MAGIC_D 465375285
#define IS_VALID_D(D)  ( NULL != (D) && (D)->m_magic == MAGIC_D)

/**
 * @brief allocats memory for Deck
 * 
 * @return Deck* 
 */
Deck* DeckCreate()
{
	Deck* deck;
	int i;
	deck = (Deck*)malloc(sizeof(Deck));
	if(NULL == deck)
	{
		return NULL;
	}
	deck->m_deck = VectorCreate(DECKSZ ,0);
	if(NULL == deck->m_deck)
	{
		free(deck);
		return NULL;
	}
	for(i = 0;i < DECKSZ;++i)
		VectorAdd(deck->m_deck,i);
	deck->m_magic = MAGIC_D;	
	return deck;
}

/**
 * @brief free memory
 * 
 * @param _deck 
 */
void DeckDestroy(Deck* _deck)
{
	if(IS_VALID_D(_deck))
	{
		_deck->m_magic = 0;
		free(_deck->m_deck);
		free(_deck);
	}
}

/**
 * @brief shuffle using rand
 * 
 * @param _deck 
 */
void DeckShuffle(Deck* _deck)
{
	int val1,idxVal1,val2,idxVal2;
	if(IS_VALID_D(_deck))
	{
		srand(time(NULL));
		for(idxVal1 = DECKSZ-1;idxVal1 > 0;--idxVal1)
		{
			idxVal2 = rand() % (idxVal1+1);
			VectorGet(_deck->m_deck,idxVal1,&val1);
			VectorGet(_deck->m_deck,idxVal2,&val2);
			VectorSet(_deck->m_deck,idxVal1,val2);
			VectorSet(_deck->m_deck,idxVal2,val1);
		}
	}
}

/**
 * @brief display deck
 * 
 * @param _deck 
 */
void DeckSPrint(Deck* _deck)
{
	int i,id;
	Card card;
	for(i = 0;i < DECKSZ;++i)
	{
		VectorGet(_deck->m_deck,i,&id);
		card.m_suit = GETSUIT(id);
		card.m_rank = GETRANK(id);
		CardPrint(card);
	}
	printf("\n");
}
	
/**
 * @brief dealing one card
 * 
 * @param _deck 
 * @param cardId decimal representation of a card
 */
void DeckGiveOneC(Deck* _deck,int* cardId)
{
	
	if(IS_VALID_D(_deck) && NULL != cardId)
	{
		VectorDelete(_deck->m_deck,cardId);
	}
}	



