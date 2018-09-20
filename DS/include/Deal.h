#ifndef __DEAL_H__
#define __DEAL_H__
#include "Player.h"
#include "Deck.h"
#include "Card.h"



typedef struct Deal Deal;



void DealPlay(Player* _p[], int* _score,int _heartInit[]);


#endif /*__DEAL_H__*/
