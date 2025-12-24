#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
}List;


typedef struct{
    List list;
    int front;
    int rear;
}Queue;

Queue * initialize();
bool isFull(Queue * Q);
bool isFull(Queue * Q);
void enqueue(Queue * Q, int value);
int dequeue(Queue * Q);
int front(Queue * Q);
void display(Queue * Q);




int main(){
    Queue * Q = initialize(); 
    enqueue(Q, 1);
    enqueue(Q, 2);
    enqueue(Q, 3);
    enqueue(Q, 4);
    enqueue(Q, 5);
    enqueue(Q, 6);
    enqueue(Q, 7);
    enqueue(Q, 8);
    enqueue(Q, 9);
    printf(" front is %d\n", Q->front); 
    printf("Rear is %d\n", Q->rear);
    enqueue(Q, 10);

    display(Q);
    printf("\n Dequeing Value: %d\n", dequeue(Q));
    display(Q);
    printf("\nTop Value %d\n", front(Q));

}

Queue * initialize(){
    Queue * Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;
    Q->rear = -1;
    return Q; 
}


bool isFull(Queue * Q){
    return Q->front == (Q->rear + 2) % MAX;
}

bool isEmpty(Queue * Q){
    return Q->front == (Q->rear + 1) % MAX;
}

void enqueue(Queue * Q, int value){
    if(!isFull(Q)){
        if(!isEmpty(Q)){
            Q->rear = (Q->rear + 1) % MAX;
        }else{
            Q->rear = (Q->rear + 1) % MAX; 
        }
            Q->list.items[Q->rear] = value;
    }else{
        printf("cant queue its full\n");
    }
    

}

int dequeue(Queue * Q){
    if(isEmpty(Q)) return -1; 

    int num = Q->list.items[Q->front]; 
    if(Q->rear == Q->front){
        Q->front = (Q->rear + 1) % MAX; 
    }else{
        Q->front = (Q->front + 1) % MAX; 
    }

    return num; 

}

int front(Queue * Q){
    return (!isEmpty(Q)) ? Q->list.items[Q->front] : -1;
}

void display(Queue * Q){
    int i = Q->front;

    printf("\n \nPrinting List\n");
    while(1){
        printf("%d ", Q->list.items[i]);
        if(i == Q->rear){
            break;
        }
        i = (i + 1) % MAX;
    }
}




