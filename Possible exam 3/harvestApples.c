#include<stdio.h> 
#include<stdlib.h>
#include<string.h>

#define MAX 20



typedef struct{
    int size; 
    char status[10]; 
}Apple; 

typedef struct node{
    Apple apple; 
    struct node * left;
    struct node * right; 
}*Tree, node; 

typedef struct{
    int top; 
    Tree stack[MAX]; 
}Stack; 

typedef struct{
    int top; 
    Apple stack[MAX]; 
}Basket; 


void growApple(Tree * appleTree, Apple newApple); 
Basket * harvestApple(Tree * appleTree);
void preorder(Tree appleTree); 
void push(Stack * s, node * newNode); 
void pushBasket(Basket * s, Apple newApple); 
Tree pop(Stack * s);
void initStack(Stack * s); 
void initBasket(Basket * s); 







int main(){
    Tree appleTree = NULL; 
    Apple appleArray[MAX] = {
        {5, "RIPE"},
        {3, "UNRIPE"},
        {8, "RIPE"},
        {2, "ROTTEN"},
        {4, "RIPE"},
        {7, "UNRIPE"},
        {9, "RIPE"},
        {1, "ROTTEN"},
        {6, "RIPE"}
    };
    for(int i = 0; i < 9; i++){
        growApple(&appleTree, appleArray[i]); 
    }
    printf("Current tree\n");
    preorder(appleTree);
    Basket * basket ;
    basket =  harvestApple(&appleTree);
    printf("\n\nBasket Contents\n");
    for(int i = 0; i <= basket->top; i++){
        printf("%d %s | ", basket->stack[i].size , basket->stack[i].status); 
    }
    printf("\n\nUpdated Tree\n"); 
        preorder(appleTree);

}


void growApple(Tree * appleTree, Apple newApple){
    Tree * trav = appleTree; 
    while(*trav != NULL){
        trav = (*trav)->apple.size > newApple.size ? &(*trav)->left : &(*trav)->right;
    }

    if(*trav == NULL){
        *trav = (Tree)calloc(1, sizeof(node));
        (*trav)->apple = newApple; 
    }
}
Basket * harvestApple(Tree * appleTree){
    Stack * s = malloc(sizeof(Stack)); 
    Basket * basket = malloc(sizeof(Basket)); 
    initStack(s);
    initBasket(basket); 
    
    push(s, *appleTree); 
    Tree trav;
    while(s->top != -1){
        trav = pop(s);
        if(strcmp(trav->apple.status, "RIPE") == 0) pushBasket(basket, trav->apple); 
        if(trav->right != NULL) push(s, trav->right); 
        if(trav->left != NULL) push(s, trav->left); 
    }

    for(int i = 0; i <= basket->top; i++){
        int target = basket->stack[i].size; 
        Tree * curr = appleTree; 
        while(*curr != NULL){
            if((*curr)->apple.size == target){
                break; 
            }

            curr  = (*curr)->apple.size > target ? &(*curr)->left : &(*curr)->right;
        }

        if(curr != NULL){

            Tree del = *curr; 

            if((*curr)->left == NULL){
                *curr  = del->right; 
                free(del); 
            }else if((*curr)->right == NULL){
                *curr = del->left;
                free(del);  
            }else{
                Tree parent = del; 
                Tree child = del->right;
                while(child->left != NULL){
                    parent = child; 
                    child = child->left;

                }
                

                del->apple = child->apple; 

                if(parent->right == child){
                    parent->right = child->right; 
                }else{
                    parent->left = child->right; 
                }

                free(child); 
            }
        }






    }



    return basket; 

}
void preorder(Tree appleTree){
    if(appleTree != NULL){
        printf("%d \"%s\" | ", appleTree->apple.size, appleTree->apple.status);
        preorder(appleTree->left); 
        preorder(appleTree->right);  
    }
}


void push(Stack * s, node * newNode){
    s->stack[++s->top] = newNode; 
}


void pushBasket(Basket * s, Apple newApple){
    s->stack[++s->top] = newApple; 
}

Tree pop(Stack * s){
    return s->stack[s->top--]; 
}



void initStack(Stack * s){
    for(int i = 0;i < MAX;i++){
        s->stack[i] = NULL; 
    }

    s->top = -1; 
}

void initBasket(Basket * s){
    s->top = -1; 
}