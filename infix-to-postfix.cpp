/*
* Program: To convert infix to postfix.
*Author: Milan Budhathoki.
Date: July 17, 2016.
Reference:  Data structures using C and C++, chap 2, page 102 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 100

typedef struct{
	int top;
	char items[max];
}stack;

char push(stack *,char);
int pop(stack *);
int symbolValue(char);

int main()
{
	int i,w,k,b=0;
	char infix[max],a[max],y;
	stack s;
	s.top=-1;
	
	printf("enter the infix expression:\n");
	scanf("%s",&infix);
	
	for(i=0;i<=strlen(infix);i++)
	{
		if((infix[i]>='0' && infix[i]<='9') || (infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z'))
		{
			a[b++]=infix[i];
		}
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='$')
		{
			w=symbolValue(infix[i]);
			if(s.top==-1)
			{
				push(&s,infix[i]);
			}
			else if(!(s.top==-1))
			{
				y=pop(&s);
				push(&s,y);
				if(w>(k=symbolValue(y)))
				{
					push(&s,infix[i]);
				}
				else if(w<=(k=symbolValue(y)))
				{
					a[b++]=pop(&s);
					push(&s,infix[i]);
				}
			}	
		}
	}
	while(!(s.top==-1))
	{
		a[b++]=pop(&s);
	}
	printf("The postfix expression of given infix expression is: %s",a);
}

int symbolValue(char x)
{
	if(x=='+' || x=='-')
	{
		return 1;
	}
	else if(x=='*' || x=='/' || x=='%')
	{
		return 2;
	}
	else if(x=='$')
	{
		return 3;
	}
}

char push(stack *s, char x)
{
	s->items[++(s->top)]=x;
}

int pop(stack *s)
{
	int x;
	x=s->items[(s->top)--];
	return x;
}

