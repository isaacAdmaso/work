/*       card.h 
*   include TTY.h for printing
*	Suit enum for suit
*	Rank enum for rank
*/
#ifndef __CARD_H__
#define __CARD_H__
#include <stddef.h>
#include "TTY.h"  /** Contains shortcuts to print commands for printing card*/


#define NOP 4                /**number of players */
#define SUITNUM 4     /** CLUBS, DIAMONDS, SPADES, HEARTS */
#define HAND 13      /**13 cards make a hand */
#define DECKSZ 52	
#define MAXPOINTS 26 
#define WORSTCARDPT 13    /**queen of spades  */
#define GETSUIT(ID) ((ID) % DECKSZ) / HAND                 /* suit of card   */
#define GETRANK(ID) (ID) % HAND						  /* rank of card*/
#define GETID(SUIT,RANK) ((SUIT) * HAND + (RANK))   /* the actual representation of a card */


typedef enum Suit{CLUBS, DIAMONDS, SPADES, HEARTS , NONE_S = -1}Suit;

typedef enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		    JACK, QUEEN, KING, ACE,NONE_R = -1}Rank;

/**
 * @brief card representation structer 
 * 
 */
typedef struct Card
{
	Suit m_suit;	 /*	     enum suit     */
	Rank m_rank;	 /* 	 enum rank  	*/
}Card;




/**
 * @brief initialize the deck
 * 
 */
void CardInit();

/**
 * @brief print "card"
 * 
 * @param _card 
 */
void CardPrint(Card _card);

/**
 * @brief print Deck of cards
 * 
 */
void CardSPrint();

/**
 * @brief check if two cards are equal
 * 
 * @param card1 
 * @param card2 
 * @return int 1 if equal int 0 else
 */
int IsEqCrs(Card card1,Card card2);

/**
 * @brief bool, bg
 * 
 * @param card1 
 * @param card2 
 * @return int 1 if card1 is bigger or equal to card 2 ,int 0 else
 */
int IsBgCrs(Card card1,Card card2);


#endif  /*__CARD_H__*/


