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

Queue * initialize();
bool isFull(Queue * q);
bool isEmpty(Queue * q);
void enqueue(Queue * q, int value);
int dequeue(Queue * q);
int front(Queue * q);
void display(Queue * q);

int main(){
    Queue * q = initialize();
    enqueue(q, 1);
    display(q);
    enqueue(q, 2); 
    enqueue(q, 3);
    enqueue(q, 4);
    display(q);
    printf("\n%d is at front\n", front(q));
    printf("\nDequeued %d\n", dequeue(q));
    display(q);
    printf("\nDequeued %d\n", dequeue(q));
    display(q);
    enqueue(q, 5);
    display(q);
    printf("\nDequeued %d\n", dequeue(q));
    printf("\nDequeued %d\n", dequeue(q));
    printf("\nDequeued %d\n", dequeue(q));
display(q);


}


Queue * initialize(){
    Queue * q = (Queue *)malloc(sizeof(Queue));
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
    node * newNode = (node *)malloc(sizeof(node));
    newNode->data = value;
    if(isEmpty(q)){
        q->front = newNode;
        q->rear = newNode;
        newNode->next = NULL;
        printf("\nQueued to the first, %d\n", newNode->data);
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
        newNode->next = NULL;
        printf("\nQueued to the rear %d\n", newNode->data);
    }
    
    
}
int dequeue(Queue * q){
    if(!isEmpty(q)){
        node * temp = q->front;
        int num = temp->data;
        q->front = q->front->next;
        
        if(isEmpty(q)){
            q->rear == NULL;
            printf("\nSet everything back to zero\n");
        }

        return num;
    }else{
        printf("No List");
        return -1;
    }
}



int front(Queue * q){
    if(!isEmpty(q)){
        return q->front->data;
    }else{
        return -1;
    }
}

void display(Queue * q){
    if(!isEmpty(q)){
        printf("\n--- List ---\n");
        node * temp = q->front;
        while(temp != NULL){
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf("\n\nList has been fully printed");
    }else{
        printf("\nEmpty\ List\n");
    }

}
