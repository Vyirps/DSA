#include<stdio.h>
#include<stdlib.h>

#define MAX 20


typedef struct node{
    struct node * lc;
    struct node * rc;
    int data;
}*BST, node; 


typedef struct{
    node * stack[MAX]; 
    int top;   
}Stack; 

void insert(BST * tree, int val);
void delete(BST * tree, int val);
void preorder(BST tree);
void postorder(BST tree);
void inorder(BST tree);
int maxHeight(BST tree); 
int minHeight(BST tree); 
int depth(BST tree, int target);

void push(Stack * s, BST node); 
BST pop(Stack * s); 
void initStack(Stack * s);
void iterativePreorder(BST tree);


int main(){
    BST tree = NULL; 
    insert(&tree, 3);
    insert(&tree, 5);
    insert(&tree, 9);
    insert(&tree, 1);
    insert(&tree, 8);
    insert(&tree, 4);
    insert(&tree, 2);
    insert(&tree, 6);
    insert(&tree, 7);

    printf("Inorder: ");
    inorder(tree);
    delete(&tree, 3);
    printf("\nPreorder: ");
    preorder(tree);
    printf("\nIterative preorder: ");
    iterativePreorder(tree);

    printf("\nPostorder: ");
    postorder(tree);
    printf("\n");

    printf("The maximum height is %d\n", maxHeight(tree));
    printf("The minimum height is %d\n", minHeight(tree));
    printf("The depth of node %d is %d", 9, depth(tree, 9));
    return 0;

}

void push(Stack * s, BST newNode){
    s->stack[++s->top] = newNode; 
}
BST pop(Stack * s){
    return s->stack[s->top--]; 
}

void initStack(Stack * s){
    for(int i = 0; i < MAX; i++){
        s->stack[i] = 0; 
    }

    s->top = -1; 
}

void iterativePreorder(BST tree){
    Stack * s = malloc(sizeof(Stack));
    initStack(s); 
    push(s, tree); 
    BST curr = NULL; 

    while(s->top != -1){
        curr = pop(s); 
        if(curr->rc != NULL ) push(s, curr->rc); 
        if(curr->lc != NULL) push(s, curr->lc); 

        printf("%d ", curr->data); 
    }
}

void insert(BST * tree, int val){
    BST * trav = tree; 
    while(*trav != NULL && (*trav)->data != val){
        trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc;
    }

    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(node)); 
        (*trav)->data = val; 
    }
}


void delete(BST * tree, int val ){
    BST * trav = tree; 
    while(*trav != NULL && (*trav)->data != val){
        trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc; 
    }

    if(*trav != NULL){

        BST del = *trav;
        if(del->lc == NULL){
            *trav = del->rc; 
            free(del); 
        }else if(del->rc == NULL){
            *trav = del->lc; 
            free(del); 
        }else{

            BST temp = del->rc;
            if(temp->lc != NULL){
                temp = temp->lc; 
            }

            (*trav)->data = temp->data; 
            delete(&(*trav)->rc, temp->data);
        }
    }



}
void preorder(BST tree){
    if(tree != NULL){
        printf("%d ", tree->data); 
        preorder(tree->lc); 
        preorder(tree->rc); 
    }
}
void postorder(BST tree){
    if(tree != NULL){
        postorder(tree->lc); 
        postorder(tree->rc); 
        printf("%d ", tree->data);         

    }
}
void inorder(BST tree){
    if(tree != NULL){
        inorder(tree->lc);
        printf("%d ", tree->data); 
        inorder(tree->rc);
    }
}


int maxHeight(BST tree){
    if(tree == NULL ) return 0; 
    if(tree->lc == NULL && tree->rc == NULL) return 0; 

    int left = maxHeight(tree->lc);
    int right = maxHeight(tree->rc); 

    return left > right ? left + 1 : right + 1; 
}

int minHeight(BST tree){
    if(tree == NULL ) return 0; 
    if(tree->lc == NULL && tree->rc == NULL) return 0; 

    int left = minHeight(tree->lc);
    int right = minHeight(tree->rc); 

    return left < right ? left + 1 : right + 1; 
}

int depth(BST trav, int target){
    if(trav->data == target ) return 0; 
    trav = trav->data > target ? trav->lc : trav->rc; 
    return depth(trav, target) + 1; 
}


