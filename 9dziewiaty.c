#include <stdio.h>
 
#define BASE 3 /* podstawa systemu; NIE MO¯E BYÆ WIÊKSZA OD 16, ze wzglêdu na sposób prezentacji wyniku! */
 
void rozwin(int liczba)
{
	if (liczba > 0)
	{
		/* liczba = k*BASE + cyfra, gdzie
			k = liczba/BASE 
		(czêœæ ca³kowita z dzielenia).
		Zatem 
			cyfra = liczba % BASE
		wiêc w ten sposób mo¿emy 
		znaleŸæ ostatni¹ cyfrê rozwiniêcia w bazie BASE.
		Jednak przed wydrukowaniem tej cyfry, powinniœmy znaleŸæ 
		rozwiniêcie liczby "k"! */
 
		/* Krok1: znajdŸ rozwiniêcie liczby k */
		rozwin(liczba/BASE); 
 
		/* Krok 2: wypisz ostatni¹ cyfrê rozwiniêcia */
		printf("%X", liczba % BASE); /* wydruk cyfry w formacie hex */
	}
}
 
int main(void)
{
	int liczba;
 
	printf("Podaje liczbê do konwersji:\n");
	scanf("%d", &liczba);
	printf("(%d)_10 = (", liczba);
 
	/* kilka przypadków szczegónych */
	if (liczba == 0)
	{
		/* rozwiniêcie zera jest zawsze zerem */
		printf("0\n");
		return(0);
	}
	if (liczba < 0)
	{
		/* liczbê ujemn¹ musimy poprzedziæ znakiem "-" */
		printf("-");
		/* wykonujemy dalej rozwiniêcie liczby dodatniej */
		liczba = -liczba;
	}
 
	/* teraz na pewno "liczba" jest dodatnia, 
	przystêpujemy do rozwiniêcia */
 
	rozwin(liczba);
 
	printf(")_%d\n", BASE);
 
	return(0);
}