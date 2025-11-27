/*
Priority Queue
- A queueing system that uses Max Heap, where starting from root each child will always be lower than the parent
Formulas to note
Parent = (child index - 1)/2
Left = 2(parent index) + 1
Right = 2(parent index) + 2
Delete root heapsort = size/2 - 1

PQ's Typedef 
typedef struct {
    int priority; // Priority level (Higher number = Higher priority)
    //maybe some other data
} Process;

// Priority Queue Structure (Max Heap Implementation)
// The heap array will store the processes.
typedef struct {
    Process heap[MAX_PROCESSES]; // Array to store the heap elements
    int size;                    // Current number of processes in the queue
    int capacity;                // Maximum capacity of the queue
} PriorityQueue;


Basic commands
1. enqueue(PriorityQueue * pq, int priority)
- Insert data at last available node (size), then increment
- while loop to upheapify(pushing the number up the tree until root)
    - upheapify uses a while loop that compares child and parent, call swap func if child is greater
- functions ends

2. dequeue(PriorityQueue * pq)
* depending on whats asked, might be a non void func that asks for returned value(extracted root)
- Swap data of root and last, then decrement size;
- Start a for loop where I starts at the last non leaf, each iteration call heapify to fix the heap
    - take note that the heapify argument would be heapify(pq, i)
    *we need to pass i as index for heapify to start there

3. Swap(Process * a, Process * b)
*Make sure the passed value to this functions are ADDRESSES of the struct containing data
- initialize temp to store the value of a(Process temp = *a)
- swap, assign value of b(*b) to value of a(*a) where (*a = *b)
- *b = temp

4. Heapify(PriorityQueue * pq, int i)
*concept of heapify is checks if a swap is possible, if it is then swap then recursively call the number
- initialize variables to store
largest = i //current parent index
left = 2(i) + 1 //current's left child
right = 2(i) + 2 //current's right child

- Setup two if statements, where both:
checks if its under size, meaning valid
if childs index value is higher than largest's index value, assign that specific child as largest 

- check if largest is not equal to i(if its not eq, it means a child is greater)
if condition was fulfilled:
call swap function on largest and i, then heapify where we pass largest as 2nd argument


*/


code from sir edwins problem: 
#include <stdio.h>
#include <stdlib.h>
#include "types.h"


/*
#ifndef TYPES_H
#define TYPES_H

// Maximum number of processes the scheduler can hold
#define MAX_PROCESSES 10

// Process Structure
// A structure representing a task/process in the operating system.
typedef struct {
    int pid;      // Process ID (Unique Identifier)
    int priority; // Priority level (Higher number = Higher priority)
} Process;

// Priority Queue Structure (Max Heap Implementation)
// The heap array will store the processes.
typedef struct {
    Process heap[MAX_PROCESSES]; // Array to store the heap elements
    int size;                    // Current number of processes in the queue
    int capacity;                // Maximum capacity of the queue
} PriorityQueue;

void initQueue(PriorityQueue *pq);
void swap(Process *a, Process *b);
void heapifyDown(PriorityQueue *pq, int index);
void insertProcess(PriorityQueue *pq, Process newProcess);
Process extractMax(PriorityQueue *pq);
void printQueue(PriorityQueue *pq);
void runEnqueueTest(void);
void runDequeueTest(void);
void runCombinationTest(void);

#endif

*/


void initQueue(PriorityQueue *pq){
    pq->capacity = MAX_PROCESSES; 
    pq->size = 0; 
    
    printf("\n--- Scheduler Queue initialized with capacity 10. ---\n");
}

void swap(Process *a, Process *b){
    Process temp = *a;
    *a = *b;
    *b = temp; 
}


void heapifyDown(PriorityQueue *pq, int index){
    int largest = index; 
    int left = 2 * index + 1; 
    int right = 2 * index + 2; 

    
    if( left < pq->size && &&pq->heap[left].priority > pq->heap[largest].priority){
        largest = left; 
    }
    
    if(right < pq->size && pq->heap[right].priority > pq->heap[largest].priority ){
        largest = right; 
    }
    
    if(largest != index){
        swap(&pq->heap[largest], &pq->heap[index]);
        heapifyDown(pq, largest);
        
    }
    
}
void insertProcess(PriorityQueue *pq, Process newProcess){
    pq->heap[pq->size] = newProcess; 
    pq->size += 1; 

    int child = pq->size-1;
    int parent; 
    while(child >= 0){
        parent = (child -1)/2;
        if(pq->heap[child].priority > pq->heap[parent].priority){
            swap(&pq->heap[child], &pq->heap[parent]); 
        }else{
            break;
        }
        
        child = parent; 
    }
    
    printf("-> ENQUEUED: Process ID %d (Priority: %d)\n", newProcess.pid, newProcess.priority);
}

Process extractMax(PriorityQueue *pq){
    Process maxNode = pq->heap[0];
    pq->size -= 1;
    swap(&pq->heap[0], &pq->heap[pq->size]);
    

    
    for(int i = pq->size/2 - 1; i >= 0; i--){
        heapifyDown(pq, i); 
    }
    
    
    return maxNode; 
    
}