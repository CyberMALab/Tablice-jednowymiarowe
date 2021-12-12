# Tablice jednowymiarowe - statyczne.
Tablica to struktura danych pozwalająca przechować wiele elementów określonego typu. W praktyce można też ją zdefiniować jako zbiór indeksowanych zmiennych tego samego typu. Tablicę w języku C deklaruje się poprzez podanie typu, nazwy i rozmiaru tablicy.

`typ_zmiennej nazwa_zmiennej [rozmiar_tablicy]; `

*np.*

`int a[5]; /* 5-cio elementowa tablica liczb całkowitych */ `

Taki zapis tworzy tablicę typu *int* o rozmiarze 5, czyli 5 umieszczonych kolejno w pamięci zmiennych do których można się dostać za pomocą zapisów **a[0]**, **a[1]**, **a[2]**, **a[3]**, **a[4]**. Warto zauważyć, że ostatni element n-elementowej tablicy ma indeks n-1, ponieważ indeksowanie zmiennych tablicowych zaczyna się od 0.

|`a[0]`|`a[1]`|`a[2]`|`a[3]`|`a[4]`|
| :-: | :-: | :-: | :-: | :-: |

Bardzo ważnym jest to, że rozmiar tablicy statycznej, nie może być podawany jako zmienna. Musi być on zadeklarowany jako stała liczba, podana w kodzie (zmienne const również nie mogą być użyte jako rozmiar w tablicach statycznych). Jednak zasada ta tyczy się jedynie deklaracji tablicy. Aby dostać się do jej poszczególnych elementów, już można używać zmiennych, ale tylko całkowitoliczbowych.

Operacje których można używać na elementach tablicy, są identyczne jak operacje wykonywane na zmiennych, z tą różnicą, że aby dostać się do elementu tablicy należy do jej nazwy dodać indeks, który można wywołać za pomocą zmiennej *int*.

```
a[0] = 0;/* do pierwszego elementu tablicy */
i = 4;
a[i] = 3;/* do i-tego (w tym przypadku piątego) elementu tablicy */
```

Właściwość, która pozwala nam dostać się do elementu tablicy podając indeks jako zmienną daje nam pewnego rodzaju synergię pomiędzy tablicami a pętlami. Jest to zobrazowane przez przykład (8.0), gdzie zmienna sterująca pętli *for* jest indeksem tablicy, w każdym wykonaniu pętli.

*Przykład (8.0) Wczytanie i wypisanie wartości do tablicy za pomocą pętli*

```
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int i;
	int tablica[5];
	for(i=0; i<5; i++)
	{
		printf("Podaj element tablicy o indeksie %d:”, i);
		scanf("%d", &tablica[i]);
	}
	for(i=0; i<5; i++)
	{
		printf("tablica[%d] = %d\n", i,tablica[i]);
	}
	
	return 0;
}

```

*Wynik działania programu:*

>Podaj element tablicy o indeksie 0:1
>
>Podaj element tablicy o indeksie 1:2
>
>Podaj element tablicy o indeksie 2:3
>
>Podaj element tablicy o indeksie 3:4
>
>Podaj element tablicy o indeksie 4:5
>
>tablica[0] = 1
>
>tablica[1] = 2
>
>tablica[2] = 3
>
>tablica[3] = 4
>
>tablica[4] = 5

## **Sposoby przypisania do tablicy wartości początkowych**
Deklarując tablicę można zainicjować jej początkowe wartości. W tym celu po deklaracji tablicy należy postawić operator przypisania oraz nawias klamrowy, wewnątrz którego należy podać wartości kolejnych elementów tablicy, oddzielając je przecinkami (6.1). Można też w tej deklaracji wybrać elementy tablicy których wartości chcemy wprowadzić. W tym celu należy przed wartością dopisać w nawiasie kwadratowym indeks (6.2). Elementy które nie będą podane zostaną wyzerowane. Korzystając z tej ostatniej własności można szybko przy deklaracji tablicy wyzerować ją całą (6.3). Tworząc tablicę i nadając jej wszystkie wartości początkowe można pominąć podanie jej rozmiaru w nawiasach kwadratowych. W takiej sytuacji rozmiar tablicy zostanie przypisany równy ilości elementów podanych w nawiasach klamrowych (6.4).

*Przykłady przypisanie wartości początkowych przy inicjacji tablicy.*

*(8.1)* 

`int a[5] = { 0, 1, 5, 8, 0};  `

|0|1|5|8|0|
| :-: | :-: | :-: | :-: | :-: |

*(8.2)* 

`int a[10] = { [3]4, 1, 5, [9]3}; `

`int a[10] = { [3]=4, 1, 5, [9]=3}; `

|0|0|0|4|1|5|0|0|0|3|
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |

*(8.3)* 

`int a[10] = {0}; `

|0|0|0|0|0|0|0|0|0|0|
| :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: | :-: |

*(8.4)* 

`int a[] = {1, 5, 8, 0};  `

|1|5|8|0|
| :-: | :-: | :-: | :-: |

## **Tworzenie funkcji obsługujących tablice**
Podrozdział ten podchodzi do działania z tablicami w funkcji tylko względem praktyki. Wyjaśnienie zjawiska jest zawarte w rozdziale 14 dla którego istotnym jest zrozumienie wskaźników (rozdział 12) oraz dynamicznego tworzenia tablic (rozdział 13).  

Aby stworzyć funkcję, która wykona nam działanie na tablicy, należy zadeklarować parametr tej funkcji jako tablicę. Drugim istotnym parametrem, który należy podać, aby obsłużyć tablicę, jest jej rozmiar – uchroni to nasz program od nieoczekiwanych wyjść z tablicy w nieznany nam obszar pamięci. Bardzo ważną różnicą jest fakt, że operacje na parametrze - tablicy tak zadeklarowanej funkcji wpłyną na oryginalną tablicę. Aby wywołać funkcję operującą na tablicy, należy podać nazwę tablicy bez zawierania nawiasów kwadratowych (w praktyce jest to wskaźnik do pierwszego elementu tablicy).

*Przykład (8.5) funkcje operujące na tablicy*

``` 
#include <stdio.h>
#include <stdlib.h>

void print_array(int array[], int size);
void scan_array(int array[], int size);

int main() 
{
	int tab[5];
	scan_array(tab,5);
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
void scan_array(int array[], int size)
{
	if(size>0)
	{
		int i;
		for(i=0; i<size; i++)
		{
			printf("Podaj element tablicy o indeksie %d: ", i);
			scanf("%d", &array[i]);
		}
	}
}

```

*Wynik działania programu (identyczny jak z przykładu 6.0)*

>Podaj element tablicy o indeksie 0:1
>
>Podaj element tablicy o indeksie 1:2
>
>Podaj element tablicy o indeksie 2:3
>
>Podaj element tablicy o indeksie 3:4
>
>Podaj element tablicy o indeksie 4:5
>
>tablica[0] = 1
>
>tablica[1] = 2
>
>tablica[2] = 3
>
>tablica[3] = 4
>
>tablica[4] = 5

## **Zadania do samodzielnego wykonania:**
1. Zadeklaruj tablicę jednowymiarową wybranymi wartościami (w kodzie). A następnie wyświetl zawartość tej tablicy za pomocą pętli *for, while* i *do... while*, tworząc odpowiednie funkcje.
   1. od początku do końca tablicy,
   1. od końca do początku tablicy.
1. Napisz program, który wczytuje do tablicy 10 liczb podanych przez użytkownika, a następnie wykonuje wymienione czynności. Podziel program na funkcje, tak aby każdy podpunkt realizowała przynajmniej jedna osobna funkcja.
   1. podaje ich średnią arytmetyczną,
   1. wypisze wszystkie liczby większe od średniej,
   1. wypisze najmniejszą oraz największą liczbę,
   1. sumuje wszystkie elementy nieparzyste,
   1. wypisuje tablicę od ostatniego elementu.
1. Napisz program, który wczyta od użytkownika tablicę 10-cio elementową, a następnie posortuje ją algorytmem [sortowania bąbelkowego](https://pl.wikipedia.org/wiki/Sortowanie_b%C4%85belkowe). Stwórz funkcję *bubble\_sort().*
1. Napisz program, który wczyta od użytkownika tablicę 10-cio elementową, a następnie posortuje ją algorytmem [merge sort](https://pl.wikipedia.org/wiki/Sortowanie_przez_scalanie). Stwórz funkcję *merge\_sort().*
1. Napisz program, który wczyta od użytkownika tablicę 10-cio elementową, a następnie posortuje ją algorytmem [quick sort](https://pl.m.wikipedia.org/wiki/Sortowanie_szybkie). Stwórz funkcję *quick\_sort().*

***
[Poprzednia część](https://github.com/CyberMALab/Pierwsze-wlasne-funkcje-i-rekurencja.git) | [Spis treści](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Następna część](https://github.com/CyberMALab/Tablice-znakow.git)
***
&copy; Cyberspace Modelling and Analysis Laboratory
