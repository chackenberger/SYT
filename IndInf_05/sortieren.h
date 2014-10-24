

#ifndef SORTIEREN_H
#define SORTIEREN_H

void msort(int*,int);
void radix_sort(int*, int);
void insertion_sort(int*, int);

typedef struct {
	int* list;
	int length;
	void (*sort)(int*,int);
} sorter;

#endif
