#include <stdio.h>
#define N 32
int main(void)
{
	char nazwapliku[N]; /* bufor na nazw� pliku */
	FILE *fp;
	int c;
 
	printf("Podaj nazwe pliku (uwaga: mniej ni� %d znaki):\n", N);
	scanf("%s", nazwapliku);
 
	if( (fp = fopen(nazwapliku,"r")) == NULL) /* czy da�o si� otworzy�? */
	{
		/* komunikat o b��dzie wypiszemy na stderr */
		fprintf(stderr,"! Nie moge otworzyc pliku %s\n", nazwapliku);
		return(-1); /* ko�czymy program, zwracaj�c nietypow� warto�� */
	}
 
	/* kopiujemy znak po znaku, a� do napotkania ko�ca pliku */
	while( (c = getc(fp)) != EOF )
		putc(c, stdout); /* r�wnowa�nie: putchar(c) */
 
	fclose(fp);
	return(0);
}