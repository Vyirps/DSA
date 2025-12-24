#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
    int count;
} List;

List *initialize();
void empty(List *L);
void insertFirst(List *L, int data);
void insertLast(List *L, int data);
void insertPos(List *L, int data, int index);
void deleteStart(List * L);
void deleteLast(List *L);
void deletePos(List *L, int index);
int retrieve(List *L, int index);
int locate(List *L, int data);
void display(List *L);

int main()
{
    List *L = initialize();
    insertFirst(L, 1); 
    insertFirst(L, 2);
    insertFirst(L, 3);
    display(L);
    insertLast(L, 4);
    insertLast(L, 5);
    insertLast(L, 6);
    display(L);
    insertPos(L, 7, 0);
    display(L);
    insertPos(L, 8, 7);
    insertPos(L, 9, 8);
    display(L);
    deleteStart(L);
    display(L);
    deleteLast(L);
    display(L);
    deletePos(L, 0);
    display(L);
    deletePos(L, 5);
    display(L);
    deletePos(L, 4);
    display(L);
    int num = retrieve(L, 1);
    printf("\nNumber at index 1 is %d\n",  num);
    num = retrieve(L, 20);
    if(num == - 1){
        printf("\nNOT REAL\n");
    }

    int ind = locate(L, 4);
    printf("Number 4 is at index %d", ind);
    ind = locate(L, 20);
    if(ind == -1){
        printf("\nNOT REAL\n");
    }
    


}

List *initialize()
{
    List *L = (List *)malloc(sizeof(List));
    if (L == NULL)
    {
        printf("\nALLOCATION UNSUCCESSFUL RETRY AGAIN\n");
    }
    L->head = NULL;
    L->count = 0;
    return L;
}

void empty(List *L)
{
    Node * temp = L->head;
    Node * temp2;
    while(temp != NULL){
        temp2 = temp;
        temp = temp->next;
        free(temp2);
    }

    printf("\nAll nodes have been freed\n");

}

void insertFirst(List *L, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = L->head;
    L->head = newNode;
    L->count++;
}

void insertLast(List *L, int data)
{
    if (L->head == NULL)
    {
        insertFirst(L, data);
    }
    else
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        Node *temp = L->head;
        for (int i = 0; i < L->count - 1; i++)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = NULL;
        L->count++;
    }
}

void insertPos(List *L, int data, int index)
{
    if (index <= L->count)
    {
        if (index == 0)
        {
            insertFirst(L, data);
        }
        else if (index == L->count)
        {
            insertLast(L, data);
        }
        else
        {
            Node * newNode = (Node*)malloc(sizeof(Node));
            newNode->data = data;
            Node * temp = L->head;
            for(int i = 0; i < index -1;i++){
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
            L->count++;
        }
    }
    else
    {
        printf("\nINVALID POSITION\n");
    }
}

void deleteStart(List * L){
    if(L->head == NULL){
        printf("\nNothing to delete from the list\n");
    }else{
        Node * temp = L->head;
        L->head = temp->next;
        free(temp);
        printf("\nSuccessfully deleted starting node\n");
        L->count--;
    }
}

void deleteLast(List *L)
{
    if(L->head == NULL){
        printf("\nNothing to delete from the list\n");
    }else{
        Node * temp = L->head;
        Node * temp2;
        int i = 0;
        while(i < L->count - 1 && temp->next != NULL){
            i++;
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = NULL;
        free(temp2);
        printf("\nSuccessfully deleted last node\n");
        L->count--;
    }


}

void deletePos(List *L, int index)
{
    if(index < L->count){
        if(index == 0){
            deleteStart(L);
        }else if(index == L->count - 1){
            deleteLast(L);
        }else{
            Node * temp = L->head;
            Node * temp2;
            int i = 0;
            while(i < index - 1){
                temp = temp->next;
                i++;
            }
            temp2 = temp->next;
            temp->next = temp2->next;
            free(temp2);
            printf("\nNode at position %d has been freed\n", index);
        }
    }else{
        printf("\nInvalid Index\n");
    }

}



int retrieve(List *L, int index)
{
    if(index < L->count){
        Node * temp = L->head;
        int i = 0;
        while(i != index){
            temp = temp->next;
            i++;
        }
        return temp->data;
    }else{
        printf("\nInvalid Position\n");
        return -1;
    }

}

int locate(List *L, int data)
{
    if(L->head == NULL){
        printf("\nLIST IS EMPTY\n");
    }else{
        Node * temp = L->head;
        int i = 0;
            while(i < L->count && temp->next != NULL){
                if(temp->data == data){
                    printf("Position found, returning index %d", i);
                    return i;
                }else{
                    i++;
                    temp = temp->next;
                }
            }
        printf("\nData %d was NOT found within the list\n", data);
        return -1;
    }
        return -1;

}

void display(List *L)
{
    if(L->head == NULL){
        printf("\nList is Empty\n");
    }else{
        printf("\nLINK LIST: ");
        Node * temp = L->head; 
        for(int i = 0;i <= L->count - 1;i++){
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf(" Count: %d\n", L->count);
    }

}