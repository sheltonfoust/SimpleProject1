#include "header.h"

Heap* createHeap(int capacity, int* nums)
{
	// Allocating memory to heap h
	Heap* h = (Heap*)malloc(sizeof(Heap));

	// Checking if memory is allocated to h or not
	if (h == NULL) {
		printf("Memory error");
		return NULL;
	}
	// set the values to size and capacity
	h->size = 0;
	h->capacity = capacity;

	// Allocating memory to array
	h->values = (int*)malloc(capacity * sizeof(int));
	h->original_indeces = (int*)malloc(capacity * sizeof(int));

	// Checking if memory is allocated to h or not
	if (h->values == NULL) {
		printf("Memory error");
		return NULL;
	}
	int i;
	for (i = 0; i < capacity; i++) {
		h->values[i] = nums[i];
		h->original_indeces[i] = i;
	}

	h->size = i;
	i = (h->size - 2) / 2;
	while (i >= 0) {
		heapify(h, i);
		i--;
	}
	return h;
}

void heapify(Heap* h, int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int min = index;

	// Checking whether our left or child element
	// is at right index or not to avoid index error
	if (left >= h->size || left < 0)
		left = -1;
	if (right >= h->size || right < 0)
		right = -1;

	// store left or right element in min if
	// any of these is smaller that its parent
	if (left != -1 && h->values[left] < h->values[index])
		min = left;
	if (right != -1 && h->values[right] < h->values[min])
		min = right;

	// Swapping the nodes
	if (min != index) {
		int temp = h->values[min];
		h->values[min] = h->values[index];
		h->values[index] = temp;

		int temp2 = h->original_indeces[min];
		h->original_indeces[min] = h->original_indeces[index];
		h->original_indeces[index] = temp2;
		// recursively calling for their child elements
		// to maintain min heap
		heapify(h, min);
	}
}

ValueAndIndex extractMin(Heap* h) {

	ValueAndIndex returnValues;

	returnValues.value = h->values[0];
	returnValues.index = h->original_indeces[0];

	// Replace the deleted node with the last node
	h->values[0] = h->values[h->size - 1];
	h->original_indeces[0] = h->original_indeces[h->size - 1];
	// Decrement the size of heap
	h->size--;

	// Call minheapify_top_down for 0th index
	// to maintain the heap property
	heapify(h, 0);
	//return the value and original index of the deleted node;
	return returnValues;
}

int heapSort(int A[], int N) {
	if (N <= 1) {
		return 0;
	}//no inversions if the array is size N=1 or N=0
	int inversionCount = 0;

	//inversion counting
	int tempArray[DATA_LEN][2];

	for (int i = 0; i < N; i++) {
		tempArray[i][0] = A[i];
		tempArray[i][1] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (tempArray[i][0] > tempArray[j][0]) {
				inversionCount++;
			}
		}
	}

	//sorting
	Heap* HEAP = createHeap(N, A);//sort using the heap
	ValueAndIndex ValueAndIndex;//used to extract one element from the heap with its original index

	int sortedList[DATA_LEN][2];//store all elements of the array with their original indeces

	for (int i = 0; i < N; i++) {//extract values from the min heap to sort
		ValueAndIndex = extractMin(HEAP);
		sortedList[i][0] = ValueAndIndex.value;
		sortedList[i][1] = ValueAndIndex.index;
		Globals.dataSet[i] = sortedList[i][0];
	}

	return inversionCount;
}
