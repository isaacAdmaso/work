#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Deck.h" 

typedef enum PlyT{REAL ,COMP} PlyT;


typedef struct Player
{
	char name[512];  /*player's name*/
	PlyT ROC;        /* human or computer */
	Vector* spades;
	Vector* diamond;
	Vector* clubs;
	Vector* hearts;
}Player;

void TakeCard(Player*_p,Cards _card);

void DisCard(Player*_p,Cards _card); 

int IsExs(Player*_p,Cards _card);

#endif/*__PLAYER_H__*/
