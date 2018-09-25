/**
 * @brief represent a computer player with it moves
 * 
 * @file Player.c
 */
#include "Player.h"
#include <stdlib.h>/**malloc */
#include <string.h>/**using strncpy for name (string) */
#include <stdio.h>/**printf */


#define MAGIC 285375465
#define IS_VALID(P)  ( NULL != (P) && (P)->m_magic == MAGIC)


/**
 * @brief Player have name "hand" and his round points 
 * 
 */
struct Player
{
	char m_name[P_NAME];  /*player's name*/
	PlyT m_roc;        /* human or computer */
	Vector* m_spades;  /**4 adt (vectors) represent hand */
	Vector* m_diamond;
	Vector* m_clubs;
	Vector* m_hearts;
	Vector* m_disTrick;/*losing round (trick) pile of cards*/
	HeartPlayed m_heartPlayed; /* is heart played*/
	int m_points;
	size_t m_magic;
};




static void InSortHlp(Vector* _vec);
static Vector* WiVecToUs(Player*_p,Suit _s);


/**
 * @brief bool check if player has a specific card
 * 
 * @param _p - player pointer 
 * @param _card - with field  m_suit and m_rank
 * @return int 1 if true ,int 0 false
 */
int PlayerIsCardExs(Player*_p,Card _card)	
{
	int i,cardId=-1,chId=-1;
	size_t numOfC;
	Vector *suitVec;
	
	if(IS_VALID(_p))
	{		
		cardId = GETID(_card.m_suit,_card.m_rank);
		suitVec = WiVecToUs(_p,_card.m_suit);
		VectorItemsNum(suitVec,&numOfC);
		for(i = 0;i < numOfC;++i )
		{
			VectorGet(suitVec,i,&chId);
			if(chId == cardId)
				return 1;
		}
	}
	return 0;
}
	
/**
 * @brief search suit in player's "hand" vectors 
 * 
 * @param _p 
 * @param _s -suit 
 * @return Vector* 
 */
static Vector* WiVecToUs(Player*_p,Suit _s)
{
	if(IS_VALID(_p))
	{
		switch(_s)
				{
					case CLUBS:
						return _p->m_clubs;
					case DIAMONDS:				
						return _p->m_diamond;
					case SPADES:
						return _p->m_spades;
					case HEARTS:
						return _p->m_hearts;
					default:
						return NULL;
				}
	}
	return NULL;
}

/**
 * @brief add rank of card to vector (suit)  
 * 
 * @param _p 
 * @param _card 
 */
void PlayerTakeCard(Player*_p,Card _card)
{	
	int card;
	Vector *suitVec;
	if(IS_VALID(_p) && _card.m_suit != NONE_S )
		{
			suitVec = WiVecToUs(_p,_card.m_suit);
			
			card = GETID(_card.m_suit,_card.m_rank);
			VectorAdd(suitVec,card);
			InSortHlp(suitVec);
		}
}
			
/**
 * @brief get name
 * 
 * @param _p 
 * @return char* player->name
 */
char* PlayerGetName(Player* _p)
{
	if(IS_VALID(_p))
		return _p->m_name;
	return NULL;
}

/**
 * @brief create player using 5 adt (4 suits & discarded pile)
 * and save round points  
 * 
 * @param _name - string
 * @param _modePlyr - player mode -enum {REAL ,COMP} 
 * @return Player* 
 */
Player* PlayerCreate(char* _name,PlyT _modePlyr)
{
	Player* ply;
	
	ply = (Player*)malloc(sizeof(Player));
	if(NULL == ply)
		return NULL;
	ply->m_spades = VectorCreate(HAND,0);
	ply->m_diamond = VectorCreate(HAND,0);
	ply->m_clubs = VectorCreate(HAND,0);
	ply->m_hearts = VectorCreate(HAND,0);
	ply->m_disTrick =VectorCreate(4,2);
	if( NULL == ply->m_spades || NULL == ply->m_diamond ||\
		NULL == ply->m_clubs || NULL == ply->m_hearts ||\
		NULL == ply->m_disTrick)
	{
		return NULL;
	}
	strncpy(ply->m_name,_name,sizeof(ply->m_name));
	ply->m_roc = _modePlyr;
	ply->m_heartPlayed = YES;
	ply->m_points = 0;
	ply->m_magic = MAGIC;
	return ply;
}	
/**
 * @brief free player
 * 
 * @param Player*
 */
void PlayerDestroy(Player* _ply)
{
	if(IS_VALID(_ply))
	{
		_ply->m_magic = 0;
		VectorDestroy(_ply->m_spades);	
		VectorDestroy(_ply->m_diamond);	
		VectorDestroy(_ply->m_clubs);	
		VectorDestroy(_ply->m_hearts);
		VectorDestroy(_ply->m_disTrick);
		free(_ply);
	}
}

/**
 * @brief insertion sort of cards by suit
 * 
 * @param _vec 
 */
static void InSortHlp(Vector* _vec)
{
	size_t size;
	int i,j,swapItem,item;
	
	VectorItemsNum(_vec ,&size);
	if(size <= 1)
	{
		return ;
	}
	for(i = 1;i < size;++i)
	{
		VectorGet(_vec,i,&item);
		j = i-1;
		VectorGet(_vec,j,&swapItem);
	/*Move elements bigger than val  */
		while (j >= 0 && swapItem > item)
		{
			VectorSet(_vec,j+1,swapItem);
			--j;
			VectorGet(_vec,j,&swapItem);
		}
		VectorSet(_vec,j+1,item);
	}
}

/**
 * @brief print cards of the same suit 
 * 
 * @param _vec - suit
 * @param _size - size of array
 */
static void printHelper(Vector* _vec,size_t _size)
{
	int i,card;
	Card cardreal;
	
	for(i = 0;i < _size;++i )
	{
		VectorGet(_vec,i,&card);
		cardreal.m_suit = GETSUIT(card);
		cardreal.m_rank = GETRANK(card);
		CardPrint(cardreal);
	}
}

/**
 * @brief print player by his/her name and hand
 * 
 * @param _p 
 */
void PlayerPrint(Player *_p)
{	
	size_t size_s;
	int i;
	Vector *suitToDr;

	size_s = 0;
	suitToDr = NULL;
	printf("\n%s - %d\n",_p->m_name,_p->m_points);
	for(i = 0;i < SUITNUM;++i)
	{
		suitToDr = WiVecToUs(_p,i);
		VectorItemsNum(suitToDr,&size_s);
		printHelper(suitToDr,size_s);

	}
	printf("\n");
}
/**
 * @brief chose a high or low card 
 * 
 * @param _vec - suit
 * @param _mode - LOW or HIGH
 * @return Card 
 */
static Card ChoseCard(Vector* _vec,CHOSE_CARD _mode)
{
	int cardId,card_replace;
	Card card_return;
	size_t numOfCards;
	
	numOfCards = 0;
	card_return.m_suit = NONE_S;
	card_return.m_rank = NONE_R;
	cardId = 0;
	card_replace = 999;
	if(NULL == _vec)
		return card_return;
	VectorItemsNum(_vec,&numOfCards);
	if(numOfCards != 0 )
	{
		if(_mode == HIGH)
		{
			VectorDelete(_vec,&cardId);
		}
		else 
		{
			VectorGet(_vec,0,&cardId);
			VectorSet(_vec,0,card_replace);
			InSortHlp(_vec);
			VectorDelete(_vec,&card_replace);
		}
		card_return.m_suit = GETSUIT(cardId);
		card_return.m_rank = GETRANK(cardId);
	}
	return card_return;
}


/**
 * @brief chose min or max card based on rank by mode
 * 
 * @param _card array of struct card (one from each suit) allowed
 * @param _size size of array
 * @param _Mcard return selected card (enter with none_ suit & rank) 
 * @param _modeC HIGH or LOW
 */
static void ChoseHiLoCr(Card _card[],int _size,Card *_Mcard,CHOSE_CARD _modeC )
{
	int i;
	*_Mcard = _card[0];
	for(i = 1; i < _size;++i )
	{
		if(_modeC == HIGH) 
		{
			if(_Mcard->m_rank < _card[i].m_rank)
				*_Mcard = _card[i];
		}
		else
		{
			if(_Mcard->m_rank > _card[i].m_rank)
				*_Mcard = _card[i];
		}
	}
}

/**
 * @brief set indicator of hearts (in palyer) to 0  
 * 
 * @param _p 
 */
void PlayerHrtStatOff(Player* _p[])
{
	int i;
	if(NULL == _p)
		return;
	for(i = 0; i < NOP;++i )
	{
		if(!IS_VALID(_p[i]))
			return;
		_p[i]->m_heartPlayed = NO;
	}
}

/**
 * @brief set indicator of hearts (in palyer) to 0  
 * 
 * @param _p 
 */
void PlayerHrtStatOn(Player* _p[])
{
	int i;
	if(NULL == _p)
		return;
	for(i = 0; i < NOP;++i )
	{
		if(!IS_VALID(_p[i]))
			return;
		_p[i]->m_heartPlayed = YES;
	}
}
	
/**
 * @brief player take the pile 
 * 
 * @param _p Player
 * @param _trick Vector
 */
void PlayerTakeTrick(Player* _p,Vector* _trick)
{
	int cardId,i;
	
	cardId = -1;
	if( IS_VALID( _p ) && NULL != _trick )
	{
		for(i = 0; i < NOP;++i )
		{
			VectorGet(_trick,i,&cardId);
				if(cardId < 0)
					continue;
			VectorAdd(_p->m_disTrick,cardId);
		}
	}
}	

/**
 * @brief chose card to play based on suit  -if suit exists 
 * if not chose from next suit 
 * 
 * @param _p :player
 * @param _suit: enum {CLUBS, DIAMONDS, SPADES, HEARTS}
 * @param _modeC: CHOSE_CARD mode HIGH or LOW
 * @return Card 
 */
Card PlayerChoseTrick(Player* _p,Suit _suit,CHOSE_CARD _modeC)
{
	Card card = {NONE_S,NONE_R};
	Vector *suitToDr;

	if(IS_VALID(_p))
	{
		suitToDr = WiVecToUs(_p,_suit);
		card = ChoseCard(suitToDr,_modeC);
	}
	return card;
}
/**
 * @brief check if card  played by REAL player is valid 
 * 			in case of hearts suit
 * 
 * @param _p 
 * @param card 
 * @return int 1 if card good for play 0 if not -1 for bugs


static int PlayerRealValidP(Player* _p,Card card)
{
	if(IS_VALID(_p))
	{
		if(card.m_suit == HEARTS)
		{
			if(_p->m_heartPlayed == YES)
			{
				return 1;

			}else
			{
				return 0;
			}
		}
		return 1;
	}
	return -1;
}
 * @brief REAL player chose a card to play
 * 
 * @param _p 
 * @return Card

Card PlayerRealplay(Player* _p)
{
	int i,j,card,count;
	Card cardreal;
	size_t size_s;
	Vector *suitToDr;

	cardreal.m_suit = NONE_S;
	cardreal.m_rank = NONE_R;
	size_s = 0;
	count = 0;
	suitToDr = NULL;
	if(IS_VALID(_p))
	{
		while(1)
		{	
			printf("chose card to play \n");
			for(i = 0;i < SUITNUM;++i)
			{
				suitToDr = WiVecToUs(_p,i);
				VectorItemsNum(suitToDr,&size_s);

				for(j = 0;j < size_s;++j )
				{
					VectorGet(suitToDr,i,&card);
					cardreal.m_suit = GETSUIT(card);
					cardreal.m_rank = GETRANK(card);
					printf("%d-> ",++count);
					CardPrint(cardreal);
				}
			}
			printf("\n");
			scanf("%d",&card);
			count = 0;
			for(i = 0;i < SUITNUM;++i)
			{
				suitToDr = WiVecToUs(_p,i);
				VectorItemsNum(suitToDr,&size_s);
				

				for(j = 0;j < size_s;++j )
				{
					VectorGet(suitToDr,i,&card);
					cardreal.m_suit = GETSUIT(card);
					cardreal.m_rank = GETRANK(card);
					if(card == count)
						break;
					count++;
				}
				if(card == --count)
					break;
			}
			if(PlayerRealValidP(_p,cardreal))
				break;
			printf("Not valid try again... ");
		}
	}
	return cardreal;
}
*/
/**
 * @brief chose card to play based on "hearts played" status  
 * 
 * @param _p: player 
 * @param _modeC : HIGH or LOW
 * @return Card 
 */
Card PlayerCardToPass(Player* _p,CHOSE_CARD _modeC)
{
	int i,j,suitAllowed;
	Vector *suitToDr;
	Card cardTM,card[SUITNUM];
	
	cardTM.m_suit = NONE_S;
	cardTM.m_rank = NONE_R;	
	suitToDr = NULL;
	suitAllowed =SUITNUM; 
	/**enum Suit are ranked fromm 0 - 3 and hearts is 3   */
	if(_p->m_heartPlayed == NO)
		--suitAllowed;
	for(i = 0,j = 0;i < suitAllowed;++i )
	{
		
		suitToDr = WiVecToUs(_p,i);
		cardTM = ChoseCard(suitToDr,_modeC);
		if(cardTM.m_suit != NONE_S)
		{
			card[j] = cardTM;
			++j;
		}
	}
	if(j == 0)
		return cardTM;
	ChoseHiLoCr( card,j,&cardTM,_modeC );
	for(i = 0;i < j;++i)
	{
		if(IsEqCrs(cardTM,card[i])) 
			continue;
		PlayerTakeCard(_p,card[i]);
	}
	return cardTM;
}
/**
 * @brief update player's round points from pile played 
 * 
 * @param _p 
 * @param _trick pile played  
 */
void PlayerUpDtPtTrk( Player* _p ,Vector* _trick)
{
	int i,cardId,sumPoits = 0;
	Card card = {NONE_S,NONE_R};

	if(IS_VALID(_p))
	{
		for(i = 0; i < NOP;++i )
		{
			VectorGet(_trick,i,&cardId);
				if(cardId < 0)
					continue;
			card.m_suit = GETSUIT(cardId);
			card.m_rank = GETRANK(cardId);
			if( HEARTS == card.m_suit)
				++sumPoits;
			if(SPADES == card.m_suit && card.m_rank == QUEEN)
				sumPoits += WORSTCARDPT;	
		}
		_p->m_points += sumPoits;
	} 
}

/**
 * @brief Player type points getter  
 * 
 * @param _p player
 * @return int round points
 */
int PlayerGetScore(Player* _p)
{
	if(IS_VALID(_p))
		return _p->m_points;
	return -1;
} 
/**
 * @brief Player type points setter
 * 
 * @param _p 
 * @param _setPts starting round points
 */
void PlayerSetScore(Player* _p,int _setPts)
{
	if(IS_VALID(_p))
		_p->m_points = _setPts;
}

/**
 * @brief getter for player mode  
 * 
 * @param _p 
 * @return int 0 if REAL int 1 if COMP -1 for bugs
 */
int PlayerGetMood(Player *_p)
{
	if(IS_VALID(_p))
		return _p->m_roc;
	return -1;
}	

	

