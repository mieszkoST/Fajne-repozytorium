#include <stdio.h>
#include <stdlib.h>
#define N 3;			//BLAD: �rednik
 
int main(void)
{
 
	int A[N] = {-2,-1,-3};
	int i;
 
	i = rand();
 
	if( (A[i] > 0) &&  (i < N)  ) //BLAD: odwrotna kolejno�� warunk�w
	{
		printf("TRAFIONY\n");
	}
	else
	{
		printf("PUDLO\n");
	}
 
	return(0);
 
}
 