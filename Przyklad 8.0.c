#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int i;
	int tablica[5];
	for(i=0; i<5; i++)
	{
		printf("Podaj element tablicy o indeksie %d:”, i);
		scanf(" %d", &tablica[i]);
	}
	for(i=0; i<5; i++)
	{
		printf("tablica[%d] = %d\n", i,tablica[i]);
	}
	
	return 0;
}

