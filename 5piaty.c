#include <stdio.h>

int slowa(FILE *plik)

{

int i=0;

char buf[30];

while(!feof(plik))

{

fscanf(plik,"%s",buf);

i++;

}

return i;

}

int wystap(FILE *plik,char slowo[30])

{

int i=0;

char buf[30];

printf("%s\n",slowo);

fseek(plik,0,SEEK_SET);

while(!feof(plik))

{

fscanf(plik,"%s",buf);

printf("%s\n",buf);

if((strcmp(buf,slowo)==0))

i++;

}

return i;

}

main(int argc,char*argv[])

{

FILE *plik;

char buf[20];

int s,w;

plik=fopen(argv[1],"r");

if (argc!=3)

{

printf("zla liczba parametrow\n");

exit(1);

}

s=slowa(plik);

w=wystap(plik,argv[2]);

printf("Ilosc slow w podanym pliku: %d\n",s);

printf("Ilosc wystapien szukanego slowa: %d\n",w);

}