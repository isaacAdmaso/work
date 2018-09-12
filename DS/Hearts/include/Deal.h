#ifndef __DEAL_H__
#define __DEAL_H__
#include "Deck.h"
#include "Player.h"
#define NOP 4



void TakeTrCard(Player _p[NOP],int _mode);/*take 3 cards*/
void DisTrCard(Player _p[NOP],int _mode);/*dicard 3 cards*/
Deck* DeckInit(Deck* _deck);/*initial deak*/
void DeaLoop(Player _p[NOP],int _mode,int _score[NOP]);/*the game*/

#endif /*__DEAL_H__*/
