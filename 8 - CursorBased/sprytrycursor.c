#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 4

/*
practice steps
1. initialize with avail as 0, L as -1 and Heap where iterate through it and set to the next until last, where u set it to -1
2. functions are insertFirst/Last(*L, *V, elem) ,allocSpace(*V), deallocSpace(*V, index), delete(*L, *V, elem), display(*V)
3. insertion two types
3.1 insert first
- check first if avail -1 for availability
- call allocspace, create node
- insert data at returned allocspace index, set next to head, set head to node(like LL insert first)

3.2 insert last
-check first if avail -1 for availability
-call allocspace, create node
-set data, set next to -1(signify its last)
-traversion from head, until -1 (trav = &V->H[*trav].next)
- set *trav to allocspace index (to connect)


4. alloc space
- create index and set it to temp , update avail to the next of temp, return temp

5. dealloc space
- set next of passed index as avail then set index as the new avail

6. deletion
- initialize *trav and temp, traverse as long as *trav is not -1 and next of trav does not match elem
- if found, set *trav as temp for index to "delete", reroute *trav to point to next of node to "delete" 
(*trav = V->H[*trav].next) then call dealloc space for "deletion"

7. display
- initialize a trav to traverse and print until -1



*/
typedef struct{
    int elem;
    int next;
}Cell, HeadSpace[MAX];

typedef struct{
    HeadSpace H;
    int avail;
}VHeap;

void initialize(VHeap *V){
    for(int i = 0;i < MAX - 1;i++){
        if(i != MAX-1){
            V->H[i].next = i+1;
        }else{
            V->H[i].next = -1;
        }
    }
}
int allocSpace(VHeap *V){
    if(V->avail != -1){
        int index = V->avail;
        V->avail = V->H[index].next;
        return index;
    }else{
        return -1;
    }
}
void deallocSpace(VHeap* V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}
void insertFirst(int* L, VHeap* V, int elem){

    if(V->avail != -1){ //iftheres still space
        printf("\nInserting Element on Avail Index %d\n", V->avail);
        int cellIndex = allocSpace(V); //
        V->H[cellIndex].elem = elem;
        V->H[cellIndex].next = *L;
        *L = cellIndex;
        printf("\nIndex %d is now the head, New avail is %d\n", *L, V->avail);
    }else{
        printf("\nCursor List is FULL\n");
    }
}
void insertLast(int* L, VHeap* V, int elem){
    if(V->avail != -1){
        printf("Inserting the element at last through Avail %d", V->avail);
        int cellIndex = allocSpace(V);
        int * trav = L;

        V->H[cellIndex].elem = elem;
        V->H[cellIndex].next = -1;
        while(*trav != -1){
            trav = &V->H[*trav].next;
        }
        *trav = cellIndex;
    }else{
        printf("\nCursor List is FULL\n");
    }
}
void delete(int* L, VHeap* V, int elem){
    int *trav = L, temp;
    while(*trav != -1 && V->H[*trav].elem != elem){
        trav = &V->H[*trav].next;
    }
    if(*trav != -1){
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V, temp);
    }else{
        printf("\nElem was not found!\n");
    }
}

void display(int * L, VHeap * V){
    int * trav = L;
    while(*trav != -1){
        int order = 0;
        printf("Order %d: Elem: %d || Pointing to %d\n", order, V->H[*trav].elem, *trav);
        trav = &V->H[*trav].next;
    }
    printf("--- End of List ---\n");
}

int main(){
    VHeap V;
    int L = -1;
    initialize(&V);
    
    int choice = 0;
    while(choice != 5){
        printf("SPRY CURSOR\n1. Insert First\n2. Insert Last\n3. Delete\n4. Display\n5. Exit\nEnter Choice: "); scanf("%d", &choice);
        int val = 0;
        switch(choice){
            case 1:
                    printf("\n--- INSERTING FIRST ---\n");
                    printf("Type the value u want to insert at FIRST: ");
                    scanf("%d", &val);
                    insertFirst(&L, &V, val);
                    printf("\n");
                break;
            case 2:
                    printf("\n--- INSERTING LAST ---\n");
                    printf("Type the value u want to insert at LAST: ");
                    scanf("%d", &val);
                    insertLast(&L, &V, val);
                    printf("\n");
                break;
            case 3:
                printf("\n--- DELETING ELEMENT ---\n");
                printf("Type the element you want to delete: ");
                scanf("%d", &val);
                delete(&L, &V, val);
                break;
            case 4:
                printf("\n--- DISPLAYING LIST ---\n");
                display(&L, &V);
                return 0;
                break;
            case 5: 
                printf("\nExiting program...\n");
                break;
            default:
                printf("Invalid Choice.");
                break;
        }
        printf("\n\n");
    }
    return 0;
}