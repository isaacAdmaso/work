#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "Person.h"

/*
Person* ListInsertByKeyRec(Person* _head,int _key,Person* _p);
Person* ListRemoveByKeyRec(Person* _head,int _key, Person* _p);
struct Person
{
	int m_id;
	char m_name[128];
	int m_age;
	Person* M_next;
}
*/

typedef struct Person
{
	int m_id;
	char m_name[128];
	int m_age;
	struct Person* m_next;
}Person;
Person* ListInsertHead(Person* _head, Person* _p)
{
	if (_p == NULL)
	{
		return _head;
	}
	_p->m_next = _head;
	return _p;
}

Person* ListRemovedHead(Person* _head, Person** _item)
{
	Person* new_head;
	if(_head == NULL || _item == NULL)
	{
		return _head;
	}
	*_item = _head;
	new_head=_head->m_next;
	_head->m_next=NULL;
	return new_head; 
}

Person* ListInsertByKey(Person* _head,int _key, Person* _p)
{
	Person* cur;
	cur=_head;
	if(_head == NULL ||_key < _head->m_id)
	{
		_p->m_next = _head;
		return _p;
	}	
	while(cur->m_next != NULL)
	{
		if(cur->m_next->m_id > _key/*&& cur->m_id < _key */)
		{
			_p->m_next=cur->m_next;
			cur->m_next=_p;
			break;
		}
		cur=cur->m_next;
	}
	return _head;
}
/*
Person* ListInsertByKeyRec(Person* _head,int _key, Person* _p)
{
	if()
*/


		
Person* ListRemoveByKey(Person* _head,int _key, Person** _p)
{
	Person* cur;
	cur=_head;
	if(_head == NULL || _p ==NULL)
	{
		return _head;
	}	

	if (_key == _head->m_id)
	{
		*_p = _head;
		return _head->m_next;
	}
	
	while(cur->m_next != NULL)
	{
		if(cur->m_next->m_id == _key)
		{
			*_p=cur->m_next;
			cur->m_next=cur->m_next->m_next;
			break;
		}
		cur=cur->m_next;
	}
	return _head;
}
	

	

void  PrintList(Person* _head)
{
	Person* cur;
	int i=0;
	if(_head == NULL)
	{
		return;
	}
	cur = _head;
	while (cur != NULL)
	{
		printf("Person %d):\n I.D: %d\n NAME: %s\n AGE: %d\n",i,cur->m_id,cur->m_name,cur->m_age);
		++i;
		cur=cur->m_next;
	}
}


int main()
{

	//int i;
	//char c[32];
	char s[]="yitshak";
	char s2[]="yitshak";
	Person** item=malloc(sizeof(Person*));
	Person* p_test=malloc(sizeof(Person));
	Person* p1=malloc(sizeof(Person));
	Person* p2=malloc(sizeof(Person));
	Person* p3=malloc(sizeof(Person));
	Person* p4=malloc(sizeof(Person));
	Person* p5=malloc(sizeof(Person));
	Person* p0=malloc(sizeof(Person));
	p1->m_id =1;
	strcpy(p1->m_name,"yit30 1");
	p1->m_age = 30;
	p1->m_next = NULL;
	p2->m_id = 2;
	strcpy(p2->m_name,"yit31 2");
	p2->m_age = 31;
	p2->m_next = NULL;
	p3->m_id = 3;
	strcpy(p3->m_name,"yit32 3");
	p3->m_age = 32;
	p3->m_next = NULL;
	p4->m_id = 4;
	strcpy(p4->m_name,"yit33 4");
	p4->m_age = 33;
	p4->m_next = NULL;
	p0->m_id = 0;
	strcpy(p0->m_name,"yit29 0");
	p0->m_age = 29;
	p0->m_next =NULL;
	p5->m_id = 5;
	strcpy(p5->m_name,"yit34 5");
	p5->m_age = 34;
	p5->m_next =NULL;
	
	
	
/*	for(i=0;i<20;++i)
	{
		_p[i]->m_id=i;
		strcpy(_p[i]->m_name,s);
		_p[i]->m_age=30+i;
		_p[i]->m_next=NULL;
*/	
	p_test=ListInsertHead(p2,p1);
	p_test=ListInsertHead(p1,p5);
	p_test=ListInsertHead(p5,p0);
	//p_test=ListRemoveHead(p5,item);
	//ListInsertByKey(p_test,p0->m_id,p0);
	//ListInsertByKey(p_test,p5->m_id,p5);
	//ListInsertByKey(p_test,p4->m_id,p4);
	//PrintList(*item);
	//printf("\n");
	//p_test=ListInsert~~Head(p0,NULL);

	//printf("%d\n%d",p_test==p1,p_test==p2);
//	ListInsertHead(p_test,p0);
/*	for(i=0;i<5;++i)
	{
		ListInsertByKey(_p[0],503,_p[i+3]);
	}
*///	p_test=ListInsertByKey(p0,4,p4);
	PrintList(p_test);


	return 0;
}		



































