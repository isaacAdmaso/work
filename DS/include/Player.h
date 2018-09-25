/**
 * @brief module player  with geters and seters and "playing" 
 * 
 * @file Player.h
 */
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <stddef.h>
#include "Card.h"   /**for card struct */
#include "vector.h" /**using adt vector */

#define P_NAME 128 /**128 letters name */


typedef enum HeartPlayed{ NO,YES } HeartPlayed;

typedef enum PlyT{REAL ,COMP} PlyT;/**player mode  */

typedef enum CHOSE_CARD{LOW,HIGH} CHOSE_CARD;/**for COMP player chose card mode */

typedef struct Player Player;


/**
 * @brief create player using 5 adt (4 suits & discarded pile)
 * and save round points  
 * 
 * @param _name - string
 * @param _modePlyr - player mode -enum {REAL ,COMP} 
 * @return Player* 
 */
Player* PlayerCreate(char* _name,PlyT _modePlyr);

/**
 * @brief free player
 * 
 * @param Player*
 */
void PlayerDestroy(Player* _ply);


/**
 * @brief chose card to play based on "hearts played" status  
 * 
 * @param _p: player 
 * @param _modeC : HIGH or LOW
 * @return Card 
 */
Card PlayerCardToPass(Player* _p,CHOSE_CARD _modeC);


/**
 * @brief chose card to play based on suit  -if suit exists 
 * if not chose from next suit 
 * 
 * @param _p :player
 * @param _suit: enum {CLUBS, DIAMONDS, SPADES, HEARTS}
 * @param _modeC: CHOSE_CARD mode HIGH or LOW
 * @return Card 
 */
Card PlayerChoseTrick(Player* _p,Suit _suit,CHOSE_CARD _modeC);

/**
 * @brief get name
 * 
 * @param _p 
 * @return char* player->name
 */
char* PlayerGetName(Player* _p);


/**
 * @brief print player by his/her name and hand
 * 
 * @param _p 
 */
void PlayerPrint(Player *_p);


/**
 * @brief add rank of card to vector (suit)  
 * 
 * @param _p 
 * @param _card 
 */
void PlayerTakeCard(Player*_p,Card _card);


/**
 * @brief bool check if player has a specific card
 * 
 * @param _p - player pointer 
 * @param _card - with field  m_suit and m_rank
 * @return int 1 if true ,int 0 false
 */
int PlayerIsCardExs(Player*_p,Card _card);


/**
 * @brief set indicator of hearts (in palyer) to 0  
 * 
 * @param _p 
 */
void PlayerHrtStatOn(Player* _p[]);


/**
 * @brief set indicator of hearts (in palyer) to 0  
 * 
 * @param _p 
 */
void PlayerHrtStatOff(Player* _p[]);


/**
 * @brief player take the pile 
 * 
 * @param _p Player
 * @param _trick Vector
 */
void PlayerTakeTrick(Player* _p,Vector* _trick);


/**
 * @brief update player's round points from pile played 
 * 
 * @param _p 
 * @param _trick pile played  
 */
void PlayerUpDtPtTrk( Player* _p,Vector* _trick );


/**
 * @brief Player type points getter  
 * 
 * @param _p player
 * @return int round points
 */
int PlayerGetScore(Player* _p);


/**
 * @brief Player type points setter
 * 
 * @param _p 
 * @param _setPts starting round points
 */
void PlayerSetScore(Player* _p,int _setPts);

/*
Card PlayerRealplay(Player* _p);
*/

/**
 * @brief getter for player mode  
 * 
 * @param _p 
 * @return int 0 if REAL int 1 if COMP -1 for bugs
 */
int PlayerGetMood(Player *_p);


#endif/*__PLAYER_H__*/
