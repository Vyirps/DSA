#include<stdio.h>
#include<stdlib.h>

#define MAX 10


typedef struct{
    int data; 
    int priority; 
}Process; 

typedef struct{
    Process heap[MAX]; 
    int size; 
    int capcity; 
}PriorityQueue; 

void intializePQ(PriorityQueue * pq); 
void insert(PriorityQueue * pq, Process newNode); 
Process extractRoot(PriorityQueue * pq); 
void heapify(PriorityQueue * pq, int size, int index); 
void printHeap(PriorityQueue * pq); 
void swap(Process * a, Process * b); 
void heapsort(PriorityQueue * pq); 


int main(){
    PriorityQueue * pq = malloc(sizeof(PriorityQueue)); 
    intializePQ(pq);
    int choice; 
    
    while(choice != 5){
    printf("Welcome to prio queue! \n1. Insert\n2. Delete\n3. PrintHeap\n4. Heapsort\n5. Exit\nEnter your choice: ");
    scanf("%d", &choice);
        switch(choice){
            case 1:{
                Process newNode; 
                printf("\nType data to insert: ");
                scanf("%d", &newNode.data);
                printf("\nType the priority number: "); 
                scanf("%d", &newNode.priority); 
                insert(pq, newNode);
                printf("Inserted successfully!\n\n");
                break;
            }

            case 2:{
                printf("\nDeleting your root node...\n");
                Process root = extractRoot(pq); 
                printf("Extracted root data is %d with priority of %d\n", root.data, root.priority);
                break;  
            }

            case 3:{
                printf("Printing Heap\n"); 
                printHeap(pq); 
                printf("\n\n");
                break;
            }

            case 4:{
                printf("Transforming heap... "); 
                heapsort(pq);
                break; 
            }


            default:{
                printf("invalid choice!");
                break;
            }


        }
    }


} 

void intializePQ(PriorityQueue * pq){
    pq->capcity = MAX; 
    pq->size = 0; 
}
void insert(PriorityQueue * pq, Process newNode){
    pq->heap[pq->size] = newNode; 
    pq->size += 1; 

    for(int i = pq->size/2 - 1;i >= 0;i--){
        heapify(pq, pq->size, i); 
    }
}
Process extractRoot(PriorityQueue * pq){
    Process prio = pq->heap[0];
    pq->size -= 1; 
    swap(&pq->heap[0], &pq->heap[pq->size]);

    for(int i = pq->size/2 - 1; i >= 0; i--){
        heapify(pq, pq->size, i); 
    }

    return prio; 
}

void heapsort(PriorityQueue * pq){
    for(int i = pq->size - 1; i > 0; i--){
        swap(&(pq->heap[0]), &(pq->heap[i]));
            heapify(pq, i, 0); 
        
    }
}



void heapify(PriorityQueue * pq, int size,  int index){
    int largest = index; 
    int left = index * 2 + 1; 
    int right = index * 2 + 2; 


    if(left < size && pq->heap[left].priority > pq->heap[largest].priority){
        largest = left;
    }

    if(right < size && pq->heap[right].priority > pq->heap[largest].priority){
        largest = right; 
    }

    if(largest != index){
        swap(&pq->heap[largest], &pq->heap[index]);
        heapify(pq, size, largest);
    }
}
void printHeap(PriorityQueue * pq){
    for(int i = 0; i < pq->size; i++){
        printf("Index %d: Priority %d Data %d\n", i, pq->heap[i].priority, pq->heap[i].data); 
    }
}
void swap(Process * a, Process * b){
    Process temp = *a; 
    *a = *b; 
    *b = temp; 
}