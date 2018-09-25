/**
 * @brief the game 
 * 
 * @file Game.c
 */
#include <stdio.h>/**for print */
#include <stdlib.h>/**for malloc */
#include <assert.h> /**trying using assert */
#include "Game.h"

#define MAXI 100  /**max points */
#define MAGIC 109238745
#define IS_VALID(G) (NULL != (G) && MAGIC == (G)->m_magic)


struct Game
{
	Player* m_playres[NOP]; /*players */
	int* m_score;     /* players score*/
	int m_heartInit[3];        /* passing 3 cards to*/
	size_t m_magic;
};

/**
 * @brief initiate the game
 *  
 * @param _names list of  plyers names. 
 * @param _cardToStr dealing  cards style 
 * @param _cardToPass amount of cards to pass from player to player at the beginning
 * @param _xChgMode how to pass the cards
 * @return Game* 
 */
static Game* GameCreate(char* _names[],int _pMode[],int _cardToStr ,int _cardToPass,int _xChgMode)
{
	Game* game;
	int i,j;
	
	game = (Game*)malloc(sizeof(Game));
	if(NULL == game)
		return NULL;
	
	/**initialize score array */
	game->m_score = (int*)calloc(NOP,sizeof(int));
	if(NULL == game->m_score)
	{
		free(game);
		return NULL;
	}
	/**initialize players array*/
	for(i = 0;i < NOP;++i)
	{
		game->m_playres[i] = PlayerCreate(_names[i],_pMode[i]);
		if(NULL == game->m_playres[i])
		{	
			for(j = 0;j < i; ++j)
				PlayerDestroy(game->m_playres[j]);
			free(game->m_score);
			free(game);
			return NULL;
		}
	}
	game->m_heartInit[0] = _cardToStr; /*initial game*/
	game->m_heartInit[1] = _cardToPass;/*data        */
	game->m_heartInit[2] = _xChgMode;  
	game->m_magic = MAGIC;
	return game;
}

/** printing player name and his score */
void GamePrint(Game* _game)
{
	int i,score = 0;
	
	if(IS_VALID(_game))
	{
		for(i = 0;i < NOP;++i )
		{
			score = _game->m_score[i];	
			printf("%s Score is: %d  \n",PlayerGetName(_game->m_playres[i]),score);
		}
	}
}
			
		
/**free allocated memory */
static void GameDestroy(Game* _game)
{
	int i,minP,minIdx;

	if(IS_VALID(_game))
	{
		minP = _game->m_score[0];
		minIdx = 0;
		for(i = 1;i < NOP;++i)
		{
			if (minP > _game->m_score[i])
			{
				minP =  _game->m_score[i];
				minIdx = i;
			}
		}
		printf("\t\t%sEND OF GAME\n\tTHE WINNER IS: %s%s\n",TXT_BOLD_ON,PlayerGetName(_game->m_playres[minIdx]),TXT_NORMAL);
		GamePrint(_game);
		_game->m_magic = 0;
		for(i = 0;i < NOP;++i)
			PlayerDestroy(_game->m_playres[i]);
		free(_game->m_score);
		free(_game);
	}
}


/**
 * @brief the actual game loop
 * 
 * @param _names list of  plyers names.
 * @param _cardToStr dealing  cards style
 * @param _cardToPass amount of cards to pass from player to player at the beginning
 * @param _xChgMode how to pass the cards
 *  
 */
static void GamePlay(char* _names[],int _pMode[],int _cardToStr,int _cardToPass,int _xChgMode)
{
	Game* game;
	int i,maxSc = 0;
	game = GameCreate(_names,_pMode,_cardToStr,_cardToPass,_xChgMode);
	if(NULL == game)
		return;
		
	while(1)
	{
		for(i = 0;i < NOP;++i)
		{
			if(game->m_score[i] > maxSc)
				maxSc = game->m_score[i];
		}
		if(maxSc >= MAXI)
			break;
				
		DealPlay(game->m_playres,game->m_score,game->m_heartInit);
		GamePrint(game);
		getchar();
	}
	GameDestroy(game);
}
		
		
/**
 * @brief take names and  mode and play the game 
 * 
 */
void GameMain()
{
	int i,cardToStr,cardToPass,xChgMode;
	char* names[NOP];
	int _pMode[NOP];
	FILE* fp = NULL;
	
	fp = fopen("GameINIT.txt","r");
	if(NULL == fp)
	{
		for(i = 0;i < NOP;++i)
		{
			names[i] = (char*)malloc(P_NAME*sizeof(char));
			assert(names[i] != NULL);
			printf("Enter Player #%d name: \n",i+1);
			scanf("%s",names[i]);
			printf("enter player #%d type (REAL = 0 , COMP = 1): \n",i+1);
			scanf("%d",_pMode+i);
		}
		printf("How much to deal? \n");
		scanf("%d",&cardToStr);
		printf("How much to pass? \n");
		scanf("%d",&cardToPass);
		printf("How to exchange cards? (0-3 Counterclockwise) \n");
		scanf("%d",&xChgMode);
	}
	else
	{
		for(i = 0;i < NOP;++i)
		{
			names[i] = (char*)malloc(P_NAME*sizeof(char));
			assert(names[i] != NULL);
			fscanf(fp,"%s",names[i]);
			fscanf(fp,"%d",_pMode+i);
		}
		fscanf(fp,"%d",&cardToStr);
		fscanf(fp,"%d",&cardToPass);
		fscanf(fp,"%d",&xChgMode);
		fclose(fp);
	}
	GamePlay(names,_pMode,cardToStr,cardToPass,xChgMode);
	for(i = 0;i < NOP;++i)
		free(names[i]);
}

/*
*/ 	


















