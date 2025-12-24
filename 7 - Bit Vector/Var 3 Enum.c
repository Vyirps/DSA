#include<stdio.h>
#include<stdbool.h>

#define ARRAY_SIZE 8
typedef bool Set[ARRAY_SIZE];

void initialize(Set set);
void insert(Set set, int element);
void delete(Set set, int element);
bool find(Set set, int element);
void Union(Set A, Set B, Set C);
void intersection(Set A, Set B, Set C);
void difference(Set A, Set B, Set C);
void display(Set set);

int main(){
    Set A, B, C; 
    initialize(A);
    initialize(B);
    initialize(C);

    insert(A, 0);
    insert(A, 1);
    insert(A, 2);
    insert(A, 3);
    display(A);
    

    insert(B, 7);
    insert(B, 6);
    insert(B, 5);
    display(B);

    bool wow = find(A, 1); 
    if(wow){
        printf("\nElement 1 in a is found\n");
    }else{
        printf("\nNah\n");
    }
    
    wow = find(A, 7); 
    if(wow){
        printf("\nElement 1 in a is found\n");
    }else{
        printf("\nNah\n");
    }
    
    Union(A,B,C);
    printf("\nPrinting Union\n");
    display(C);

    insert(B, 4);
    insert(B, 3);
    intersection(A,B,C);
    printf("\nPrinting intersection\n");
    display(C);

    difference(A,B,C);
    printf("\nPrinting difference\n");
    display(C);



}



void initialize(Set set){
    for(int i = 0;i < ARRAY_SIZE;i++){
        set[i] = 0;
    }
}


void insert(Set set, int element){
    if(element >= 0 && element < ARRAY_SIZE){
        set[ARRAY_SIZE - 1 - element] = 1;
        printf("\nElement %d is now true\n", element);
    }else{
        printf("\nInvalid element cannot insert\n");
    }
}


void delete(Set set, int element){
    if(element >= 0 && element < ARRAY_SIZE){
        set[ARRAY_SIZE - 1 - element] = 0;
        printf("\nElement %d is now false\n", element);
    }else{
        printf("\nInvalid element cannot delete\n");
    }
}
bool find(Set set, int element){
    if(element >= 0 && element < ARRAY_SIZE){
        if(set[ARRAY_SIZE - 1 - element] == 1){
            return true;
        }

    }
    return false;
}
void Union(Set A, Set B, Set C){
    for(int i = 0;i < ARRAY_SIZE;i++){
        C[i] = (A[i] | B[i] );
    }
}
void intersection(Set A, Set B, Set C){
    for(int i = 0;i < ARRAY_SIZE;i++){
        C[i] = (A[i] & B[i]);
    }
}
void difference(Set A, Set B, Set C){
    for(int i = 0;i < ARRAY_SIZE;i++){
        C[i] = (A[i] & (~B[i]) );
    }
}
void display(Set set){
    printf("\nPrinting set\n");
    for(int i = ARRAY_SIZE - 1; i >= 0;i--){
        if(set[i] == 1){
            printf("%d", i);
        }
    }
    printf("\n\n");
}
