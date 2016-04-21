#include <stdio.h>

#include <math.h>

main()

{

int w,l,j,k,i=0,p=0;

printf("Podaj liczbe ");

scanf("%d",&k);

w=k;

while(k>=1)

{

k=k/10;

p++;

}

k=w;

while(k>=1)

{

j=k/10;

l=k%10;

p--;

i+=l*(pow(10,p));

k=j;

}

printf("%d\n",i);

}

    Program obliczaj¹cy NWD.

//program dzia³a pod Borlandem

#include<stdio.h>

#include<conio.h>

void main()

{

int a=0,b=0,t=0,nwd1=0,nwd2=0,r=0;

int NWD=0;

char temp[10];

FILE *nwd;

printf("Podaj pierwsza i druga liczbe oddzielona <space>(max 4-cyfrowa)\n");

fgets(temp,sizeof(temp),stdin);

sscanf(temp, "%d %d", &a, &b);

nwd1=a;

nwd2=b;

if(a<b)

{

t=a;

a=b;

b=t;

}

r=1;

while(r)

{

t=a;

a=b;

b=t%b;

r=b;

}

printf("NWD(%d,%d)=%d",nwd1,nwd2,a);

nwd=fopen("nwd.txt","w");

fprintf(nwd,"Najwiêkszy wspolny dzielnik liczb %d i %d wynosi NWD(%d,%d)=%d",nwd1,nwd2,nwd1,nwd2,a);

fclose(nwd);

getch();

}