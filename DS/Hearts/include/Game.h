#ifndef __GAME_H__
#define __GAME_H__
#include "Deck.h"
#include "Player.h"
#define NOP 4

typedef enum CHMODE{LEFT,RIGHT,NEXT,PREV}CHMODE;

typedef struct Game
{
	Player m_playres[NOP]; /*players */
	int m_score[NOP];     /* players score*/
	CHMODE chmode;        /* passing 3 cards to*/
}Game;



Game* GameCreate();
void GamePlay();

#endif /*__GAME_H__*/


