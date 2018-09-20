#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <stddef.h>
#include "Card.h"
#include "vector.h"

#define P_NAME 128


typedef enum HeartPlayed{ NO,YES } HeartPlayed;

typedef enum PlyT{REAL ,COMP} PlyT;

typedef enum CHOSE_CARD{LOW,HIGH} CHOSE_CARD;

typedef struct Player Player;


Player* PlayerCreate(char* _name,PlyT _modePlyr);

void PlayerDestroy(Player* _ply);

Card PlayerCardToPass(Player* _p,CHOSE_CARD _modeC);

Card PlayerChoseTrick(Player* _p,Suit _suit,CHOSE_CARD _modeC);

char* PlayerGetName(Player* _p);

void PlayerPrint(Player *_p);

void PlayerTakeCard(Player*_p,Card _card);

int PlayerIsCardExs(Player*_p,Card _card);

void PlayerHrtStatOn(Player* _p[]);

void PlayerHrtStatOff(Player* _p[]);

void PlayerTakeTrick(Player* _p,Vector* _trick);

void PlayerUpDtPtTrk( Player* _p,Vector* _trick );

int PlayerGetScore(Player* _p);

void PlayerSetScore(Player* _p,int _setPts);

#endif/*__PLAYER_H__*/
