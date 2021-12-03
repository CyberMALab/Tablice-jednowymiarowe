#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int size);
void scan_array(int array[], int size);

int main() 
{
	int tab[5];
	scanf_array(tab,5);
	print_array(tab,5);
	
	return 0;
}
void print_array(int array[], int size)
{
	if(size>0)
	{
		int i;
		for(i=0; i<size; i++)
		{
			printf("tablica[%d] = %d\n", i,array[i]);
		}
	}
}
void scanf_array(int array[], int size)
{
	if(size>0)
	{
		int i;
		for(i=0; i<size; i++)
		{
			printf("Podaj element tablicy o indeksie %d: ", i);
			scanf(" %d", &array[i]);
		}
	}
}

