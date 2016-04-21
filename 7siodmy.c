#include <stdio.h>

#include <conio.h>

#include<stdlib.h>

void RysujSzachownice();

char line[100];

//zmienna potrzebna do fgets

void main()

{

while(1)

{

fflush(stdin);

//zerowanie bufora fgets

RysujSzachownice();

gotoxy(45,3);

printf("Szachownica :-)");

getch();

clrscr();

}

}//koniec main

//Funkcja rysujaca szachownice

void RysujSzachownice()

{

int i;

int j;

int k;

gotoxy(0,0);

printf(" ");

for(i=0;i<8;i++)

printf("%c%c%d%c%c",32,32,i+1,32,32);

printf("\n");

for(j=0; j<8; j++)

{

for(k=0; k<3; k++)

{

if (k==1) printf("%c",j+65);

else printf("%c",32);

for(i=0; i<8; i++)

{

if((i+j)%2==0) textcolor(15);

else textcolor(7);

cprintf("%c%c%c%c%c",219,219,219,219,219);

}

if (k==1) printf("%c",j+65);

else printf("%c",32);

printf("\n");

}

}

printf(" ");

for(i=0;i<8;i++)

printf("%c%c%d%c%c",32,32,i+1,32,32);

}//Koniec funkcji RysujSzachownice