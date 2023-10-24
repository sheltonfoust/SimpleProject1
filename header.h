#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_LEN 3

typedef struct _Heap {
	int* values;
	int* original_indeces;
	int size;
	int capacity;
} Heap;

typedef struct _ValueAndIndex {
	int value;
	int index;
} ValueAndIndex;

typedef struct _GlobalStruct
{
	int inversionCount;
	int dataSet[DATA_LEN];
} GlobalStruct;

typedef struct _Bound
{
	int lowerBound;
	int upperBound;
} Bound;



void mergesort(int lowerBound, int upperBound);
void merge(int lowerBound, int midPoint, int upperBound);
void springQuickSort(int lowerBound, int upperBound);
int springPartition(int lowerBound, int upperBound);
void quickSort(int lowerBound, int upperBound);
Bound partition(int lowerBound, int upperBound);

Heap* createHeap(int capacity, int* nums);
void heapify(Heap* h, int index);
ValueAndIndex extractMin(Heap* h);
int heapSort(int A[], int N);

GlobalStruct Globals;

#endif
