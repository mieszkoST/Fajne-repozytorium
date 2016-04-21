#include <stdio.h>
#define N 32
int main(void)
{
	char nazwapliku[N]; /* bufor na nazwê pliku */
	FILE *fp;
	int c;
 
	printf("Podaj nazwe pliku (uwaga: mniej ni¿ %d znaki):\n", N);
	scanf("%s", nazwapliku);
 
	if( (fp = fopen(nazwapliku,"r")) == NULL) /* czy da³o siê otworzyæ? */
	{
		/* komunikat o b³êdzie wypiszemy na stderr */
		fprintf(stderr,"! Nie moge otworzyc pliku %s\n", nazwapliku);
		return(-1); /* koñczymy program, zwracaj¹c nietypow¹ wartoœæ */
	}
 
	/* kopiujemy znak po znaku, a¿ do napotkania koñca pliku */
	while( (c = getc(fp)) != EOF )
		putc(c, stdout); /* równowa¿nie: putchar(c) */
 
	fclose(fp);
	return(0);
}