#include "Card.h"
#include<stdio.h>


#define GETSUIT(ID) ((ID) % 52) / 13                  /* suit of card   */
#define GETRANK(ID) (ID) % 13						  /* rank of card*/
#define GETID((SUIT),(RANK)) ((SUIT) * 13 + (RANK))   /* the actual representation of a card */








void CardPrint(Card _card);

