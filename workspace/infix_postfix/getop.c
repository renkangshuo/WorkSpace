#include "calc.h"

/* getop: get next operator or numeric operand */
extern int j;
int getop(char s[], char ps[])
{
	int i;
	int c;
	i = 0;


	while ((s[0] = c = ps[j++]) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c; 	/* not a number */
	i = 0;
	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c =ps[j++]))
			;
	if (c == '.') 	/* collect fraction part */
		while (isdigit(s[++i] = c = ps[j++]))
			;
	s[i] = '\0';

	return NUMBER;
}
