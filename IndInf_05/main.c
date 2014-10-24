
#include <stdlib.h>
#include <stdio.h>
#include "sortieren.h"

static void fuellen(int*,int);
static void init(sorter* s,int length, void(*sort)(int*,int));
static void unintit(sorter* s);
static void change_size(sorter* s, int length);

int main(void) {
	srand( (unsigned) time(NULL) );
	sorter s;
	init(&s,10,msort);
	while(1) {

	}
	unintit(&s);
	return EXIT_SUCCESS;
}

static void fuellen(int* list, int length)
{
	int i;
	for(i=0;i<length;i++) {
		*(list+i) = rand()%1234+1;
	}
}

static void init(sorter* s,int length, void(*sort)(int*,int)) {
	s->length = length;
	s->list = (int*)malloc(length * sizeof(int));
	s->sort = sort;
	fuellen(s->list,length);
}

static void unintit(sorter* s) {
	free(s->list);
}

static void change_size(sorter* s, int length) {
	s->length = length;
	s->list = (int*)realloc(s->list,length * sizeof(int));
}
