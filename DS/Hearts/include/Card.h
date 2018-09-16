/*       card.h 
*   include TTY.h for printing
*
*
*/
#ifndef __CARD_H__
#define __CARD_H__
#include <stddef.h>
#include "TTY.h"


#define NOP 4
#define SUITNUM 4
#define HAND 13
#define DECKSZ 52
#define GETSUIT(ID) ((ID) % DECKSZ) / HAND                  /* suit of card   */
#define GETRANK(ID) (ID) % HAND						  /* rank of card*/
#define GETID(SUIT,RANK) ((SUIT) * HAND + (RANK))   /* the actual representation of a card */


typedef enum Suit{CLUBS, DIAMONDS, SPADES, HEARTS , NONE_S = -1}Suit;

typedef enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		    JACK, QUEEN, KING, ACE,NONE_R = -1}Rank;

typedef struct Card
{
	Suit m_suit;	 /*	                   */
	Rank m_rank;	 /* card representation*/
}Card;





void CardInit();

void CardPrint(Card _card);

void CardSPrint();


#endif  /*__CARD_H__*/


