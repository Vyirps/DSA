#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define VISITED -2

typedef struct node{
    struct node * next; 
    int val; 
}*ptr, node; 


typedef struct{
    int front; 
    int rear; 
    int qArr[MAX + 1];
}Queue; 

typedef ptr Graph[MAX];


void initGraph(Graph G); 
void initQueue(Queue * q); 
void insert(Graph G, int parent, int indexVal);
void delete(Graph G, int indexVal);
void dfs(Graph G, int val, int * marker); 
void bfs(Graph G, int start); 
void enqueue(Queue * q, int val);
int dequeue(Queue * q);  
void printGraph(Graph G); 



int main(){
    Graph G; 
    int marker[MAX]; 

    initGraph(G); 
    insert(G, 1, 2); 
    insert(G, 1, 3); 
    insert(G, 1, 5);
    insert(G, 2, 1);
    insert(G, 2, 4);
    insert(G, 3, 7);
    insert(G, 4, 5);
    insert(G, 4, 6);
    insert(G, 4, 9);
    insert(G, 6, 3);
    insert(G, 7, 8);
    insert(G, 8, 2);
    insert(G, 8, 9);
    printGraph(G); 
    printf("dfs: "); 
    dfs(G, 1, marker); 
    printf("\nbfs: ");
    bfs(G, 1);
    delete(G, 9); 
    
    
    
    
    
    

    
    
    for(int i = 0; i < MAX;i++){
        marker[i] = 0;
    }
    printGraph(G); 
    printf("dfs: "); 
    dfs(G, 1, marker); 
    printf("\nbfs: ");
    bfs(G, 1);

    

}

void initGraph(Graph G){
    printf("Initializing Graph...\n\n");
    for(int i = 0; i < MAX;i++){
        G[i] = NULL; 
    }
} 
void initQueue(Queue * q){
    q->front = -1; 
    q->rear = 0;
}
void insert(Graph G, int parent, int indexVal){
    ptr * trav = &(G[parent]); 

    while(*trav != NULL){
        if((*trav)->val == indexVal){
            printf("connection already exists!\n"); 
            return; 
        }
        trav = &(*trav)->next; 
    }

    if(*trav == NULL){
        *trav = (ptr)calloc(1, sizeof(node)); 
        (*trav)->val = indexVal; 
    }

}
void delete(Graph G, int indexVal){
    for(int i = 0; i < MAX; i++){
        ptr * trav = &(G[i]);
        while(*trav != NULL){
            if((*trav)->val == indexVal){
                printf("Data found... deleting arc... \n"); 
                break; 
            }
            trav = &(*trav)->next; 
        }

     if(*trav != NULL){
            *trav = (*trav)->next; 
     }


    }

    ptr trav; 
    while(G[indexVal] != NULL){
        trav = G[indexVal]; 
        G[indexVal] = G[indexVal]->next;
        free(trav);  
    }
}
void dfs(Graph G, int val, int * marker){
    printf("%d ", val); 
    marker[val] = VISITED; 

    for(ptr trav = G[val]; trav != NULL; trav = trav->next){
        if(marker[trav->val] != VISITED){
            dfs(G, trav->val, marker); 
        }
    }
}
void bfs(Graph G, int start){
    Queue q; 
    initQueue(&q);
    int bfsMarker[MAX]; 
    enqueue(&q, start); 


    while(q.front != -1){
        int i = dequeue(&q); 
        printf("%d ", i);
        bfsMarker[i] = VISITED; 
        ptr trav = G[i]; 
        while( trav != NULL){
            if(bfsMarker[trav->val] != VISITED){
                enqueue(&q, trav->val); 
            }

            trav = trav->next; 
        }
    }
}
void enqueue(Queue * q, int val){
    if(q->rear + 2 == q->front){
        return; 
    }

    if(q->front == -1){
        q->front = 0;
    }else{
        q->rear = (q->rear + 1) % MAX; 
    }

    q->qArr[q->rear] = val; 
}
int dequeue(Queue * q){
    if(q->front == -1){
        return -1; 
    }

    int val = q->qArr[q->front];
    if(q->front == q->rear){
        initQueue(q);
    }else{
        q->front = (q->front + 1) % MAX; 
    }

    return val; 
}
void printGraph(Graph G){
    for(int i = 0;i < MAX;i++){
        ptr trav = G[i];
        printf("[%d] ", i); 
        while(trav != NULL){
            printf("%d -> ", trav->val);
            trav = trav->next; 
        }
        printf("NULL\n"); 
    }
}