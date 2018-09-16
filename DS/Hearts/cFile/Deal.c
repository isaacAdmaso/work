#include "../include/Deal.h"
#include <stdlib.h>
#include <stdio.h>

#define MAGIC 645735825
#define IS_VALID(D)  ( NULL != (D) && (D)->m_magic == MAGIC)
#define NOP 4


struct Deal
{
	Deck* m_dDeck;
	Vector* m_trick;
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
	deal->m_trick = VectorCreate(NOP,0);
	if(NULL == deal->m_dDeck || NULL == deal->m_trick)
	{
		free(deal);
		return NULL;
	}
	DeckShuffle(deal->m_dDeck);
	for(i = 0;i < NOP;++i )
		VectorAdd(deal->m_trick,-1);
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


/*
void pass3Cards(player)

לבדוק אם PLAYERצריך את deal!!!

*/
 /*take 3 cards*/
/*the game*/
/*dicard 3 cards*/







