#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int count;
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

    display(Q);
    printf("\nValue: %d\n", dequeue(Q));
    display(Q);
    printf("\nTop Value %d\n", front(Q));

}

Queue * initialize(){
    Queue * Q = (Queue*)malloc(sizeof(Queue));
    Q->list.count = 0;
    Q->front = -1;
    Q->rear = -1;
    return Q; 
}


bool isFull(Queue * Q){
    return Q->rear == MAX - 1;
}

bool isEmpty(Queue * Q){
    return Q->front == -1;
}

void enqueue(Queue * Q, int value){
    if(!isFull(Q)){
        if(!isEmpty(Q)){
             Q->rear = (Q->rear + 1) % MAX;
            
        }else{
           Q->front = 0;
            Q->rear = 0;
        }
        Q->list.items[Q->rear] = value;
        Q->list.count++;
    }
    

}

int dequeue(Queue * Q){
    if(!isEmpty(Q)){
        int num = Q->list.items[Q->front];
        if(Q->list.count == 1){
            Q->front = - 1;
            Q->rear = -1;
        }else{
            Q->front = (Q->front + 1) % MAX; 
        }
        return num;
    }else{
        printf("\nNo Value to be returned\n");
    }
}

int front(Queue * Q){
    if(!isEmpty(Q)){
        return Q->list.items[Q->front];
    }else{
        return -1;
    }
}

void display(Queue * Q){
    int i = Q->front;
    printf("\nPrinting List\n");
    while(1){
        printf("\nValue %d\n", Q->list.items[i]);
        if(i == Q->rear){
            break;
        }
        i = (i + 1) % MAX;
    }
}




