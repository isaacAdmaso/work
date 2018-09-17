#include "../include/Deal.h"
#include <stdlib.h>
#include <stdio.h>

#define MAGIC 645735825
#define IS_VALID(D)  ( NULL != (D) && (D)->m_magic == MAGIC)



struct Deal
{
	Deck* m_dDeck;
	Vector* m_trick;
	int m_curStPly;
	Suit m_suit;
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
	PlayerHrtStatChg(_p);
}

		
void DealWhoHasTwOClu( Deal* _deal,Player* _p[] )
{
	int i;
	
	Card card = {CLUBS,TWO};
	for(i = 0;i < NOP; ++i )
	{
		if(PlayerIsCardExs(_p[i],card))
			 _deal->m_curStPly = i;
	}
}

void DealTrick(Deal *_deal,Player* _p[] )
{
	int i,cardId,plyTrn,winIdx;
	Card card,maxCard;
	Suit suit;

	
	if(IS_VALID(_deal))
	{
		plyTrn = _deal->m_curStPly;
		suit = _deal->m_suit;

		maxCard.m_suit = NONE_S;
		maxCard.m_rank = NONE_R;

		for(i = 0;i < NOP;++i )
		{	
			plyTrn = (i+plyTrn) % NOP;
			card = PlayerChoseTrick(_p[plyTrn],suit,LOW);
			cardId = GETID( card.m_suit,card.m_rank );
			VectorSet(_deal->m_trick,i,cardId);
			if(IsBgCrs(card,maxCard))
			{
				maxCard = card;
				winIdx = plyTrn;
			}
		}
		PlayerTakeTrick(_p[winIdx],_deal->m_trick);
		PlayerUpDtPt(_p[winIdx]);
	}
}
			
/*
*/ 	

int main()
{
	Deal* deal;
	int i;
	Player* p[4];
	Card card = {SPADES,TWO};
	char* n[4]={ "a","b","c","d"}; 
	size_t numOfTrk;
	
	deal = DealCreate();
	for(i = 0; i < 4;++i)
		p[i] = PlayerCreate(n[i],COMP);
	
	DealCards(deal,p,13);
	for(i = 0; i < 4;++i)
		PlayerPrint(p[i]);
	printf("\n");
	DealPassNCard(deal,p,3,3);
	for(i = 0; i < 4;++i)
		PlayerPrint(p[i]);
	DealPassNCard(deal,p,3,3);
	for(i = 0; i < 4;++i)
		PlayerPrint(p[i]);
	VectorPrint(deal->m_trick);

	return 0;
}
/*	
לבדוק אם PLAYERצריך את deal!!!

*/
 /*take 3 cards*/
/*the game*/
/*dicard 3 cards*/






