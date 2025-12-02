#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10
#define VISITED -2

typedef struct node{
    struct node * next; 
    int data; 
}node, *ptr;

typedef struct{
    int front; 
    int rear; 
    int qArr[MAX + 1];
}Queue; 

typedef ptr Graph[MAX];

void initGraph(Graph G);
void initQueue(Queue * Q);
void insert(Graph G, int parent, int indexVal);
void delete(Graph G, int target); 
void dfs(Graph G, int parent, int * marker);
void bfs(Graph G, int * marker);
void enqueue(Queue * Q, int index); 
int dequeue(Queue * Q); 
void printGraph(Graph G);
 




int main(){
    Graph G; 
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
    insert(G, 7, 8);
    insert(G, 8, 2);
    insert(G, 8, 9);
    printf("DFS: ");
    dfs(G, 1, marker); 
    int bfsMarker[MAX];
    printf("\nBFS: ");
    bfs(G, bfsMarker);



}

void printGraph(Graph G){
    for(int i = 0; i < MAX; i++){
        printf("%d | ", i);
        ptr trav = G[i]; 
        while(trav != NULL){
            printf("%d -> ", trav->data);
            trav = trav->next;
        }
        printf("NULL");
        printf("\n");
    }
}

void initGraph(Graph G){
    for(int i = 0;i < MAX;i++){
        G[i] = NULL; 
    }
}
void initQueue(Queue * Q){
    Q->front = -1; 
    Q->rear = 0; 
}
void insert(Graph G, int parent, int indexVal){


    ptr * trav = &(G[parent]);
    ptr newNode = (ptr)calloc(1, sizeof(node));
    newNode->data = indexVal;

    while(*trav != NULL){
        if((*trav)->data == indexVal){
            printf("dupli found!\n");
            return; 
        }

        trav = &(*trav)->next; 
    }

    *trav = newNode;

    // if(G[parent] == NULL){
    //     G[parent] = newNode;
    //     return;
    // }


    // while(trav->next != NULL){
    //     if(trav->data == indexVal){
    //         printf("dupe found"); 
    //         return; 
    //     }
    //     trav = trav->next;
    // }


    // if(trav->data != indexVal){
    //     trav->next = newNode;
    // }

    }


void delete(Graph G, int target){
    for(int i = 0;i < MAX;i++){
        ptr curr =  G[i]; 
        ptr prev = NULL; 
        while(curr != NULL){
            if(curr->data == target){
                printf("data found, deleting link..\n");
                break;
            }
            prev = curr; 
            curr = curr->next;
        }


    if(curr != NULL){


        if(prev == NULL){
            G[i] = curr->next; 
        }else{
            prev->next = curr->next;
        }

        free(curr);
    }



    }


    ptr freeLink;
    while(G[target] != NULL){
        freeLink = G[target];
        G[target] = G[target]->next;
        free(freeLink);

    }
}
void dfs(Graph G, int parent, int * marker){
    printf("%d ", parent); 
    marker[parent] = VISITED; 
    
    for(ptr trav = G[parent]; trav != NULL ;trav = trav->next){
        if(marker[trav->data] != VISITED){
            dfs(G, trav->data, marker);
        }
    }
}
void bfs(Graph G, int * marker){
    Queue Q;
    initQueue(&Q); 
    enqueue(&Q, 1);

    while(Q.front != -1){
        int i = dequeue(&Q);
        marker[i] = VISITED;
        ptr trav = G[i];
        printf("%d ", i);
        while(trav != NULL){
            if(marker[trav->data] != VISITED){
                enqueue(&Q, trav->data);
            }

            trav = trav->next;
        }
    }
}
void enqueue(Queue * Q, int index){
    if((Q->rear + 2) % MAX == Q->front){
        printf("hello");
        return; 
    }

    if(Q->front == -1){
        Q->front = 0; 
    } else Q->rear = (Q->rear + 1) % MAX; 

    Q->qArr[Q->rear] = index; 
}
int dequeue(Queue * Q){
    if(Q->front == -1){
        printf("nothing to delete\n");
        return -1; 
    }


    int val = Q->qArr[Q->front];
    if(Q->front == Q->rear){
        Q->front = -1;
        Q->rear = 0; //
    } else Q->front = (Q->front + 1) % MAX; 
    return val; 


}

