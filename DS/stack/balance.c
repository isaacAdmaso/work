#include "Stack.h"
#include <string.h>
#include<stdlib.h>
#include<stdio.h>

ADTErr BalanceParentheses(char* _lst)
{
	Stack* s =StackCreate(5,5);
	ADTErr is_Empty;
	int i,bracket,len = strlen(_lst);
	for(i=0;i<len;++i)
	{
		if(_lst[i]=='(' ||_lst[i]=='['||_lst[i]=='{')
		{
			StackPush(s,_lst[i]);
		}
		if(_lst[i]==')' ||_lst[i]==']'||_lst[i]=='}')
		{
			StackTop(s,&bracket);
			switch(_lst[i])
			{
				case ')':

					if(bracket=='(')
					{
						StackPop(s,&bracket);
					}
					break;
				case ']':
				
					if(bracket=='[')
					{
						StackPop(s,&bracket);
					}
					break;
				case '}':
					if(bracket=='{')
					{
						StackPop(s,&bracket);
					}
					break;
				default:
					StackDestroy(s);
					printf("Parentheses are not balanced ");
					return 1;
			}
		}	
	}	
	is_Empty=StackIsEmpty(s);
	StackDestroy(s);
	if(!is_Empty)
	{
		printf("Parentheses are balanced");
		StackDestroy(s);
		return is_Empty; 					
	}else
	{
		printf("Parentheses are not balanced ");
		StackDestroy(s);
		return 1;
	}
}


int main()
{	
	
	BalanceParentheses("DG()D{}[({{([])}[})]");
	return 0;
}















