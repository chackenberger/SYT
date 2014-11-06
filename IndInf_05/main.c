/*
  Name of file	: main.c
  Author	: Christoph Hackenberger <chackenberger@student.tgm.ac.at>
  Version	: 20141106
  Description	: Programm zum Sortieren eines Integer Vektors. inkl CLI-Menue
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "sortieren.h"

static void fuellen(sorter* s);
static void init(sorter* s,int length, void(*sort)(int*,int));
static void un_init(sorter* s);
static void change_size(sorter* s, int length);
static void print_struct(sorter* s);
static void showCommandList();
static void sort_with(sorter* s, void(*sort)(int*,int));

int main(void) {
	srand( (unsigned) time(NULL) );
	sorter* s = (sorter*)malloc(sizeof(sorter));
	init(s,10,msort);
	char in[100];
	int cont = 1;
	while(cont) {
		printf("\n? - Commands anzeigen\n");
		printf("q - Programm beenden\n>");

		fgets(in,100,stdin);
		if(strcmp(in,"q\n") == 0)
			cont = 0;
		else if(strcmp(in,"?\n") == 0)
			showCommandList();
		else if(strcmp(in,"show\n") == 0)
			print_struct(s);
		else if(strcmp(in,"msort\n") == 0) {
			sort_with(s,msort);
			printf("\n Sortiert mit Mergesort!\n");
		}else if(strcmp(in,"radix\n") == 0) {
			sort_with(s,radix);
			printf("\n Sortiert mit Radixsort!\n");
		}else if(strcmp(in,"insertion\n") == 0) {
			sort_with(s,insertion);
			printf("\n Sortiert mit Insertionsort!\n");
		}else if(strcmp(in,"cSize\n") == 0) {
			printf("\nGeben Sie eine Groeße fuer den Vektor an (x > 0)\n>");
			fgets(in,100,stdin);
			int gr;
			int ret = sscanf(in,"%d",&gr);
			if(ret != 1 || gr < 1)
				printf("\nFehler! Sie Muessen eine Zahl > 0 eingeben!\n");
			else {
				change_size(s,gr);
				printf("\nGroeße des Vektors auf %d geaendert!",gr);
				printf("\nGeben Sie nun fuellen ein um den Vektor mit zufaelligen Zahlen zu fuellen!");
				printf("\nACHTUNG! Sollten Sie den Vektor vergroeßert haben gibt es nun nicht gefuellte Stellen");
				printf("\nDies koennte zu unerwarteten Verhalten fuehren!\n");
			}
		}else if(strcmp(in,"fuellen\n") == 0)
			fuellen(s);
		else {
			printf("\nCommand nicht gefunden! Um alle verfuegbaren Commands anzuzeigen geben Sie ? ein\n");
		}
	}
	un_init(s);
	return EXIT_SUCCESS;
}

static void fuellen(sorter* s)
{
	int i;
	for(i=0;i<s->length;i++) {
		*(s->list+i) = rand()%1234+1;
	}
}

static void init(sorter* s,int length, void(*sort)(int*,int)) {
	s->length = length;
	s->list = (int*)malloc(length * sizeof(int));
	s->sort = sort;
	fuellen(s);
}

static void un_init(sorter* s) {
	free(s->list);
	free(s);
}

static void change_size(sorter* s, int length) {
	s->length = length;
	s->list = (int*)realloc(s->list,length * sizeof(int));
}

static void sort_with(sorter* s, void(*sort)(int*,int)) {
	s->sort = sort;
	s->sort(s->list,s->length);
}

static void print_struct(sorter* s) {
	int i;
	printf("\n Zahlen: ");
	for(i=0;i<s->length;i++) {
		printf("%d ", *(s->list+i));
	}
	printf("\n");
}

static void showCommandList() {
	printf("\nshow - Zeigt die Zahlen des Vektors an\n");
	printf("msort - Mergesort auf den Vektor anwenden\n");
	printf("radix - Radixsort auf den Vektor anwenden\n");
	printf("insertion - Insertionsort auf den Vektor anwenden\n");
	printf("cSize - Aendert die Groeße des Vektors\n");
	printf("fuellen - Fuellt den Vektor mit zufaelligen Zahlen\n");
}
