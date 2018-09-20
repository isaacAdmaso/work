#include "../include/Deal.h"
#include <stdlib.h>
#include <stdio.h>

#define MAGIC 645735825
#define IS_VALID(D)  ( NULL != (D) && (D)->m_magic == MAGIC)

typedef enum DIVIDE{ DONOT,DO }DIVIDE;

struct Deal
{
	Deck* m_dDeck; 		/* deck used for deal*/
	Vector* m_trick;	/*round played*/
	int m_curStPly;		/*curent leader*/
	Suit m_suit; 		/*leading suit*/
	size_t m_magic;
	
};

Deal* DealCreate()
{
	Deal* deal;
	int i;
	deal = (Deal*)malloc(sizeof(Deal));
	if(NULL == deal)
		return NULL;
	deal->m_dDeck = DeckCreate();
	deal->m_trick = VectorCreate(NOP,1);
	if(NULL == deal->m_dDeck || NULL == deal->m_trick)
	{
		free(deal);
		return NULL;
	}
	DeckShuffle(deal->m_dDeck);
	for(i = 0;i < NOP;++i )
		VectorAdd(deal->m_trick,-1);
	deal->m_curStPly = 0;
	deal->m_suit = CLUBS;
	deal->m_magic = MAGIC;
	return deal;
}


void DealDestroy(Deal* _deal)
{
	if(IS_VALID(_deal))
	{
		_deal->m_magic = 0;
		DeckDestroy(_deal->m_dDeck );
		VectorDestroy( _deal->m_trick );
		free(_deal);
	}
}

void DealCards(Deal* _deal,Player* _p[],int _nOfCard )
{
	int i,j,k,cardId=0;
	Card card;
	
	if(IS_VALID(_deal) && NULL != _p)
	{
		for(j = 0,i = 0;j < DECKSZ;j += _nOfCard,++i )
		{
			i %= NOP;
			if(i == NOP-1 && (DECKSZ-1-j) > NOP*_nOfCard )
			{
				for(k = 0;k < _nOfCard;++k )
				{
					DeckGiveOneC(_deal->m_dDeck,&cardId);
					card.m_suit = GETSUIT(cardId);
					card.m_rank =GETRANK(cardId); 
					PlayerTakeCard(_p[i],card);
				}
			}
			else
			{
				break;
			}
		}
		/*cards remained in deck*/
		for(i = 0 ;j < DECKSZ;++j,++i)
		{
			i %= NOP;
			DeckGiveOneC(_deal->m_dDeck,&cardId);		
			card.m_suit = GETSUIT(cardId);
			card.m_rank =GETRANK(cardId); 
			PlayerTakeCard(_p[i],card);			
		}
	}
}


static void DealGetNCards(Player* _p, Vector* _vec,int _numOfCard )
{
	int i,cardId;
	Card card; 
	for(i = 0;i < _numOfCard;++i )
	{
		card = PlayerCardToPass(_p,HIGH);
		cardId = GETID(card.m_suit,card.m_rank);		
		VectorAdd(_vec,cardId);
	}
}	

static void DealSetNCards(Player* _p, Vector* _vec,int _numOfCard)
{
	int i,cardId;
	Card card; 
	for(i = 0;i < _numOfCard;++i )
	{
		VectorDelete(_vec,&cardId);
		card.m_suit = GETSUIT(cardId);
		card.m_rank	= GETRANK(cardId);
		PlayerTakeCard(_p,card);
	}
}
	
void DealPassNCard( Deal* _deal,Player* _p[],int _numOfCard,int _passOrder)
{
	int i;

	for(i = NOP-1;i >= 0;--i )
		DealGetNCards(_p[i],_deal->m_trick,_numOfCard);
	for(i = 0; i < NOP;++i )
		DealSetNCards(_p[(i+_passOrder)%NOP],_deal->m_trick,_numOfCard);
	PlayerHrtStatOff(_p);
}

		
void DealWhoHasTwOClu( Deal* _deal,Player* _p[] )
{
	int i;
	
	Card card = {CLUBS,TWO};
	for(i = 0;i < NOP; ++i )
	{
		if(PlayerIsCardExs(_p[i],card))
		{
			 _deal->m_curStPly = i;
			 break;
		}
	}
}


static void DealUpPt(Player* _p[],Vector* _score);


void DealPlay(Deal *_deal,Player* _p[], Vector* _score )
{
	int i,cardId = 0,plyTrn = 0,winIdx = 0,round;
	Card card,maxCard;
	Suit suit;
	
	if(IS_VALID(_deal))
	{
		DealWhoHasTwOClu(_deal,_p);
		suit = _deal->m_suit;
		for(round = 0;round < HAND;++round )
		{
			maxCard.m_suit = NONE_S;
			maxCard.m_rank = NONE_R;
			plyTrn = _deal->m_curStPly;
			for(i = 0;i < NOP;++i )
			{	
				plyTrn = (i+_deal->m_curStPly) % NOP;
				if(i == 0 )
				{
					card = PlayerCardToPass(_p[plyTrn],LOW);
					suit = card.m_suit;
					maxCard = card;
				}
				else
				{
					card = PlayerChoseTrick(_p[plyTrn],suit,LOW);
				}
				PlayerPrint(_p[plyTrn]);
				if(card.m_suit == HEARTS)
					PlayerHrtStatOn(_p);	
				cardId = GETID( card.m_suit,card.m_rank );
				VectorSet(_deal->m_trick,i,cardId);
				if(IsBgCrs(card,maxCard))
				{
					maxCard = card;
					winIdx = plyTrn;
					CardPrint(card);
				}
			}
			PlayerTakeTrick(_p[winIdx],_deal->m_trick);
			PlayerUpDtPtTrk(_p[winIdx],_deal->m_trick);
			_deal->m_curStPly = winIdx;
		}
		PlayerHrtStatOff(_p);	
		DealUpPt(_p,_score);
	}
}	
	
	
	
static void DealUpPt(Player* _p[],Vector* _score)
{
	DIVIDE divide = DONOT;
	int i,maxPtIdx = 0,plyScr = 0,plyrPt = 0;	
	
	for(i = 0;i < NOP;++i )
	{	
		plyrPt = PlayerGetScore(_p[i]);
		if(plyrPt == -1)
			return;
		if(plyrPt == MAXPOINTS)
		{
			divide = DO;
			maxPtIdx = i;
		}
	}
	for(i = 0;i < NOP;++i )
	{
		if(divide == DO) 
		{
			if( i == maxPtIdx)
				continue;
			VectorSet(_score,i,MAXPOINTS/(NOP-1));
		}
		else
		{
			plyrPt = PlayerGetScore(_p[i]);
			VectorGet(_score,i,&plyScr);	 
			VectorSet(_score,i,plyrPt+plyScr);
		}	
		PlayerSetScore(_p[i],0);
	}
}		

int main()
{
	Deal* deal;
	int i;
	Player* p[4];
	Card card = {SPADES,TWO};
	char* n[4]={ "a","b","c","d"}; 
	size_t numOfTrk;
	Vector* v;
	
	
	v = VectorCreate(4,0); 
	deal = DealCreate();
	for(i = 0; i < 4;++i)
	{
		p[i] = PlayerCreate(n[i],COMP);
		VectorAdd(v,0);
	}
	DealCards(deal,p,13);
	DealPassNCard(deal,p,3,3);
	for(i = 0; i < 4;++i)
		PlayerPrint(p[i]);
	printf("\n");
	DealPlay(deal,p,v);
	
	VectorPrint(deal->m_trick);
	VectorPrint(v);
	return 0;
}


/*
*/ 	




