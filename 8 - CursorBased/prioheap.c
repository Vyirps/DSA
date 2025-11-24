//priority heap

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 10

typedef struct{
	int array[MAX];
	int avail; 
}Heap;
//left child 2n + 1
//right child 2n + 2
//upheap trav (n-1)/2

int main(){
	Heap * arr = (Heap*)malloc(sizeof(Heap)); 
    arr->avail = -1; 
    


    insert(&arr, 1);


}

void insert(Heap * arr, int elem){
    if(arr->avail != -1){
        (arr->avail)++; 
        arr->array[arr->avail] = elem;
        upheapify(arr);
    }
}

void upheapify(Heap * arr){
    int child = (arr->avail) - 1;
    int parent; 
    while(child > 0){
        parent = (child - 1)/2;
        if(arr->array[child] > arr->array[parent]){
            int temp = arr->array[parent];
            arr->array[parent] = arr->array[child]; 
            arr->array[child] = temp;
        }
    }
}

void printArray(Heap * arr){
    printf("\nPrinting List\n");
    printf("List: ");
    for(int i = 0;i < MAX;i++){
        printf("%d ", arr[i]);
    }

    
}