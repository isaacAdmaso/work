/**
 * @brief represent the "house"-control the score  initiate the deal and end the game
 * 
 * @file Game.h
 */
#ifndef __GAME_H__
#define __GAME_H__
#include "Player.h" /**for player module  */
#include "Deal.h"   /**for Deal module  */
#include "vector.h" /**using adt vector */


#define NOP 4       


typedef struct Game Game;


/**
 * @brief  play the game 
 * 
 */
void GameMain();


#endif /*__GAME_H__*/


