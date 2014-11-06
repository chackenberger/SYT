

#ifndef SORTIEREN_H
#define SORTIEREN_H

void msort(int*,int);
void radix(int*, int);
void insertion(int*, int);

typedef struct {
	int* list;
	int length;
	void (*sort)(int*,int);
} sorter;

#endif
