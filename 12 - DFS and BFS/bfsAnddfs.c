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

//initializations
void initGraph(Graph G); 
void initQueue(Queue * q); 
void initMatrix(int matrix[][MAX]); 

//basic operations
void insertList(Graph G, int parent, int indexVal);
void deleteList(Graph G, int indexVal);
void insertMatrix(int matrix[][MAX], int parent, int indexVal); 
void deleteMatrix(int matrix[][MAX], int parent, int indexVal);
void matrixToList(int matrix[][MAX], Graph G); 

//printing algorithms
void dfs(Graph G, int val, int * marker); 
void bfs(Graph G, int start);

//bfs operations (queue system)
void enqueue(Queue * q, int val);
int dequeue(Queue * q);  

//printing
void printGraph(Graph G); 
void printMatrix(int matrix[][MAX]); 




int main(){
    Graph G; 
    int marker[MAX]; 
    int matrix[MAX][MAX]; 

    initGraph(G); 
    initMatrix(matrix); 
    insertMatrix(matrix, 1, 2); 
    insertMatrix(matrix, 1, 3); 
    insertMatrix(matrix, 1, 5);
    insertMatrix(matrix, 2, 1);
    insertMatrix(matrix, 2, 4);
    insertMatrix(matrix, 3, 7);
    insertMatrix(matrix, 4, 5);
    insertMatrix(matrix, 4, 6);
    insertMatrix(matrix, 4, 9);
    insertMatrix(matrix, 6, 3);
    insertMatrix(matrix, 7, 8);
    insertMatrix(matrix, 8, 2);
    insertMatrix(matrix, 8, 9);
    printMatrix(matrix); 
    matrixToList(matrix, G);
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

void initMatrix(int matrix[][MAX]){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            matrix[i][j] = 0; 
        }
    }
}




void insertList(Graph G, int parent, int indexVal){
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
void deleteList(Graph G, int indexVal){
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


void insertMatrix(int matrix[][MAX], int parent, int indexVal){
    matrix[parent][indexVal] = 1; 
}
void deleteMatrix(int matrix[][MAX], int parent, int indexVal){
    matrix[parent][indexVal] = 0; 
}
void matrixToList(int matrix[][MAX], Graph G){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(matrix[i][j] == 1){
                insertList(G, i, j); 
            }
        }
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

void printMatrix(int matrix[][MAX]){
    printf("MATRIX\n"); 
    printf("  0 1 2 3 4 5 6 7 8 9\n"); 
    for(int i = 0; i < MAX; i++){
        printf("%d ", i); 
        for(int j = 0; j < MAX; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n"); 
    }
}






