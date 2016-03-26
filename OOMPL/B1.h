#ifndef C_LOGIC
#define C_LOGIC
#include <math.h>
int roundoff(double);
int prime(int n)
{
	int k = roundoff( sqrt(n) );
	int i = 0;
	for (i = 2; i <=k; i++)
		if (n%i == 0)
			break;
	if (i >= k+1)
		return 0;
	else
		return i;
}

int roundoff(double p)
{
	return (int)(floor(p+0.5));
}
#endif