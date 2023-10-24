#include <stdio.h>
#include <stdlib.h>

// Declare a heap structure
struct Heap {
	int* values;
	int* original_indeces;
	int size;
	int capacity;
};

struct ValAndIndex{
  int value;
  int index;
};

//define the structs
typedef struct Heap heap;
typedef struct ValAndIndex valAndIndex;
//function declarations
heap* createHeap(int capacity, int* nums);
void insertHelper(heap* h, int index);
void heapify(heap* h, int index);
valAndIndex extractMin(heap* h);
void insert(heap* h, int data);

// Define a createHeap function
heap* createHeap(int capacity, int* nums)
{
	// Allocating memory to heap h
	heap* h = (heap*)malloc(sizeof(heap));

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

void heapify(heap* h, int index)
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

valAndIndex extractMin(heap* h){

  valAndIndex returnValues;

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

int getNumOfInversions(int A[], int N) {
    if (N <= 1) {
        return 0;
    }//no inversions if the array is size N=1 or N=0
    int inversionCount = 0;
    
    //inversion counting
    int tempArray[N][2];

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
    heap* HEAP = createHeap(N, A);//sort using the heap
    valAndIndex ValueAndIndex;//used to extract one element from the heap with its original index
    
    int sortedList[N][2];//store all elements of the array with their original indeces
    
    printf("Value                  |      Original Index\n");
    for (int i = 0; i < N; i++) {//extract values from the min heap to sort
        ValueAndIndex = extractMin(HEAP);
        sortedList[i][0] = ValueAndIndex.value;
        sortedList[i][1] = ValueAndIndex.index;
        printf("sortedList[%d][0] = %d  |   sortedList[%d][1] = %d\n", i, sortedList[i][0], i, sortedList[i][1]);

    }
    
    return inversionCount;
}

int main() {
    //test arrays
    //int A[] = {1, 20, 6, 4, 5};
    int A[] = {5, 9, 1, 8, 6, 2, 7, 3, 0, 4};
    //         0  1  2  3  4  5  6  7  8  9
    int N = sizeof(A) / sizeof(A[0]);
    printf("N: %d\n", N);
    int result = getNumOfInversions(A, N);//N is the number of elements in A
    printf("Number of inversions: %d\n", result);
    return 0;
}
