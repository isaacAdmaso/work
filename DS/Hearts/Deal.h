#ifndef __DEAL_H__
#define __DEAL_H__
#include "Deck.h"




void TakeTrCard(Game* _game);/*take 3 cards*/
void DisTrCard(Game* _game);/*dicard 3 cards*/
Deck* DeckInit(Deck* _deck);/*initial deak*/
void DeaLoop(Game* _game);/*the game*/

#endif /*__DEAL_H__*/
