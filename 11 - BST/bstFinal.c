#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX 10

typedef struct node{
    struct node * lc; 
    struct node * rc; 
    char * name; 
}node, *BST; 


typedef struct{
    BST stackArr[MAX]; 
    int top; 
}Stack; 

void insert(BST * tree, char * newName); 
void delete(BST * tree, char * target);
void preorder(BST tree); 
void inorder(BST tree); 
void postorder(BST tree); 



//iterative
void iterativePreorder(BST tree); 
void push(Stack * S, BST pushNode); 
BST pop(Stack * S); 
void initStack(Stack * S); 




int main(){
    BST tree = NULL; 
    insert(&tree, "Matias");
    insert(&tree, "Cedrick");
    insert(&tree, "Andrei");
    iterativePreorder(tree);   
    printf("\n\n");

    delete(&tree, "Matias");
        iterativePreorder(tree); 


}



void insert(BST * tree, char * newName){
    BST * trav = tree; 
    while(*trav != NULL){
        if(strcmp(newName, (*trav)->name) == 0){
            printf("Name %s already Exist!\n", newName); 
            return; 
        }

        trav = strcmp((*trav)->name, newName) > 0 ? &(*trav)->lc : &(*trav)->rc; 
    }


    if(*trav == NULL){

        *trav = (BST)calloc(1, sizeof(node)); 
        (*trav)->name = malloc(10* sizeof(char)); 
        strcpy((*trav)->name, newName); 
    }
}



void delete(BST * tree, char * target){
    BST * trav = tree; 
    while(*trav != NULL){
        if(strcmp((*trav)->name, target) == 0){
            printf("Found target %s\n", target); 
            break; 
        }


        trav = strcmp((*trav)->name, target) > 0 ? &(*trav)->lc : &(*trav)->rc; 
    }


    if(*trav != NULL){

        if((*trav)->lc == NULL){

            BST temp = (*trav)->rc; 
            free(*trav); 
            *trav = temp; 
        }else if((*trav)->rc == NULL){
            BST temp = (*trav)->lc; 
            free(*trav); 
            *trav = temp; 
        }else{
            printf("hello");
            BST parent = *trav; 
            BST child = parent->rc; 

            while(child->lc != NULL){
                parent = child; 
                child = child->lc; 
            }



            strcpy((*trav)->name, child->name);

            if(parent->rc == child){
                parent->rc = child->rc; 
            }else{
                parent->lc = child->rc; 
            }

            free(child); 
        
        }
    }




}



void preorder(BST tree){
    if(tree != NULL){
    printf("%s ", tree->name); 
    preorder(tree->lc); 
    preorder(tree->rc); 
    }
}



void inorder(BST tree){
    if(tree != NULL){
    inorder(tree->lc); 
    printf("%s ", tree->name); 
    inorder(tree->rc); 
    }
}



void postorder(BST tree){
    if(tree != NULL){
        postorder(tree->lc); 
        postorder(tree->rc); 
        printf("%s ", tree->name); 
    }
}






void iterativePreorder(BST tree){
    Stack * S = malloc(sizeof(Stack)); 
    initStack(S); 
    push(S, tree); 
    while(S->top != -1){
        BST newNode = pop(S); 
        if(newNode->rc != NULL) push(S, newNode->rc); 
        if(newNode->lc != NULL) push(S, newNode->lc); 
        printf("%s ", newNode->name); 
    }
} 
void push(Stack * S, BST pushNode){
    S->stackArr[++S->top] = pushNode;
}
BST pop(Stack * S){
    return S->stackArr[S->top--]; 
} 
void initStack(Stack * S){
    S->top = -1; 
}