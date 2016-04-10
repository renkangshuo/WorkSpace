/* right: rotate x to the right by n positions */
unsigned rightrot(unsigned x, int n)
{
	int wordlength(void);
	int rbit; /* rightmost bit */

	while (n-- > 0) {
		rbit = (x & 1) << (wordlength() - 1);
		x = x >> 1;   /* shift x 1 position right */
		x = x | rbit;
	}

	return x;
}
