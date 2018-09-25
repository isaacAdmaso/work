/**
 * @brief represent a deck of card using adt 
 * 
 * @file Deck.h
 */
#ifndef __DECK_H_
#define __DECK_H_
#include "vector.h" /**using vector adt */
#include "Card.h"  /**a deck instance */
#include<stddef.h> 


typedef struct Deck
{
	Vector* m_deck; /**adt storing the cards */
	size_t m_magic;
}Deck;


/**
 * @brief allocats memory for Deck
 * 
 * @return Deck* 
 */
Deck* DeckCreate();

/**
 * @brief free memory
 * 
 * @param _deck 
 */
void DeckDestroy(Deck* _deck);

/**
 * @brief shuffle deck
 * 
 * @param _deck 
 */
void DeckShuffle(Deck* _deck);

/**
 * @brief display deck
 * 
 * @param _deck 
 */
void DeckSPrint(Deck* _deck);

/**
 * @brief dealing one card
 * 
 * @param _deck 
 * @param cardId decimal representation of a card
 */
void DeckGiveOneC(Deck* _deck,int* cardId);

#endif /*__DECK_H_*/
