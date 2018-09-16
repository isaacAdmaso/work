#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <stddef.h>
#include "Card.h"
#include "vector.h"

typedef enum PlyT{REAL ,COMP} PlyT;

typedef enum CHOSE_CARD{LOW,HIGH} CHOSE_CARD;

typedef struct Player Player;

Player* PlayerCreate(char* _name,PlyT _modePlyr);

void PlayerDestroy(Player* _ply);

void PlayerTakeCard(Player*_p,Card _card);

int PlayerIsCardExs(Player*_p,Card _card);

void PlayerPutCard(Player*_p,Vector* _trick); 

void PlayerPrint(Player *_p);

Card ChoseCard(Vector* _vec,CHOSE_CARD _mode);

#include "Deal.h"
#endif/*__PLAYER_H__*/
