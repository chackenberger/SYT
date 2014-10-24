/*
  Name of file	: Mergesort_Hackenberger.c
  Author	: Christoph Hackenberger <chackenberger@student.tgm.ac.at>
  Version	: 20141020
  Description	: Mergesort mit Funktionspointer und Struct
  Mergesort_Quelle: http://rosettacode.org/wiki/Sorting_algorithms/Merge_sort#C
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX 10

void mergesort_r(int left, int right, int * list);
void msort(int * list, int length);
void merge(int * list, int left_start, int left_end, int right_start, int right_end);
void fuellen(int *, int);

typedef struct
{
	int list[MAX];
	int length;
	void (*sort)(int*,int);
} sorter;

int main(void)
{
	srand( (unsigned) time(NULL) );
	sorter s;
	s.length = MAX;
	s.sort = msort;
	fuellen(s.list,s.length);
	printf("Unsortiert: ");
	int i;
	for(i=0;i<s.length;i++) {
		printf("%d ", *(s.list+i));
	}
	s.sort(s.list,s.length);
	printf("\nSortiert: ");
	for(i=0;i<s.length;i++) {
		printf("%d ", *(s.list+i));
	}
	return EXIT_SUCCESS;
}

void fuellen(int* list, int length)
{
	int i;
	for(i=0;i<length;i++) {
		*(list+i) = rand()%1234+1;
	}
}

void msort(int * list, int length)
{
	mergesort_r(0, length, list);
}

void merge(int * list, int left_start, int left_end, int right_start, int right_end)
{
	/* calculate temporary list sizes */
	int left_length = left_end - left_start;
	int right_length = right_end - right_start;

	/* declare temporary lists */
	int left_half[left_length];
	int right_half[right_length];

	int r = 0; /* right_half index */
	int l = 0; /* left_half index */
	int i = 0; /* list index */

	/* copy left half of list into left_half */
	for (i = left_start; i < left_end; i++, l++)
	{
		left_half[l] = list[i];
	}

	/* copy right half of list into right_half */
	for (i = right_start; i < right_end; i++, r++)
	{
		right_half[r] = list[i];
	}

	/* merge left_half and right_half back into list */
	for ( i = left_start, r = 0, l = 0; l < left_length && r < right_length; i++)
	{
		if ( left_half[l] < right_half[r] ) { list[i] = left_half[l++]; }
		else { list[i] = right_half[r++]; }
	}

	/* Copy over leftovers of whichever temporary list hasn't finished */
	for ( ; l < left_length; i++, l++) { list[i] = left_half[l]; }
	for ( ; r < right_length; i++, r++) { list[i] = right_half[r]; }
}

void mergesort_r(int left, int right, int * list)
{
	/* Base case, the list can be no simpiler */
	if (right - left <= 1)
	{
		return;
	}

	/* set up bounds to slice array into */
	int left_start  = left;
	int left_end    = (left+right)/2;
	int right_start = left_end;
	int right_end   = right;

	/* sort left half */
	mergesort_r( left_start, left_end, list);
	/* sort right half */
	mergesort_r( right_start, right_end, list);

	/* merge sorted halves back together */
	merge(list, left_start, left_end, right_start, right_end);
}
