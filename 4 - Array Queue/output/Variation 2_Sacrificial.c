#include<stdio.h> 
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10


typedef struct{
    int items[MAX];
    int front;
    int rear;

}Queue;

Queue * initialize();
bool isFull(Queue * q);
bool isEmpty(Queue * q);
void enqueue (Queue * q, int value);
int dequeue(Queue * q);
int front(Queue * q);
void display(Queue * q);



int main(){
    Queue * q = initialize();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    display(q);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    printf("\nDequeued value %d\n", dequeue(q));
    printf("\nDequeued value %d\n", dequeue(q));
    printf("\nDequeued value %d\n", dequeue(q));
    display(q);
    printf("\nDequeued value %d\n", dequeue(q));
    printf("\nDequeued value %d\n", dequeue(q));
    display(q);
    printf("\nDequeued value %d\n", dequeue(q));
    display(q);
    enqueue(q, 9);
    enqueue(q, 8);
    display(q);
    printf("\nFront is %d\n", front(q));
    
}



Queue * initialize(){
    Queue * q = (Queue *)malloc(sizeof(Queue));
    q->front = 1;
    q->rear = 0;
}


bool isFull(Queue * q){
    return ((q->rear + 2) % MAX) == q->front;
}
bool isEmpty(Queue * q){
    return ((q->rear + 1) % MAX) == q->front;
}



void enqueue (Queue * q, int value){
    if(!isFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->items[q->rear] = value;
        printf("\nQueued value %d\n", value);
    }else{
        printf("\nList is Full\n");
    }
}
int dequeue(Queue * q){
    if(!isEmpty(q)){
        int num = q->items[q->front];
        q->front = (q->front + 1) % MAX;
        return num;
        }else{
        printf("\nList is Empty\n");
        return -1;
        }       

}
int front(Queue * q){
    if(!isEmpty(q)){
        return q->items[q->front];
    }else{
        return -1;
    }
}
void display(Queue * q){
    if(!isEmpty(q)){
        int i = q->front;
        while(1){
            printf("\nValue %d\n", q->items[i]);
            if(i  == q->rear){
                break;
            }
            i++;
        }
    }else{
        printf("\nArjoe Redoblado Marata\n");
    }
}
 




