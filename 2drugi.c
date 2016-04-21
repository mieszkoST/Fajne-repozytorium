#include <stdio.h>

int pierwsze(int n,int pier,int k, int tab[]);

int tab[1000];

int main()

{

int n;

int i;

int j=0;

int pier;

printf("Witaj w programie obliczajacym najwieksza liczbe pierwsza mniejsza od 'n'.\nPodaj n:");

scanf("%d",&n);

pier=sqrt(n);

pierwsze(n,pier,2,tab);

}

int pierwsze(int n,int pier,int k,int tab[])

{

int i;

int j=0;

if(k==pier)

{

for(i=0; i<j; i++)

printf("Tab[%d]=%d\n",i,tab[i]);

return(0);

}

else

{

for(i=k; i<n; i++)

{

if((i%2)==1) tab[j++]=i;

}

}

return(pierwsze(n,pier,k+1,tab));

}