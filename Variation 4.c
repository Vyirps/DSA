#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct
{
    int *elemPtr;
    int count;
    int max;
} List, *EPtr;

void initialize(EPtr L);
void insertPos(EPtr L, int data, int position);
void deletePos(EPtr L, int position);
int locate(EPtr L, int data);
int retrieve(EPtr L, int position);
void insertSorted(EPtr L, int data);
void display(EPtr L);
void resize(EPtr L);
void makeNULL(EPtr L);

int main()
{

    EPtr L;
    initialize(L);
}

void initialize(EPtr L)
{
    L = malloc(sizeof(List));
    L->elemPtr = malloc(LENGTH * sizeof(int));
    L->count = 0;
    L->max = LENGTH;
}

void insertPos(EPtr L, int data, int position)
{
    if(position <= L->count){
        if(L->count == L->max - 1){
            resize(L);
        }
        for(int i = L->count; i > position ;i--){
            L->elemPtr[i] = L->elemPtr[i-1];
        }

        L->elemPtr[position] = data;
        L->count++;

    }else{
        printf("\nINVALID POSITION\n");
    }



}

void deletePos(EPtr L, int position)
{
    if(position <= L->count){
        for(int i = position;i <= L->count;i++){
            L->elemPtr[i] = L->elemPtr[i+1];

        }
        printf("\nData was deleted from position %d, current num is now %d", position, L->elemPtr[position]);
    }



}
int locate(EPtr L, int data)
{
    for(int i = 0;i <= L->count;i++){
        if(data == L->elemPtr[i]){
            printf("\nElement Found! Returning position");
            return i;
        }
        printf("\nElement NOT found!");
        return -1;
    }
}

int retrieve(EPtr L, int position)
{

    if(position <= L->count){
        return L->elemPtr[position];
    }
    printf("\nPosition not valid");
    return -1;
}   

void insertSorted(EPtr L, int data)
{
    



}

void display(EPtr L)
{
    printf("\nDisplaying current list");
    for (int i = 0; i <= L->count; i++)
    {
        printf("\nIndex %d: Data %d", i, L->elemPtr[i]);
    }
}
void resize(EPtr L)
{
    L->max *= 2;
    L = realloc(L->elemPtr, L->max * sizeof(int));
}

void makeNULL(List *L)
{
    free(L->elemPtr);
}