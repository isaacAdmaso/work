#include "Stack.h"
#include <string.h>
#include<stdlib.h>
#include<stdio.h>





char* Infix(char* _expression)
{
	int i;
	int subExpression;
	char PExpression[32];
	Stack* s; 
	s= StackCreate(5,5);
	for(i=0;_expression[i] != '\0';++i)
	{
		if(isdigit(_expression[i]))
		{
			StackPush(s,_expression[i]);
		}else if(_expression[i] == '(')
		{
			StackPush(s,_expression[i]);
		}else if(_expression[i] == ')')
		{	
			do
			{
				StackPop(s,&subExpression);
				strcpy(PExpression,(char)subExpression);
			}while(subExpression != '('|| !StackIsEmpty(s));
		}else
		{	
			StackPop(s,&subExpression);
			switch(_expression[i])
			{
				case '+':
					while(subExpression != '-' || subExpression != '('||!StackIsEmpty(s))
						{
							strcpy(PExpression,(char)subExpression);
							StackPop(s,&subExpression);
						}
						strcpy(PExpression,(char)subExpression);
						StackPush(s,_expression[i]);
						break;
				case '-':
					while(subExpression != '+' || subExpression != '('||!StackIsEmpty(s))
						{
							strcpy(PExpression,(char)subExpression);
							StackPop(s,&subExpression);
						}
						strcpy(PExpression,(char)subExpression);
						StackPush(s,_expression[i]);
						break;
						
				case '/':
					while(subExpression != '+' || subExpression != '-'|| subExpression != '('||!StackIsEmpty(s))
						{
							strcpy(PExpression,(char)subExpression);
							StackPop(s,&subExpression);
						}
						strcpy(PExpression,(char)subExpression);
						StackPush(s,_expression[i]);
						break;
						
				case '*':
					while(subExpression != '+' || subExpression != '-'|| subExpression != '('||!StackIsEmpty(s))
						{
							strcpy(PExpression,(char)subExpression);
							StackPop(s,&subExpression);
						}
						strcpy(PExpression,(char)subExpression);
						StackPush(s,_expression[i]);
						break;
				case '^':
					while(subExpression != '*' || subExpression != '('||!StackIsEmpty(s) || subExpression != '+' || subExpression != '-'|| subExpression != '(')
						{
							strcpy(PExpression,(char)subExpression);
							StackPop(s,&subExpression);
						}
						strcpy(PExpression,(char)subExpression);
						StackPush(s,_expression[i]);
						break;
		
				default:
					break;
			}
		}
	}
	StackDestroy(s);
	return PExpression;
}
		
int main()
{
	char w[] = "123+11*3^5";
	char* postfix;
	
	*postfix=Infix(w);
	printf("%s",postfix);
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

