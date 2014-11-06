/*
  Name of file	: sortieren.h
  Author	: Christoph Hackenberger <chackenberger@student.tgm.ac.at>
  Version	: 20141106
  Description	: Headerfile fuer das Programm
*/
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
