#ifndef __PERSON_H__
#define __PERSON_H__


struct Person
{
	int m_id;
	char m_name[128];
	int m_age;
	struct Person* m_next;
};

typedef struct Person Person;

Person* ListInsertHead(Person* _head, Person* _p);
Person* ListRemoveHead(Person* _head, Person** _item);
Person* ListInsertByKey(Person* _head,int _key, Person* _p);
Person* ListInsertByKeyRec(Person* _head,int _key,Person* _p);
Person* ListRemoveByKey(Person* _head,int _key, Person** _p);
Person* ListRemoveByKeyRec(Person* _head,int _key, Person** _p);
void    PrintList(Person* _head);

#endif


