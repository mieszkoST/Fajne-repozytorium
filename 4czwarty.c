#include <stdio.h>

int main(int argc, char *argv[])

{

FILE *dane;

char bufor[100];

int *znak; //znak odczytany z pliku

if(argc != 2)

{

printf("\nNie podales argumentu. Prosze podac parametr: \n");

exit(1);

}

dane=fopen(argv[1]; "r");

if(dane==NULL) //brak pliku

{

printf("\n.....plik %s nie istnieje \n", bufor);

exit(1);

}

else

{

while((znak=fgetc(dane)) != EOF)

putc(znak, stdout);

fclose(dane);

}

printf("Nazwisko %s zostalo znalezione %d razy\n",argv[2],licznik);

return(0);

}