#include<stdio.h>
#include<stdlib.h>



typedef struct node{
    struct node * lc; 
    struct node * rc;  
    int val; 
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

void insert(BST * tree, int newVal){
    BST * trav = tree; 
    while(*trav != NULL){
        if((*trav)->val == newVal){
            printf("\nDupe was found! force exiting insert... \n");
            return; 
        }
        trav = (*trav)->val > newVal ? &(*trav)->lc : &(*trav)->rc; 
    }

    *trav = (BST)calloc(1, sizeof(node));
    (*trav)->val = newVal; 

    printf("Data %d has successfully been added\n", (*trav)->val); 
    
}
void delete(BST * tree, int delVal){
    BST * trav = tree; 

    while(*trav != NULL){
        if((*trav)->val ==  delVal){
            printf("\nData %d was found! Stopping traversal...\n", (*trav)->val);
            break;
        }

        trav = (*trav)->val > delVal ? &(*trav)->lc : &(*trav)->rc;
    }

    if((*trav)->val == delVal){
        if((*trav)->lc == NULL && (*trav)->rc ==  NULL){
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
            printf("hellow");
            BST temp = (*trav)->rc;
            while(temp->lc != NULL){
                temp = temp->lc; 
            }

            (*trav)->val = temp->val; 
            delete(&(*trav)->rc, temp->val);
        }
    }


}
void preorder(BST tree){
    if(tree != NULL){
    printf("%d ", tree->val); 
    preorder(tree->lc); 
    preorder(tree->rc); 
    }

}
void postorder(BST tree){
    if(tree != NULL){
    postorder(tree->lc);
    postorder(tree->rc); 
    printf("%d ", tree->val);
    }

} 
void inorder(BST tree){
    if(tree != NULL){
    inorder(tree->lc);
    printf("%d ", tree->val); 
    inorder(tree->rc); 

    }

}