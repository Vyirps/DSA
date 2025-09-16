#include<stdio.h>
#include<stdlib.h>

#define LENGTH 10

typedef struct{
    int * elemPtr;
    int count;
    int max;
}List, *EPtr;

void initialize(List * L);
void insertPos(List L, int data, int position);
void deletePos(List L, int position);
int locate(List L, int data);
int retrieve(List L, int position);
void insertSorted(List L, int data);
void display(List L);
void resize(List L);
void makeNULL(List * L);



int main(){

    EPtr L;

}


void initialize(List * L){
    L->elemPtr = malloc(LENGTH * sizeof(int));
    L->count = 0;
    L->max = LENGTH;
}


