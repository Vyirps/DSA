//priority heap

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define MAX 10

typedef struct{
	int array[MAX];
	int last; 
}Heap;
//left child 2n + 1
//right child 2n + 2
//upheap trav (n-1)/2

void insert(Heap * arr, int elem);
void delete(Heap * arr, int elem);
void upheapify(Heap * arr);
void downheapify(Heap * arr, int elem);
void printArray(Heap * arr);



int main(){
	Heap * arr = (Heap*)calloc(MAX, sizeof(Heap)); 
    arr->last = -1; 
    while((arr->last + 1) != MAX){
    	printf("\n");
        int elem = 0;
    printf("\nInsert an element: ");
    scanf("%d", &elem);
    insert(arr, elem);
    printf("\n");
    printArray(arr);
	printf("\n");	
	}    


}

void insert(Heap * arr, int elem){
	
	
	
    if((arr->last + 1) != MAX){
    	
    	if(arr->last == -1){
    		arr->array[0] = elem;
	        (arr->last)++;
	        printf("inserted at first\n");
    		return; 
		}
    	(arr->last)++; 
        arr->array[arr->last] = elem; 
        upheapify(arr);
        printf("\ninserted at index %d\n", arr->last);
    }else{
    	    printf("\nFULL\n");
	}
}

void upheapify(Heap * arr){
    int child = arr->last;
    int parent; 
    while(child > 0){
    	printf("im heaping it\n");
        parent = (child - 1)/2;
        if(arr->array[child] > arr->array[parent]){
            int temp = arr->array[parent];
            arr->array[parent] = arr->array[child]; 
            arr->array[child] = temp;
        }
        
        child = parent; 
    }
}


void downheapify(Heap * arr, int root){
	if(root >= 0){
		int left = (2 * root) + 1; 
		int right = (2 * root) + 2;		
		int highest = -1;
		
		if(arr->array[right] > arr->array[left] && right <= arr->last){
			highest = right; 
		}
		
		if(arr->array[left] > arr->array[right] && left <= arr->last){
			highest = right; 
		}
		
		if(swap(highest, root)){
			int temp = arr->array[root]
			arr->array[root] = arr->array[highest]; 
			arr->array[highest] = root;
			downheapify(arr, highest);		
			root = highest;
			printf("limit reached\n");
		}
		
		
	}else{
		printf("cannot swap anymore\n");
	}
}

bool swap(int highest, int root){
	if(highest != -1){
		if(arr->array[highest] > arr->array[root]){
			return true;
		}
		
		
	}
	
	return false; 
}


void delete(Heap * arr, int elem){
	if(arr->last != -1){
		
		if(arr->last == 0){
			arr->array[0] = 0; 
			return; 
		}
		
		arr->array[0] = arr->array[arr->last];
		(arr->last)--; 
		downheapify(arr, 0);
		
		
		
	}else{
		printf("\nCannot delete, list is empty!\n");
	}
}


bool finder(Heap * arr, elem){
	for(int i = 0; i < arr->avail; i++){
		if(arr->array[i] == elem){
			return true; 
		}
	}
	return false;
}

void printArray(Heap * arr){
    printf("\nPrinting List\n");
    printf("List: ");
    for(int i = 0;i < arr->avail;i++){
    	printf("%d ", arr->array[i]);
	}
	printf("\nAVAIL IS %d\n", arr->avail);
	printf("\n                                         0)%d                     \n", arr->array[0]);
	printf("                    1)%d                                   2)%d                         \n", arr->array[1], arr->array[2]);
	printf("           3)%d                  4)%d                  5)%d                6)%d\n", arr->array[3], arr->array[4], arr->array[5], arr->array[6]);
	printf("    7)%d         8)%d       9)%d\n", arr->array[7], arr->array[8], arr->array[9]);
	

    
}



