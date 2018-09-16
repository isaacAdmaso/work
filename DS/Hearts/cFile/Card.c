#include "../include/Card.h"
#include<stdio.h>


Card g_carDeck[DECKSZ];
			
void CardInit()
{
	int i;
	
	for(i = 0; i < DECKSZ;++i)
	{
		g_carDeck[i].m_suit = GETSUIT(i);
		g_carDeck[i].m_rank = GETRANK(i);
	}
}


void CardPrint(Card _card)
{
	switch(_card.m_suit)
	{
		case SPADES:
			printf("%s%s",WHITE_BG_ON,CHR_SPADE);
			break;
		case DIAMONDS:
			printf("%s%s%s",WHITE_BG_ON,TXT_RED,CHR_DIAMOND);
			break;
		case CLUBS:
			printf("%s%s",WHITE_BG_ON,CHR_CLUB);
			break;
		case HEARTS:
			printf("%s%s%s",WHITE_BG_ON,TXT_RED,CHR_HEART);
			break;		
	}
	switch (_card.m_rank)
	{
		case TWO:
			printf("%s 2%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case THREE:
			printf("%s 3%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case FOUR:
			printf("%s 4%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case FIVE:
			printf("%s 5%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case SIX:
			printf("%s 6%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case SEVEN:
			printf("%s 7%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case EIGHT:
			printf("%s 8%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case NINE:
			printf("%s 9%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case TEN:
			printf("%s 10%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case JACK:
			printf("%s J%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case QUEEN:
			printf("%s Q%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case KING:
			printf("%s K%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
		case ACE:
			printf("%s A%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
			break;
	}
}

void CardSPrint()
{
	int i;
	for(i = 0;i < DECKSZ;++i)
		CardPrint(g_carDeck[i]);
}

/*
int main()
{
	CardInit();
	CardSPrint();
	return 0;
}
*/






	

