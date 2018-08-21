#include<stdio.h>
#include "Person.h"

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
	if(_head == NULL || _item == NULL)
	{
		return _head;
	}
	_item = &_head;
	return _head->m_next;
}

Person* ListInsertByKey(Person* _head,int _key, Person* _p)
{
	Person* cur;
	if(_head == NULL)
	{
		return _p;
	}
	cur=_head;
	while(cur != NULL)
	{
		if(cur->m_id > _key/*&& cur->m_id < _key */)
		{
			_p->m_next=cur->m_next;
			cur->m_next=_p;
			break;
		}
		cur=cur->m_next;
	}
	return _head;
}
		
Person* ListRemoveByKey(Person* _head,int _key, Person** _p)
{
	Person* cur;
	cur=_head;
	while(cur != NULL)
	{
		if(cur->m_next->m_id == _key)
		{
			_p=&cur->m_next;
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


		



































