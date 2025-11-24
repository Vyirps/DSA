#include<stdio.h>
#include<stdlib.h>


typedef struct Node{
    struct Node * lc;
    struct Node * rc;
    int data;
}Node,  *BST;

void insert(BST * tree, int val);
void delete(BST * tree, int val);
void inorder(BST trav); 
void preorder(BST trav);
void postorder(BST trav);


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
    while(*trav != NULL){
        
        if((*trav)->data == val){
            printf("%d already exists!\n", val);
            return; 
        }

            trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc;

    }    
        if(*trav == NULL){
            *trav = (BST)calloc(1, sizeof(Node));
            (*trav)->data = val;
        }

    printf("Value %d is inserted to tree!\n", val);
}

void delete(BST * tree, int val){
    BST * trav = tree;

    while(*trav != NULL){
        printf("Iterating..\n");
        if((*trav)->data == val){
            printf("\nVal %d was found!\n", (*trav)->data);
            break;
        }
        trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc;
    }

    if(*trav == NULL){
        printf("\nTree is empty/Node was not found!\n");
        return; 
    }

    if((*trav)->data == val){

        if((*trav)->lc == NULL && (*trav)->rc == NULL){
            printf("Freeing node with no children...\n");
            free(*trav); 
        }else if((*trav)->lc != NULL && (*trav)->rc == NULL){
            printf("Freeing node with left child only...\n");
            BST temp = (*trav)->lc;
            free(*trav);
            *trav = temp; 
        }else if((*trav)->lc == NULL && (*trav)->rc != NULL){
            printf("Freeing node with right child only...\n");
            BST temp = (*trav)->rc; 
            free(*trav); 
            *trav = temp; 
        }else{
            printf("Freeing node with 2 children...");
            BST smallest = (*trav)->rc;
            while(smallest->lc != NULL){
                smallest = smallest->lc;
            }
            (*trav)->data = smallest->data; 
            printf("Fixing tree by deleting copied data %d...n", smallest->data);
            delete(&(*trav)->rc, smallest->data);
        }

        printf("\nDeletion of %d was successful!", val); 

    }


}

void inorder(BST trav){

    if(trav != NULL){
    inorder(trav->lc);
    printf("%d ", trav->data);
    inorder(trav->rc);        
    }

}

void preorder(BST trav){
    if(trav != NULL){
    printf("%d ", trav->data);
    preorder(trav->lc);
    preorder(trav->rc);        
    }

}

void postorder(BST trav){
    if(trav != NULL){
    postorder(trav->lc);
    postorder(trav->rc);
    printf("%d ", trav->data);        
    }

}