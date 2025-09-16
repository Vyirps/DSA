#include<stdio.h> 
#include<stdlib.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

EPtr L = (EPtr)malloc(sizeof(Etype));;


void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void makeNULL(EPtr L);


int main(){
    initialize(L);

    insertPos(L, 10, 0);   
    insertPos(L, 20, 1); 
    insertPos(L, 30, 2);  
    insertPos(L, 15, 1);  

    printf("\nList after insertions:\n");
    display(L);

    deletePos(L, 2);      
    printf("\nList after deleting position 2:\n");
    display(L);

    int pos = locate(L, 30);
    if (pos != -1) {
        printf("30 found at position %d\n", pos);
    }

    int val = retrieve(L, 1);
    printf("Element at position 1 is %d\n", val);

    insertSorted(L, 25);
    printf("\nList after inserting 25 sorted:\n");
    display(L);

    makeNULL(L);
    return 0;





}

void initialize(EPtr L){
    L->count = 0;
}


void insertPos(EPtr L, int data, int position){
    if(L->count != MAX && position <= L->count){
        for(int i = L->count;i > position ;i-- ){
            L->elem[i] = L->elem[i - 1];
            
        }
        L->count++;
            L->elem[position] = data;
            printf("Successfully inserted the data %d in position %d\n", data, position);
    }else{
        printf("\n\nDENIED Either List is full or invalid position");
    }

}


void deletePos(EPtr L, int position){
    if(position < L->count){
        for(int i = position;i < L->count - 1;i++){
            L->elem[i] = L->elem[i+1];
        }
        L->count--;
        printf("\nSuccessfully deleted position %d, current data at that position is now %d\n", position, L->elem[position]);
    }
}


int locate(EPtr L, int data){
    for(int i = 0;i < L->count;i++){
        if(data == L->elem[i]){
            printf("Data Found! returning position %d\n", i);
            return i;
        }
        printf("Still searching....\n");
    }
    printf("Data %d not found!\n", data);
    return -1;
}


int retrieve(EPtr L, int position){
    if(position < L->count){
        return L->elem[position];
    }else{
        printf("Invalid position!\n");
        return -1;
    }
}
void insertSorted(EPtr L, int data){
    if(L->count != MAX){
        int pos = 0;
        while(data < L->elem[pos] && pos <= L->count){
            pos++;
        }

        insertPos(L, data, pos);
    }


}



void display(EPtr L){
    for(int i = 0;i < L->count;i++){
        printf("Element %d\n", L->elem[i]);
    }
}



void makeNULL(EPtr L){
    free(L);
}