/**
 * @brief display card
 * 
 * @file Card.c
 */
#include "Card.h"
#include<stdio.h>


Card carDeck[DECKSZ]; /**represent a deck of cards */

/**
 * @brief initialize the deck
 * 
 */
void CardInit()
{
	int i;
	
	for(i = 0; i < DECKSZ;++i)
	{
		carDeck[i].m_suit = GETSUIT(i);
		carDeck[i].m_rank = GETRANK(i);
	}
}

/**
 * @brief check if two cards are equal
 * 
 * @param card1 
 * @param card2 
 * @return int 1 if equal int 0 else
 */
int IsEqCrs(Card card1,Card card2)
{
	return  card1.m_suit == card2.m_suit && card1.m_rank == card2.m_rank;
}

/**
 * @brief bool, bg
 * 
 * @param card1 
 * @param card2 
 * @return int 1 if card1 is bigger or equal to card 2 ,int 0 else
 */
int IsBgCrs(Card card1,Card card2)
{
	if(card1.m_rank >= card2.m_rank)
		if(card1.m_suit == card2.m_suit)
			return 1;
	return 0;  
}

/**
 * @brief print "card"
 * 
 * @param _card 
 */
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
		default:
			return;		
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
			printf("%s T%s%s ",TXT_BOLD_ON,TXT_BOLD_OFF,TXT_NORMAL);
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
		default:
			return;		

	}
}
/**
 * @brief print Deck of cards
 * 
 */
void CardSPrint()
{
	int i;
	for(i = 0;i < DECKSZ;++i)
		CardPrint(carDeck[i]);
}




	

