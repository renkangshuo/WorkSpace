// Operator supported: +,-,*,/,%,^,(,)
// Operator supported: all single character operands
//

#include <stdio.h>
//#include <conio.h>
#include <ctype.h>
#include "calc.h"

#define MAX 50
#define MAXOP 100

int j;


typedef struct stack
{
	int data[MAX];
	int top;

} stack;

int precedence(char);
void init(stack *);
int empty(stack *);
int full(stack *);
int pop1(stack *);
void push1(stack *, int );
int top(stack *); //value of the top element
void infix_to_postfix(char infix[], char postfix[]);

int main()
{
	int type;
	double op2;
	char s[MAXOP];
	char infix[30], postfix[30];
	printf("Enter an infix expression(eg: 5+2*4):   ");
	gets(infix);
	infix_to_postfix(infix, postfix);
	printf("\nPostfix expression: %s", postfix);
	
	int n = 0;
	int cc;
	while (cc = postfix[n] != '\0')
	{
		if (postfix[n] >= '0' && postfix[n] <= '9')
		{
			cc = postfix[n] - '0';
			push(cc);
		}
		else if (postfix[n] == '+')
			push(pop() + pop());
		else if (postfix[n] == '*')
			push (pop() * pop());
		else if (postfix[n] == '-') {
		op2 = pop();
		push(pop() - op2);
		}	

		else if (postfix[n] == '\n')
			printf("\t\n%.8g\n", pop());

		n++;
	}
	return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
	stack s;
	char x, token;
	int i, j; //i-index of infix, j-index of postfix
	init(&s);
	j = 0;

	for (i = 0;infix[i]!='\0'; i++)
	{
		token=infix[i];
		if(isalnum(token))
		{
			postfix[j++] = token;
		}
		else if(token == '(')
				push1(&s,'(');
		else if(token == ')')
			while((x = pop1(&s)) != '(')
			{
				postfix[j++] = x;
			}
				
		else
		{
			while(precedence( token ) <= precedence(top(&s)) && !empty(&s))
			{
				x = pop1(&s);
				postfix[j++] = x;

			}
			push1(&s, token);
		}

	}

	while (!empty( &s ))
	{
		x = pop1(&s);
		postfix[j++] = x;

	}
	postfix[j++] = '\n';
	postfix[j] = '\0';
}

int precedence(char x)
{
	if(x == '(')
		return(0);
	if(x == '+' || x == '-')
		return(1);
	if(x == '*' || x == '/' || x == '%')
		return(2);

	return (3);
}

void init(stack *s)
{
	s->top = -1;

}

int empty(stack *s)
{
	if (s->top == -1)
		return (1);

	return (0);
}

int full(stack *s)
{
	if (s->top == MAX-1)
		return(1);

	return (0);
}

void push1(stack *s, int x)
{
	s->top += 1;
	s->data[s->top] = x;
}

int pop1(stack *s)
{
	int x;
	x = s->data[s->top];
	s->top = s->top-1;
	return (x);
}

int top(stack *p)
{
	return (p->data[p->top]);
}
