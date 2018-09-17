#include "../include/Player.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define P_NAME 512
#define MAGIC 285375465
#define IS_VALID(P)  ( NULL != (P) && (P)->m_magic == MAGIC)



struct Player
{
	char m_name[P_NAME];  /*player's name*/
	PlyT m_roc;        /* human or computer */
	Vector* m_spades;
	Vector* m_diamond;
	Vector* m_clubs;
	Vector* m_hearts;
	Vector* m_disTrick;/*losing round (trick) pile of cards*/
	HeartPlayed m_heartPlayed;
	int m_points;
	size_t m_magic;
};




static void InSortHlp(Vector* _vec);
static Vector* WiVecToUs(Player*_p,Suit _s);


int PlayerIsCardExs(Player*_p,Card _card)	
{
	int i,cardId,chId;
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
	
	 
static Vector* WiVecToUs(Player*_p,Suit _s)
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
			




Player* PlayerCreate(char* _name,PlyT _modePlyr)
{
	Player* ply;
	
	ply = (Player*)malloc(sizeof(Player));
	if(NULL == ply)
		return NULL;
	ply->m_spades = VectorCreate(HAND,3);
	ply->m_diamond = VectorCreate(HAND,3);
	ply->m_clubs = VectorCreate(HAND,3);
	ply->m_hearts = VectorCreate(HAND,3);
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

void PlayerDestroy(Player* _ply)
{
	if(IS_VALID(_ply))
	{
		_ply->m_magic = 0;
		VectorDestroy(_ply->m_spades);	
		VectorDestroy(_ply->m_diamond);	
		VectorDestroy(_ply->m_clubs);	
		VectorDestroy(_ply->m_hearts);
		free(_ply);
	}
}


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


void PlayerPrint(Player *_p)
{	
	size_t size_s,size_d,size_c,size_h;
	
	VectorItemsNum(_p->m_clubs,&size_c);
	printf("\n%s \n",_p->m_name);
	printHelper(_p->m_clubs,size_c);

	VectorItemsNum(_p->m_diamond,&size_d);
	printHelper(_p->m_diamond,size_d);

	VectorItemsNum(_p->m_spades,&size_s);
	printHelper(_p->m_spades,size_s );

	VectorItemsNum(_p->m_hearts,&size_h);
	printHelper(_p->m_hearts,size_h);
	printf("\n");
}

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
			if(card_replace == 999)
				printf("you'r ok");
		}
		card_return.m_suit = GETSUIT(cardId);
		card_return.m_rank = GETRANK(cardId);
	}
	return card_return;
}



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

Card PlayerCardToPass(Player* _p,CHOSE_CARD _modeC)
{
	int i,j,suitAllowed;
	Vector *suitToDr;
	Card cardTM,card[SUITNUM];
	
	cardTM.m_suit = NONE_S;
	cardTM.m_rank = NONE_R;	
	suitToDr = NULL;
	suitAllowed =SUITNUM; 
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
	ChoseHiLoCr( card,j,&cardTM,_modeC );
	for(i = 0;i < j;++i)
	{
		if(IsEqCrs(cardTM,card[i])) 
			continue;
		PlayerTakeCard(_p,card[i]);
	}
	return cardTM;
}


void PlayerHrtStatChg(Player* _p[])
{
	int i;
	if(NULL == _p)
		return;
	for(i = 0; i < NOP;++i )
	{
		if(!IS_VALID(_p[i]))
			return;
		_p[i]->m_heartPlayed = (_p[i]->m_heartPlayed + 1) % 2;
	}
}	

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


Card PlayerChoseTrick(Player* _p,Suit _suit,CHOSE_CARD _modeC)
{
	Card card = {NONE_S,NONE_R},cardTest = {NONE_S,NONE_R};
	int i;
	Vector *suitToDr;

	if(IS_VALID(_p))
	{
		for( i = 0;i < SUITNUM;++i )
		{
			suitToDr = WiVecToUs(_p,(_suit+i) % SUITNUM);
			if(NULL == suitToDr);
				return card;
			card = ChoseCard(suitToDr,_modeC);
			if(IsEqCrs(card,cardTest))
				return card;
		}
	}
	return card;
}

/* 
void PlayerUpDtPt( Player* _p ,Vector* _trick)
{
	int i;
	
	if(IS_VALID(_p))
	{
		for(i = 0; i < NOP,++i )
		{
			VectorGet(_trick,i,&cardId);
				if(cardId < 0)
					continue;
			VectorAdd(_p->m_disTrick,cardId);

	
		
void updatePoints(player);
int isHeartplayd()
int isvalid(Card,vector ,Heartplayd)
void passCard( player,vector ,Heartplayd)

	 

	

int main()
{
	Deal* deal;
	int i;
	Player* p[4];
	Card card = {SPADES,TWO};
	char* n[4]={ "a","b","c","d"}; 
	
	deal = DealCreate();
	for(i = 0; i < 4;++i)
		p[i] = PlayerCreate(n[i],COMP);
	
	DealCards(deal,p,13);
	for(i = 0; i < 4;++i)
		PlayerPrint(p[i]);
	printf("\n");
	for(i = 0; i < 4;++i)
	{
		if(PlayerIsCardExs(p[i],card))
		{
			PlayerPrint(p[i]);
		}
	}
	printf("\n");
	for(i=0;i<14;++i)
		CardPrint(ChoseCard(p[0],LOW));
	PlayerPrint(p[0]);
	return 0;
}
*/












	






