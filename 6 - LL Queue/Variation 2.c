#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node * next; 
}node; 

typedef struct{
    node * front; 
    node * rear; 
}Queue; 

Queue * intialize(); 
bool isFull(Queue * q); 
bool isEmpty(Queue * q); 
void enqueue(Queue * q, int value);
int dequeue(Queue * q); 
int front(Queue * q); 
void display(Queue * q);



int main(){
    Queue * q = intialize(); 
    enqueue(q, 1); 
    enqueue(q, 2); 
    enqueue(q, 3);
    printf("Front num is %d\n", front(q));
    display(q); 
    printf("Dequeued num is %d\n", dequeue(q));  
    display(q); 




}


Queue * intialize(){
    Queue * q = (Queue*)malloc(sizeof(Queue)); 
    q->front = NULL; 
    q->rear = NULL;  
    return q; 
}

bool isFull(Queue * q){
    return false; 
} 
bool isEmpty(Queue * q){
    return q->front == NULL; 
}
void enqueue(Queue * q, int value){
    node * newNode = (node*)calloc(1, sizeof(node)); 
    newNode->data = value; 

    if(isEmpty(q)) q->front = newNode; 
    newNode->next = q->rear; 
    q->rear = newNode;
}
int dequeue(Queue * q){
    if(isEmpty(q)) return -1; 
    node * prev = NULL; 
    node * trav = q->rear; 
    int num = q->front->data; 
    while(trav->next != NULL){
        prev = trav; 
        trav = trav->next; 
    }

    
    if(prev == NULL){
        q->front = q->rear = NULL; 
    }else{
        prev->next = NULL; 
        q->front = prev; 
        free(trav); 
    }

    

    return num;

}
int front(Queue * q){
    return (!isEmpty(q)) ? q->front->data : -1; 
}
void display(Queue * q){
    node * trav = q->rear; 
    printf("Queue: ");
    while(trav != NULL){
        printf("%d -> ", trav->data); 
        trav = trav->next; 
    }
    printf("NULL\n\n");
}



