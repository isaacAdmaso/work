#include "Stack.h"
#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>



int Priority(char x)
{
	switch(x)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
		break;
	}
}
	
	
	
void Infix(char* _expression)
{	
	int i=0;
	char val;
	Stack* StIn;
	Stack* StOut; 
	
	StIn= StackCreate(5,5);
	StOut=StackCreate(5,5);
	while(_expression[i]!='\0')
	{
		if(isdigit(_expression[i]))
		{	
			StackPush(StIn,_expression[i]);
			StackPush(StIn,' ');
		}else if(_expression[i]=='(')
		{
			StackPush(StOut,_expression[i]);
		}else if(_expression[i]==')')
		{
			do
			{
				StackPop(StOut,&val);
				StackPush(StIn,val);
			}while(val != '(');
		
		}else
		{
			StackTop(StOut,&val);
			while(Priority(val)>=Priority(_expression[i]))
			{
				StackPop(StOut,&val);
				StackPush(StIn,_expression[i]);
			}
			StackPush(StOut,_expression[i]);
		}
		++i;
	}
	while(!StackIsEmpty(StOut))
	{
		StackPop(StOut,&val);
		StackPush(StIn,val);

	}
	StackPrint(StIn);
}



int main()
{
	char *c="12+12*3*4^4";
	Infix(c);

}



/*





	int i;
	char *subExpression=malloc(2*sizeof(char));
	char PExpression[32];
	for(i=0;_expression[i] != '\0';++i)
	{
		if(isdigit(_expression[i]))
		{
		}else if(_expression[i] == '(')
		{
			StackPush(s,_expression[i]);
		}else if(_expression[i] == ')')
		{	
			do
			{
				StackPop(s,&subExpression);
				strcpy(PExpression,subExpression);
			}while(subExpression != "("|| !StackIsEmpty(s));
		}else
		{	
			StackPop(s,&subExpression);
			switch(_expression[i])
			{
				case '+':
					while(subExpression != "-" || subExpression != "("||!StackIsEmpty(s))
						{
							strcpy(PExpression,subExpression);
							StackPop(s,&subExpression);
						}
						strcpy(PExpression,subExpression);
						StackPush(s,_expression[i]);
						break;
				case '-':
					while(subExpression != "+" || subExpression != "("||!StackIsEmpty(s))
						{
							strcpy(PExpression,subExpression);
							StackPop(s,&subExpression);
						}
						strcpy(PExpression,subExpression);
						StackPush(s,_expression[i]);
						break;
						
				case '/':
					while(subExpression != "+" || subExpression != "-"|| subExpression != "("||!StackIsEmpty(s))
						{
							strcpy(PExpression,subExpression);
							StackPop(s,&subExpression);
						}
						strcpy(PExpression,subExpression);
						StackPush(s,_expression[i]);
						break;
						
				case '*':
					while(subExpression != "+" || subExpression != "-"|| subExpression != "("||!StackIsEmpty(s))
						{
							strcpy(PExpression,subExpression);
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
		
		
		
*/		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

