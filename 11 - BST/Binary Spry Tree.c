#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node * lc;
    struct node * rc;
    int data;
}*BST, node; 

void insert(BST * tree, int val);
void delete(BST * tree, int val);
void preorder(BST tree);
void postorder(BST tree);
void inorder(BST tree);


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
    printf("\nPreorder: ");
    preorder(tree);
    printf("\nPostorder: ");
    postorder(tree);
    printf("\n");


    delete(&tree, 5);
    printf("\n\nInorder: ");
    inorder(tree);
    printf("\nPreorder: ");
    preorder(tree);
    printf("\nPostorder: ");
    postorder(tree);

    return 0;



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
void delete(BST * tree, int val){
    BST * trav = tree; 

    while(*trav != NULL && (*trav)->data != val){
        trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc;
    }


    if((*trav)->data == val){
        if((*trav)->lc == NULL && (*trav)->rc == NULL){
            free(*trav);
            *trav = NULL; 
        }else if((*trav)->lc != NULL && (*trav)->rc == NULL){
            BST temp = (*trav)->lc;
            free(*trav); 
            *trav = temp;
        }else if((*trav)->lc == NULL && (*trav)->rc != NULL){
            BST temp = (*trav)->rc;
            free(*trav); 
            *trav = temp;
        }else{
            BST temp = (*trav)->rc;
            while(temp->lc != NULL){
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

