#include<stdio.h>
#include<stdlib.h>


#define LENGTH 10

typedef struct{
    int *elemPtr;
    int count;
    int max;
}List;


List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);



int main(){
    List L;
    L = initialize(L);
    L = insertPos(L, 1, 0);
    L = insertPos(L, 2, 0);
    L = insertPos(L, 3, 0);
    display(L);
    L = deletePos(L, 2);
    display(L);
    L = insertSorted(L, 5);
    display(L);
    L = insertSorted(L, 0);
    display(L);
    int num = 3;
    int found = locate(L, num);
    if(found != -1){
        printf("Number found at %d\n", found);
    }else{
        printf("NOT FOUND");
    }

     num = 9;
    found = locate(L, num);
    if(found != -1){
        printf("Number found at %d\n", found);
    }else{
        printf("NOT FOUND\n");
    }

    display(L);



    return 0;
}





List initialize(List L){
    L.elemPtr = malloc(LENGTH * sizeof(int));
    L.count = 0;
    L.max = LENGTH;
    return L;
}


List insertPos(List L, int data, int position){
    if(position <= L.count){
        if(L.count == L.max){
            L = resize(L);
        }

        for(int i =  L.count;i > position;i--){
            L.elemPtr[i] = L.elemPtr[i - 1];
        
            
        }
        L.elemPtr[position] = data;
        L.count++;
        printf("Data %d inserted at position %d!\n", L.elemPtr[position], position);
        return L;

}else{
        return L;
    }

}

List deletePos(List L, int position){
    if(position <= L.count){
        for(int i = position;i < L.count;i++){
            L.elemPtr[i] = L.elemPtr[i + 1];
        }
        printf("deletion successful, current data at position %d is %d\n", position, L.elemPtr[position]);
        L.count--;
        return L;
    }else{
        return L;
    }

}
int locate(List L, int data){
    int i = 0;
    while(i <= L.count){
        printf("\nI count = %d\n", i);
        printf("Count is %d\n", L.count);
        printf("\n Iterating\n..");
        if(L.elemPtr[i] == data){
            printf("Data found at position %d, returning value..\n", i);
            return i;
    }
            i++;
    

}
    printf("\nData not found..\n");
    return -1;
}

List insertSorted(List L, int data){
    if(L.count == L.max){
        L = resize(L);
    }

    int pos = 0;

    while (pos < L.count && L.elemPtr[pos] < data) {
    pos++;
}

    printf("POS IS %d\n", pos);

    L = insertPos(L, data, pos);
    return L;

}
void display(List L){
    printf("DISPLAYING LIST:\n");
    for(int i = 0; i <= L.count - 1;i++){
        printf("Index %d: %d\n", i, L.elemPtr[i]);
        
    }

}



List resize(List L){
    L.max *= 2;
    L.elemPtr = realloc(L.elemPtr,L.max * sizeof(int));
    printf("LIST RESIZED! CURRENT MAX IS NOW %d", L.max);
    return L;

}