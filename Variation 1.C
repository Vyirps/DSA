#include<stdio.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}List;

List L;

List initialize (List L); //initializes count to 0, used to compare to other values;
List insertPos(List L, int data,  int position); //check first for valid position AND count is NOT equal to MAX, then shift all elements to the right then insert
List deletePos(List L, int position); //check if position is valid, then shift elements to the left
int locate(List L, int data); //use for loop and return the position of data, if not return -1
List insertSorted(List L, int data); //initialize pos, use while loop to increment then CALL insertPos to do the job
void display(List L); //display data 



int main(){

        L = initialize(L);

    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 2);
    L = insertPos(L, 5, 3);
    display(L);

    L = insertPos(L, 4, 2);
    display(L);  

    L = deletePos(L, 1);
    display(L);  

    printf("Locate 2 -> %d\n", locate(L, 2));

    L = insertSorted(L, 3);
    display(L); 

    return 0;


}

List initialize (List L){
    L.count = 0;
    return L;
}


List insertPos(List L, int data,  int position){
    if(L.count != MAX && position <= L.count){
        for(int i = L.count; i > position; i-- ){
            L.elem[i] = L.elem[i - 1]; 
        }
        L.elem[position] = data;
        L.count++;
        printf("Number %d successufully added as position %d\n", L.elem[position], position);
        return L;
    }
    printf("INVALID");
    return L;
}


List deletePos(List L,int position){
    if(position <= L.count){
        for(int i = position;i < L.count;i++){
            L.elem[i] = L.elem[i + 1];
        }
        L.count--;
        printf("Position %d deleted, new number inside Position is %d\n", position, L.elem[position]);
        return L;
    }
    return L;
}


int locate(List L, int data){
    for(int i = 0;i < L.count;i++){
        if( data == L.elem[i]){
            printf("Data %d is found at Position %d!... returning value\n", data, i);
            return i;
        }
    }
    printf("Data NOT FOUND!");
    return -1;

}


List insertSorted(List L, int data){

    int pos = 0;
    while(data < L.elem[pos] && pos < L.count){
        pos++;
    }

    L = insertPos(L, data, pos);
    return L;
}


void display(List L){
    printf("DISPLAYING ARRAY LIST\n");
    for(int i = 0;i < L.count ;i++){
    printf("%d\n", L.elem[i]);

 }
}
