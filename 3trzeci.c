#include <stdio.h>

/*Wczytanie macierzy z pliku*/

int flag=0;

int wczytanie(double **macierz, FILE *plik, int *rozmiar)

{

int i, j;

for(i=0; i<(*rozmiar); i++)

{

for(j=0; j<(*rozmiar); j++)

{

fscanf(plik, "%lf",&macierz[i][j]);

}

}

fclose(plik);

flag=1;

}//koniec funkcji

/*Wyswietlenie macierzy*/

int wyswietlenie(double **mac, int *rozmiar)

{

int i, j;

if(flag!=1) printf("\n\tUWAGA! Nie wczytales macierzy. Macierz jest pusta.\n");

else

{

printf("\nRozmiar macierzy = %d\n\n", *rozmiar);

for(i=0; i<(*rozmiar); i++)

{

for(j=0; j<(*rozmiar); j++)

{

printf("%.1lf\t",mac[i][j]);

}

printf("\n");

}

}//else

}//koniec funkcji

/*Mnozenie macierzy przez skalar*/

int mnozprzezskal(double **mac, int *rozmiar)

{

int i, j;

double skalar;

if(flag!=1) printf("\n\tUWAGA! Nie mozesz mnozyc pustej macierzy. Wczytaj macierz\n");

else

{

printf("Podaj liczbe przez ktora chcesz pomnozyc macierz ");

scanf("%lf", &skalar);

for(i=0; i<(*rozmiar); i++)

{

for(j=0; j<(*rozmiar); j++)

{

mac[i][j]*=skalar;

printf("%.1lf\t", mac[i][j]);

}

printf("\n");

}//koniec for

}//else

}//koniec funkcji

/*Dodawanie macierzy*/

int suma(double **mac, int *rozmiar )

{

int i, j;

int rozm;

double **mac2;

char nazwa_pliku[20];

FILE *stream;

double suma[*rozmiar][*rozmiar];

if(flag!=1) printf("\n\tUWAGA! Nie mozesz sumowac pustej macierzy. Wczytaj macierz\n");

else

{

printf("Podaj plik z ktorego chcesz wczytac macierz: ");

scanf("%s", &nazwa_pliku);

stream=fopen(nazwa_pliku, "r");

if(stream==NULL) printf("Nie udalo sie wczytac pliku..");

fscanf(stream,"%d", &rozm);

mac2=(double**)malloc(rozm*sizeof(double));

for(i=0; i<rozm; i++)

mac2[i]=(double*)malloc(rozm*sizeof(double));

for(i=0; i<rozm; i++)

{

for(j=0; j<rozm; j++)

{

fscanf(stream, "%lf",&mac2[i][j]);

}

}

if((*rozmiar)==rozm) //rozm - rozmiar podanej macierzy ktora chcemy dodac

{

for(i=0; i<(*rozmiar); i++)

{

for(j=0; j<(*rozmiar); j++ )

{

suma[i][j]=mac[i][j]+mac2[i][j];

printf("%.1lf\t",suma[i][j]);

}

printf("\n");

}

}//koniec if

else printf("\nNiewlasciwy rozmiar macierzy.Rozmiary macierzy musza byc sobie rowne.\n");

}//else

}//koniec funkcji

/*Mnozenie macierzy*/

int iloczyn(double **mac, int *rozmiar)

{

int i, j, k;

int rozm;

char nazwa_pliku[20];

double **mac2;

double iloczyn[*rozmiar][*rozmiar];

FILE *stream;

if(flag!=1) printf("\n\tUWAGA! Nie mozesz mnozyc pustej macierzy. Wczytaj macierz\n");

else

{

printf("Podaj plik z ktorego chcesz wczytac macierz: ");

scanf("%s", &nazwa_pliku);

stream=fopen(nazwa_pliku, "r");

if(stream==NULL) printf("Nie udalo sie wczytac pliku..");

fscanf(stream,"%d", &rozm);

mac2=(double**)malloc(rozm*sizeof(double));

for(i=0; i<rozm; i++)

mac2[i]=(double*)malloc(rozm*sizeof(double));

for(i=0; i<rozm; i++)

{

for(j=0; j<rozm; j++)

{

fscanf(stream, "%lf",&mac2[i][j]);

}

}

if((*rozmiar)==rozm) //rozm - rozmiar podanej macierzy ktora chcemy dodac

{

for(i=0; i<(*rozmiar); i++)

{ 

for(j=0; j<(*rozmiar); j++ )

{

iloczyn[i][j]=0;

for(k=0; k<(*rozmiar); k++)

{

iloczyn[i][j]+=mac[i][k]*mac2[k][j];

}

printf("%.1lf\t", iloczyn[i][j]);

}

printf("\n");

}

}//koniec if

else printf("\nNiewlasciwy rozmiar macierzy.Rozmiary macierzy musza byc sobie rowne.\n");

}//else

}//koniec funkcji

/*Slad macierzy czyli suma elementow na przekatnej*/

int slad(double **mac, int *rozmiar)

{

int i, j;

double slad;

if(flag!=1) printf("\n\tUWAGA! Nie mozesz obliczyc sladu w pustej macierzy. Wczytaj macierz.\n");

else

{

for(i=0; i<(*rozmiar); i++)

{

for(j=0; j<(*rozmiar); j++)

{

if(i==j)

{

slad+=mac[i][j];

}

}

}//for

printf("Slad wczytanej macierzy wynosi = %.1lf\n", slad);

}//else

}//koniec funkcji

main(int argc, char *argv[])

{

FILE *plik;

double **macierz;

int rozmiar;

int i;

if(argc !=2)

{

printf("Niewlasciwa liczba argumentow.\n");

exit(1);

}

plik=fopen(argv[1],"r");

if(plik == NULL)

{

fprintf(stderr,"\nError. Not exist such file.\n");

exit(1);

}

fscanf(plik, "%d", &rozmiar);

macierz=(double**)malloc((rozmiar)*sizeof(double));

for(i=0; i<rozmiar; i++)

macierz[i]=(double*)malloc(rozmiar*sizeof(double));

for(;;)

{

switch(menu())

{

case 1: wczytanie(macierz, plik, &rozmiar); break;

case 2: wyswietlenie(macierz, &rozmiar); break;

case 3: mnozprzezskal(macierz, &rozmiar); break;

case 4: suma(macierz, &rozmiar); break;

case 5: iloczyn(macierz, &rozmiar); break;

case 6: slad(macierz, &rozmiar); break;

case 7: exit(0);

}//koniec switch

}//koniec for

}//koniec main

int menu(void)

{

int c;

char s[2];

printf("\n");

printf("Program dokonujacy operacji na macierzach kwadratowych:\n\n");

printf("1. Wczytanie macierzy z pliku\n");

printf("2. Wyswietlenie macierzy\n");

printf("3. Pomnozenie macierzy przez skalar\n");

printf("4. Dodawanie dwoch macierzy./musza byc te same rozmiary/\n");

printf("5. Mnozenie macierzy./musza byc te same rozmiary/\n");

printf("6. Slad macierzy\n");

printf("7. Koniec \n");

do

{

printf("\nPodaj swoj wybor: ");

scanf("%2s",&s);c=atoi(s);

}while (c<0 || c>7);

return c;

}