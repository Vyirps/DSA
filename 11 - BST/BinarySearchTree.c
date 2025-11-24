#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *lc;
    struct node *rc;
    int data;
} Node, *BST;

void insert(BST *tree, int val);
void delete(BST *tree, int val);
void inorder(BST tree);
void preorder(BST tree);
void postorder(BST tree);

int main()
{
    BST tree = NULL;
    // /	3,5,9,1,8,4,2,6,7
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

void insert(BST *tree, int val)
{
    BST *trav = tree;

    while (*trav != NULL)
    {
        trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc;
    }

    if (*trav == NULL)
    {
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->data = val;
    }
}
void delete(BST *tree, int val)
{
    BST *trav = tree;
    printf("helloz");
    while (*trav != NULL && (*trav)->data != val)
    {
        trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc;
    }

    if (*trav == NULL)
    {
        printf("hellonn");
        return;
    }

    if ((*trav)->data == val)
    {
        printf("hello");
        if ((*trav)->lc == NULL && (*trav)->rc == NULL)
        {
            printf("hello1");
            free(*trav);
            *trav = NULL;
        }
        else if ((*trav)->lc == NULL && (*trav)->rc != NULL)
        {
            printf("hello2");
            BST temp = (*trav)->rc;

            free(*trav);
            *trav = temp;
        }
        else if ((*trav)->lc != NULL && (*trav)->rc == NULL)
        {
            printf("hello3");
            BST temp = (*trav)->lc;

            free(*trav);
            *trav = temp;
        }
        else
        {
            printf("hello4");
            BST find = (*trav)->rc;
            while (find->lc != NULL)
            {
                find = find->lc;
            }
            (*trav)->data = find->data;
            delete(&(*trav)->rc, find->data);
        }
    }
}
void inorder(BST tree)
{
    if (tree != NULL)
    {
        inorder(tree->lc);
        printf("%d ", tree->data);
        inorder(tree->rc);
    }
}
void preorder(BST tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        inorder(tree->lc);
        inorder(tree->rc);
    }
}
void postorder(BST tree)
{
    if (tree != NULL)
    {
        inorder(tree->lc);
        inorder(tree->rc);
        printf("%d ", tree->data);
    }
}