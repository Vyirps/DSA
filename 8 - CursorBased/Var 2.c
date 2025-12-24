#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct{
    int elem; 
    int next; 
}Cell, HeapSpace[MAX]; 


typedef struct{
    HeapSpace H; 
    int avail; 
}VHeap; 

void initialize(VHeap * V); 
int allocSpace(VHeap * V); 
void deallocSpace(VHeap * V, int index); 
void insertFirst(int * L, VHeap * V, int elem); 
void insertLast(int * L, VHeap * V, int elem); 
void insertPos(int * L, VHeap * V, int elem, int pos); 
void insertSorted(int * L, VHeap * V, int elem);
void delete(int * L, VHeap * V, int elem); 
void deleteAllOccurrences(int * L, VHeap * V, int elem); 
void display(int L, VHeap V); 

int main(){
    VHeap V; 
    int L = -1; 
    initialize(&V);
    insertFirst(&L, &V, 6);
    insertFirst(&L, &V, 7);
    insertLast(&L, &V, 10);
    insertLast(&L, &V, 10);
    insertPos(&L, &V, 4, 2);
    insertSorted(&L, &V, 8);
    
    display(L, V);
    // delete(&L, &V, 4); 
    //     display(L, V);
    deleteAllOccurrences(&L, &V, 10);
        display(L, V);
    

}



void initialize(VHeap * V){
    V->avail = MAX - 1; 
    for(int i = MAX - 1; i > 0; i--){
        V->H[i].next = i-1; 
    }

    V->H[0].next = -1; 
}


int allocSpace(VHeap * V){
    int num = V->avail; 
    V->avail = V->H[num].next; 
    return num; 
}


void deallocSpace(VHeap * V, int index){
    V->H[index].next = V->avail; 
    V->avail = index; 
}


void insertFirst(int * L, VHeap * V, int elem){
    if(V->avail == -1) return; 

    int index = allocSpace(V); 
    V->H[index].elem = elem; 
    V->H[index].next = *L; 
    *L = index; 


}
void insertLast(int * L, VHeap * V, int elem){
    if(V->avail == -1) return; 

    int index = allocSpace(V); 
    V->H[index].elem = elem; 
    V->H[index].next = -1; 
    int * trav = L; 
    while(*trav != -1){
        trav = &V->H[*trav].next; 
    }

    *trav = index; 
}
void insertPos(int * L, VHeap * V, int elem, int pos){
    if(V->avail == -1) return; 

    int index = allocSpace(V); 
    V->H[index].elem = elem; 
    int * trav = L; 
    for(int i = 0; i < pos; i++) {
        trav = &V->H[*trav].next; 
    }

    V->H[index].next = *trav; 
    *trav = index; 
}


void insertSorted(int * L, VHeap * V, int elem){

        if(V->avail == -1) return; 

    int index = allocSpace(V); 
    V->H[index].elem = elem; 
    int * trav = L;
    while(*trav != -1){
    
        if(elem < V->H[*trav].elem) break; 
        trav = &V->H[*trav].next; 
    }


    V->H[index].next = *trav; 
    *trav = index; 
}
void delete(int * L, VHeap * V, int elem){
    int * trav = L; 
    while(*trav != -1){
        if(V->H[*trav].elem == elem) break; 
        trav = &V->H[*trav].next; 
    }

    if(*trav == -1) return; 

    int goodbye = *trav; 
    *trav = V->H[goodbye].next; 
    deallocSpace(V, goodbye); 
}
void deleteAllOccurrences(int * L, VHeap * V, int elem){
    int * trav  = L;
    while(*trav != -1){

        if(V->H[*trav].elem == elem){

            int goodbye = *trav; 

            *trav = V->H[goodbye].next; 

            deallocSpace(V, goodbye); 
        }else{
        trav = &V->H[*trav].next; 
        }
    }


}
void display(int L, VHeap V){
    printf("Cursor List: ");
    for(int trav = L; trav != -1; trav = V.H[trav].next){
        printf("%d -> ", V.H[trav].elem); 
    }
    printf("NULL \n\n");
}