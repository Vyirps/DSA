#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 4

typedef struct{
    int elem;
    int next;
}Cell, HeadSpace[MAX];

typedef struct{
    HeadSpace H;
    int avail;
}VHeap;

void initialize(VHeap *V);
int allocSpace(VHeap *V);
void deallocSpace(VHeap* V, int index);
void insertFirst(int* L, VHeap* V, int elem);
void insertLast(int* L, VHeap* V, int elem);
void delete(int* L, VHeap* V, int elem);

int main(){
    VHeap V;
    int L = -1;
    initialize(&V);
    
    int choice = 0;
    while(choice != 4){
        printf("1. Insert First\n2. Insert Last\n3. Display\n4. Exit\nEnter Choice: "); scanf("%d", &choice);
        
        switch(choice){
            case 1:
                
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                printf("Exiting...");
                return 0;
                break;
            default:
                printf("Invalid Choice.");
                break;
        }
        printf("\n\n");
    }
    return 0;
}

void initialize(VHeap *V){
    V->avail = 0;
    for(int i=0; i<MAX; i++){
        if(i != MAX-1){
            V->H[i].next = i+1;
        }
        else{
            V->H[i].next = -1;
        }
    }
}

int allocSpace(VHeap *V){
    if(V->avail != -1){
        int ret = V->avail;
        V->avail = V->H[ret].next;
        return ret;
    }
}

void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell != -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

void insertLast(int* L, VHeap* V, int elem){
    int newCell = allocSpace(V);
    if(newCell !=  -1){
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
        int *trav = L;
        while(*trav != -1){
            trav = &V->H[*trav].next;
        }
        *trav = newCell;
    }
}

void delete(int* L, VHeap* V, int elem){
    int *trav, temp;
    trav = L;
    while(*trav != -1 && V->H[*trav].elem != elem){
        trav = &V->H[*trav].next;
    }
    
    if(*trav != -1){
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    }
}
