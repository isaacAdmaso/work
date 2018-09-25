#ifndef __DEAL_H__
#define __DEAL_H__
#include "Player.h"
#include "Deck.h"
#include "Card.h"



typedef struct Deal Deal;


/**
 * @brief play COMP player mode -always play low card unless suit
 * dont exist than play high card 
 * 
 * @param _p players list
 * @param _score array provided by GAME
 * @param _heartInit array of initial data (metadata) provided by GAME
 */
void DealPlay(Player* _p[], int* _score,int _heartInit[]);


#endif /*__DEAL_H__*/
