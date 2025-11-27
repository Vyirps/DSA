#include<stdio.h>
#include<stdlib.h>


#define MAX 10

typedef struct{
    int arr[MAX]; 
    int size; 
    int capacity; 
}Heap; 

void insert(Heap * pq, int val); 
void deleteRoot(Heap * pq); 
void heapify(Heap * pq, int index);
void swap(int * a, int * b);
void printHeap(Heap * pq); 
void initializeHeap(Heap * pq);

int main(){
    Heap * pq = malloc(sizeof(Heap));
    initializeHeap(pq);
    printf("hello");
    insert(pq, 32);
    insert(pq, 83);
    insert(pq, 91);
    insert(pq, 67);
    insert(pq, 8);
    insert(pq, 73);
    insert(pq, 45);
    insert(pq, 56);
    insert(pq, 23);
    insert(pq, 39);


    deleteRoot(pq);
    deleteRoot(pq);
    deleteRoot(pq);
    deleteRoot(pq);
    deleteRoot(pq);
    deleteRoot(pq);
    deleteRoot(pq);
    deleteRoot(pq);
    deleteRoot(pq);
    deleteRoot(pq);


}

void initializeHeap(Heap * pq){
    pq->capacity = MAX; 
    pq->size = 0;
}


void insert(Heap * pq, int val){
    if(pq->size == pq->capacity){
        printf("Heap full!\n\n");
        return;
    }

    int child = pq->size; 
    int parent; 
    pq->size += 1; 
    printf("helloasda");
    pq->arr[child] = val; 
    printf("hello");
    while(child > 0){
        parent = (child - 1)/2;

        if(pq->arr[child] > pq->arr[parent]){
            swap(&pq->arr[child], &pq->arr[parent]);
        }

        child = parent;
    }

    printf("Inserted %d successfully", val);
    printHeap(pq);
}
void deleteRoot(Heap * pq){
    int data = pq->arr[0]; 
    pq->size -= 1;
    swap(&pq->arr[0], &pq->arr[pq->size]); 

    for(int i = pq->size/2 - 1;i >= 0;i--){
        heapify(pq, i); 
    }

    printf("Dequeued %d successfully", data);
    printHeap(pq);

}
void heapify(Heap * pq, int index){
    printf("Starting sort at %d...\n", index);
    int largest = index; 
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int leftVal = left < pq->size ? pq->arr[left] : -10;
    int rightVal = right < pq->size ? pq->arr[right] : -10;
    


    if(right < pq->size && pq->arr[right] > pq->arr[index]){
        if(rightVal > leftVal){
        largest = right;
        }
        
    }

    if(left < pq->size && pq->arr[left] > pq->arr[index]){
        if(leftVal > rightVal){
            largest = left;
        
        }
        
    }

    if(largest  != index){
        swap(&pq->arr[largest], &pq->arr[index]);
        heapify(pq, largest);
    }

}
void swap(int * a, int * b){
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}
void printHeap(Heap * pq){
    printf("Printing Heap\n");
    
    for(int i = 0; i < pq->size; i++){
        printf("Index %d PrioNum: %d\n", i, pq->arr[i]);
    }


}