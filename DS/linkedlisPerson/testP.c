#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Person.h"
#include "mu_test.h"


Person** CreatPeersonList()
{
	int i;
	char s[]="yitshak";
	char c[32];
	Person* p_test=NULL;
	Person** _p/*=malloc(20*sizeof(Person*))*/;
	for(i=0;i<20;++i)
	{
		_p[i]->m_id=i+500;
		_p[i]->m_name=strcat(s,itoa(i,c,10));
		_p[i]->m_age=30+i;
		_p[i]->m_next=NULL;
	}
	return _p;
}


UNIT(Insert_Head_Null)
	Person** _p=CreatPeersonList();
	p_test=ListInsertHead(_p[2],_p[1]);/*_p[2] is head point to Null */
	ASSERT_THAT(p_test==_p[1]);
	ASSERT_THAT(_p[1]->m_next != NULL);
	ASSERT_THAT(_p[1]->m_next ==_p[2]);
END_UNIT
	
UNIT(Insert_Head_exist)
	p_test=ListInsertHead(_p[1],_p[0]);
	ASSERT_THAT(p_test==_p[0]);
	ASSERT_THAT(_p[0]->m_next != NULL);
	ASSERT_THAT(_p[0]->m_next == _p[1]);
END_UNIT

UNIT(Remove_Head_Normal)
	Person** item;
	p_test=ListRemoveHead(_p[0],item);
	ASSERT_THAT(p_test==_p[1]);
	ASSERT_THAT(*item==_p[0]);
END_UNIT	


UNIT(Remove_Head_Null)
	Person** item;
	p_test=ListRemoveHead(NULL,item);
	ASSERT_THAT(p_test==NULL);
END_UNIT
	
PrintList(_p[1]);

UNIT(Insert_By_Key)
for(i=0;i<5;++i)
{
	ListInsertByKey(_p[1],503,_p[i+3]);
}
	p_test=ListInsertByKey(_p[1],519,_p[19]);
	PrintList(_p[1]);
	ASSERT_THAT(p_test==_p[1]);
	ASSERT_THAT(_p[19]->m_next == NULL);
	ASSERT_THAT(_p[3]->m_next ==_p[4]);
	
END_UNIT	

UNIT(Remove_By_Key)
	Person** item;
	p_test=ListRemoveByKey(_p[1],502,item);
	PrintList(_p[1]);
	ASSERT_THAT(p_test==_p[1]);
	ASSERT_THAT(*item=_p[2]);
		
END_UNIT	



TEST_SUITE(LinkList_test)
	TEST(Insert_Head_Null)
	TEST(Insert_Head_exist)
	TEST(Remove_Head_Normal)
	TEST(Remove_Head_Null)
	TEST(Insert_By_Key)
	TEST(Remove_By_Key)
END_SUITE

