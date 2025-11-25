#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node * lc;
    struct node * rc;
    int data;
}*BST, node; 

void insert(BST * tree, int val);
void delete(BST * tree, int val);
void preOrder(BST tree);
void postOrder(BST tree);
void inOrder(BST tree);


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
    inOrder(tree);
    printf("\nPreorder: ");
    preOrder(tree);
    printf("\nPostorder: ");
    postOrder(tree);
    printf("\n");


    delete(&tree, 5);
    printf("\n\nInorder: ");
    inOrder(tree);
    printf("\nPreorder: ");
    preOrder(tree);
    printf("\nPostorder: ");
    postOrder(tree);

    return 0;



}


void insert(BST * tree, int val){
    BST * trav = tree; 

    while(*trav != NULL){

        printf("Traversing...\n");
        if((*trav)->data == val){
            printf("Duplicate was found, ending function...\n");
            return; 
        }

        trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc;

    }

    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(node));
        (*trav)->data = val; 
        printf("Value %d was inserted to the tree!..\n", (*trav)->data);
    }


}
void delete(BST * tree, int val){
    BST * trav = tree; 

    while(*trav != NULL){

        printf("Traversing...\n");
        if((*trav)->data == val){
            printf("Val %d was found!, proof is Node contains %d..\n", val, (*trav)->data);
            break;
        }

        trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc;

    }

    if(*trav == NULL){
        printf("Value %d was not found!...\n", val); 
        return; 
    }

    if((*trav)->data == val){
        printf("Value %d was found! Deleting..\n", (*trav)->data);
        if((*trav)->lc == NULL && (*trav)->rc == NULL){
            free(*trav); 
            *trav = NULL;
            printf("Node with no children removed!\n");
        }else if((*trav)->lc != NULL && (*trav)->rc == NULL){
            BST temp = (*trav)->lc; 
            free(*trav);
            *trav = temp; 
            printf("Node with left child only removed and replaced!\n"); 
        }else if((*trav)->lc == NULL && (*trav)->rc != NULL){
            BST temp = (*trav)->rc;
            printf("trav data is %d\n", (*trav)->data);
            printf("temp data is %d\n", temp->data);
            free(*trav); 
            *trav = temp; 
            printf("new trav data is %d\n", (*trav)->data);

            printf("Node with right child only removed and replaced!\n");
        }else{
            BST left = (*trav)->rc;
            while(left->lc != NULL){
                printf("Traversing for replacement...\n");
                left = left->lc;
            }

            (*trav)->data = left->data; 
            delete(&(*trav)->rc, left->data);
        }

        printf("Sucessfully deleted %d!\n", val);

    }
}
void preOrder(BST tree){
    if(tree != NULL){
        printf("%d ", tree->data); 
        preOrder(tree->lc);
        preOrder(tree->rc);
    }
}
void postOrder(BST tree){
    if(tree != NULL){
        postOrder(tree->lc);
        postOrder(tree->rc);
        printf("%d ", tree->data);
    }
}
void inOrder(BST tree){
    if(tree != NULL){
        inOrder(tree->lc);
        printf("%d ", tree->data);
        inOrder(tree->rc);
    }
}

