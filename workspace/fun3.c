#include<stdio.h>

typedef void (*pf) (int);
pf fun(int, pf);

//void (*)(int)  fun(int,void (*)(int));
//void (*fun(int,void (*)(int)))(int);//fun是一个函数声明，函数内有两个形参，分别\
		 为int和void (*)(int),返回值是void (*)(int)

void abc(int);
int main(int argc, const char *argv[])
{
//	void (*(*p)(int,void (*)(int)))(int);
    pf (*p) (int, pf);
	
    
 //   void (*q)(int);
    pf q;

	p = fun;

	q = (*p)(100,abc);
	
	(*q)(200);

	return 0;
}

void abc(int sig)
{
	printf("sig = %d\n",sig);
}

//void (*fun(int sig,void (*p_sig)(int)))(int)
pf fun(int sig, pf p_sig)
{
	(*p_sig)(sig);

	return p_sig;
}


