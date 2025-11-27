#include <stdio.h>
#include <stdlib.h>

#define VISITED -1
#define UNVISITED 100
#define MAX 10

typedef int vertex

    typedef struct node
{
    int elem;
    struct node *link;
} *ptr, node;

typedef ptr Graph[MAX];

int main()
{
}

void dfs(Graph G, vertex v, int *marker)
{
    node *vertices = G[v];
    printf("%d ", vertices->elem);

    marker[v] = VISITED;

    for (int trav = G[v]; trav != NULL; trav = trav->link)
    {
        if (mark[trav->elem] == UNVISITED)
        {
            dfs(G, vertices->elem, marker);
        }
    }
}







insert(Graph G, vertex v, int val)
{
    ptr node = (ptr)calloc(1, sizeof(node));
    node->elem = val;

    if (G[v] == NULL)
    {
        G[v] = node;
    }
    else
    {
        ptr trav = G[v];
        while (trav->next != NULL)
        {
            trav = trav->link;
        }
    }
}

/*
1. visit the start vertex
2. for each adjacent
3. if w has not been visited then apply dfs to w

*/


void dfs(Graph G, vertex v, int * marker){
    marker[v] = VISITED; 
    printf("%d ", G[v]->elem);

    for(ptr trav = G[v]; trav != NULL; trav = trav->link){
        if(marker[trav->elem] == UNVISITED){
            dfs(G, trav->data, marker);
        }
    } 
}


void insert(Graph g, vertex v, int val){
    ptr newNode = (ptr)calloc(sizeof(node));
    newNode->elem = val; 

    if(G[v] == NULL){
        G[v] = newNode; 
    }else{
        ptr trav = G[v];
        while(trav->link != NULL ){
            trav = trav->link;
        }

        trav->next = newNode;
    }
}