#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node * next; 
    int data;
}Node; 

typedef struct{
    Node * head; 
    int count; 
}List; 

List intialize(); 
List empty(List L);
List insertFirst(List L, int data); 
List insertLast(List L, int data); 
List insertPos(List L, int data, int index); 
List deleteStart(List L); 
List deleteLast(List L); 
List deletePos(List L, int index); 
int retrieve(List L, int index); 
int locate(List L, int data); 
void display(List L); 


int main(){
    List L = intialize();
    L = insertFirst(L, 1); 
    L = insertLast(L, 2);
    L = insertPos(L, 3, 1);
    // L = deleteStart(L);
    // L = deleteLast(L); 
    L = deletePos(L, 1);
    retrieve(L, 1) != -1 ? printf("Data in index 1 is %d\n", retrieve(L, 1)) : printf("Nonexistent\n");
    locate(L, 1) != -1 ? printf("Data 1 was found\n") : printf("Data 1 was not found\n");
        locate(L, 3) != -1 ? printf("Data 3 was found\n") : printf("Data 3 was not found\n");
    display(L); 
    
     
}



List intialize(){
    List L; 
    L.head = NULL; 
    L.count = 0; 
    return L; 
}


List empty(List L){
    for(int i = 0; i < L.count; i++){
        Node * trav = L.head;
        L.head = L.head->next; 
        free(trav);  
    }

    L.count = 0; 

    return L; 
}
List insertFirst(List L, int data){
    Node * newNode = (Node*)calloc(1, sizeof(Node)); 
    newNode->data = data; 
    newNode->next = L.head; 
    L.head = newNode; 
    L.count++; 
    return L; 
} 
List insertLast(List L, int data){
    if(L.count == 0 ) return insertFirst(L, data); 


    Node * newNode = (Node*)calloc(1, sizeof(Node)); 
    newNode->data = data; 

        Node * trav; 
        for(trav = L.head; trav->next != NULL; trav = trav->next); 
        trav->next = newNode; 
        L.count++; 

    
    return L; 
}
List insertPos(List L, int data, int index){

    if(L.count == 0) return insertFirst(L, data); 
    if(L.count == index) return insertLast(L, data); 
    if(index > L.count) return L; 

    Node * newNode = (Node*)calloc(1, sizeof(Node)); 
    newNode->data = data; 

    Node * trav; 
    int i; 
    for(trav = L.head, i = 0 ; i < index - 1; i++,  trav = trav->next){}
    newNode->next = trav->next; 
    trav->next = newNode; 
    L.count++; 


    return L; 
}
List deleteStart(List L){
    if(L.count == 0) return L; 

    Node * trav = L.head; 
    L.head = L.head->next; 
    free(trav); 

    if(--L.count == 0) L.head = NULL; 

    return L; 
}
List deleteLast(List L){
    if(L.count == 0) return L; 
    if(L.count == 1) return deleteStart(L); 

    Node * trav; 
    int i;
    for(i = 0, trav = L.head; i < L.count - 2; i++, trav = trav->next){}
    Node * del = trav->next; 
    trav->next = NULL; 
    free(del);

    L.count--; 


    return L; 
}
List deletePos(List L, int index){

    if(index < 0 || index >= L.count) return L; 
    if(L.count == 0) return L; 
    if(index == 0) return deleteStart(L); 

    Node * trav; 
    int i;
    for(i = 0, trav = L.head; i < index - 1; i++, trav = trav->next); 
    Node * del = trav->next; 
    trav->next = del->next; 
    free(del); 
    L.count--; 


    return L; 
}
int retrieve(List L, int index){
    if(index < 0 || index >= L.count) return -1; 
    if(L.count == 0) return -1;
    
    Node * trav; 
    int i;
    for(trav = L.head, i = 0; i != index; i++, trav = trav->next);
    return trav->data; 
}
int locate(List L, int data){
    if(L.count == 0) return -1; 
    Node * trav;
    for(trav = L.head; trav != NULL && trav->data != data; trav = trav->next); 
    return trav != NULL ? trav->data : -1; 
}
void display(List L){
    printf("Linked List: ");
    Node * trav; 
    for(trav = L.head; trav != NULL; trav = trav->next){
        printf("%d -> ", trav->data); 
    }
    printf("NULL"); 
}


