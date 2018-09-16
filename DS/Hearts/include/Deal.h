#ifndef __DEAL_H__
#define __DEAL_H__
#include "Player.h"
#include "Deck.h"

#define NOP 4

typedef struct Deal Deal;

Deal* DealCreate();

void DealDestroy(Deal* _deal);

void DealCards(Deal* _deal,Player* _p[NOP],int _nOfCard );

/*
void DealTakeTrCard(Player _p[NOP],int _mode)
void DealDisTrCard(Player _p[NOP],int _mode);
void DealDeaLoop(Player _p[NOP],int _mode,int _score[NOP]);
void DealPreint(Player**);
*/
/*the game*/
 /*take 3 cards*/
/*dicard 3 cards*/



#endif /*__DEAL_H__*/
