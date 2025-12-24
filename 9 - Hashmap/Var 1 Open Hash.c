#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node{
    int elem; 
    struct node * next; 
}node, *Hash; 

void initialize(Hash array[]);
void display(Hash array[]); 
void insert(Hash array[], int key); 
void delete(Hash array[], int key); 
int hash(int key); 
void deleteAll(Hash array[]); 


int main(){
    Hash array[MAX];
    initialize(array); 
    insert(array, 10);
    insert(array, 383);
    insert(array, 32);
    insert(array, 932);
    insert(array, 83872);
    insert(array, 872);
    insert(array, 312893);
    insert(array, 67243);
    display(array);
    delete(array, 32);
    delete(array, 872);
    display(array);
    deleteAll(array); 
    display(array);

    
}


void initialize(Hash array[]){
    for(int i = 0; i < MAX; i++){
        array[i] = NULL; 
    }
}

void display(Hash array[]){\
    printf("OPEN HASH\n");
    for(int i = 0; i < MAX; i++){
        printf("Index %d: ", i); 
        node * trav = array[i];

        while(trav != NULL){
            printf("%d -> ", trav->elem);
            trav = trav->next; 
        }

        printf("NULL \n");
    }

    printf("\n\n");
}

void insert(Hash array[], int key){
    int index = hash(key); 

    node * newNode = (node*)calloc(1, sizeof(node)); 
    newNode->elem = key; 

    newNode->next = array[index]; 
    array[index] = newNode; 
}
void delete(Hash array[], int key){
    int index = hash(key);

    node ** trav = &array[index];
    while(*trav != NULL){
        if((*trav)->elem == key) break; 
        trav = &(*trav)->next;
    }

    if(*trav == NULL ) return; 

    node * del = *trav; 
    *trav = (*trav)->next; 
    free(del);
}
int hash(int key){
    int index = ((key + 132 - 10) * 5) % MAX; 
    return index;
}


void deleteAll(Hash array[]){
    for(int i = 0; i < MAX; i++){
        while(array[i] != NULL){
            node * del = array[i]; 
            array[i] = array[i]->next; 
            free(del); 
        }

    }

    printf("Cleaned!\n\n");
} 