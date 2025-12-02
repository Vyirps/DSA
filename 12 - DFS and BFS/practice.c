#include<stdio.h>
#include<stdlib.h>

#define MAX 10 
#define VISITED -2

typedef struct node{
    struct node * next; 
    int data; 
}*ptr, node; 

typedef struct{
    int front;
    int rear;
    int arrQ[MAX + 1]; 
}Queue; 

typedef ptr Graph[MAX];
typedef int vertex; 


void initQueue(Queue * Q);
void initGraph(Graph G);
void insert(Graph G, vertex parent, vertex indexVal); 
void delete(Graph G, vertex val);
void enqueue(Queue * Q, vertex val);
vertex dequeue(Queue * Q);  
void dfs(Graph G, vertex val, int * marker);
void bfs(Graph G, vertex start);
void printGraph(Graph G); 


int main(){
    Graph G; 
    initGraph(G); 
    int marker[MAX];


    initGraph(G);
    insert(G, 1, 2);
    insert(G, 1, 3);
    insert(G, 1, 5);
    insert(G, 2, 4);
    insert(G, 2, 1);
    insert(G, 3, 7);
    insert(G, 4, 5);
    insert(G, 4, 6);
    insert(G, 4, 9);
    insert(G, 7, 8); 

    insert(G, 8, 2);
    insert(G, 8, 9);
        printGraph(G);
    printf("DFS: ");
    dfs(G, 1, marker); 
    printf("\nBFS: ");
    bfs(G, 1);


    node ** trav = &(G[1]);
    node * curr = G[1];
    printf("\ndouble ptr addresses\n1. arr box add %d\n2. dbl ptr %d\n", &(G[1]), trav);
    printf("single ptr addresses\n1. arr inside add %d\n2. curr add %d\n3. derefed trav %d\n4. double deref add %d\n5. Double Pointer add %d\n6. Travnext %d \n7.g[].next %d", G[1], curr, *trav, **trav, &trav,(*trav)->next, G[1]->next);

}


void initQueue(Queue * Q){
    Q->front = -1; 
    Q->rear = 0; 
}
void initGraph(Graph G){
    for(int i = 0; i < MAX; i++){
        G[i] = NULL; 

        
    }
}
void insert(Graph G, vertex parent, vertex indexVal){
    node ** trav = &(G[parent]); 
    node * newNode = (ptr)calloc(1, sizeof(node)); 
    newNode->data = indexVal; 

    while(*trav != NULL){
        if((*trav)->data == indexVal){
            printf("dupe exist\n");
            return; 
        }

        trav = &(*trav)->next; 
    }

    *trav = newNode; 
} 
void delete(Graph G, vertex val){
    for(int i = 0; i < MAX; i++){
        node ** trav = &(G[i]);
        while(*trav != NULL){
            if((*trav)->data == val){
                printf("value found\n"); 
                break; 
            }
            trav = &(*trav)->next; 
            
        }

        *trav = (*trav)->next; 
         
    }


    node * curr; 
    while(curr != NULL){
        curr =  G[val]; 
        G[val] = G[val]->next;
        free(curr); 
    }

}
void enqueue(Queue * Q, vertex val){
    if((Q->rear + 2) % MAX == Q->front){
        return; 
    }

    if(Q->front == -1){
        Q->front = 0;
    }else{
        Q->rear = (Q->rear + 1) % MAX; 
    }

    Q->arrQ[Q->rear] = val; 
}
vertex dequeue(Queue * Q){
    if(Q->front == -1) {
        return -1; 
    }


    vertex v = Q->arrQ[Q->front]; 
    if(Q->front == Q->rear){
        initQueue(Q); 
    }else{
        Q->front = (Q->front + 1) % MAX; 
    }

    return v; 
}
void dfs(Graph G, vertex val, int * marker){
    printf("%d ", val);
    marker[val] = VISITED; 

    for(node * trav = G[val];trav != NULL;trav = trav->next){
        if(marker[trav->data] != VISITED){
            dfs(G, trav->data, marker); 
        }
    }
}
void bfs(Graph G, vertex start){
    Queue Q; 
    initQueue(&Q);
    int bfsMarker[MAX]; 
    enqueue(&Q, start);
    while(Q.front != -1){

        vertex i = dequeue(&Q);
        bfsMarker[i] = VISITED; 
        node * trav = G[i];
        printf("%d ", i); 


        while(trav != NULL){
            if(bfsMarker[trav->data] != VISITED){
                enqueue(&Q, trav->data);
            }
            trav = trav->next;
        }
    }

}
void printGraph(Graph G){
    for(int i = 0; i < MAX; i++){
        node * trav = G[i]; 
        printf("%d | ", i);
        while(trav != NULL){
            printf("%d -> ", trav->data);
            trav = trav->next;
        }
        printf("NULL\n"); 


    }
}