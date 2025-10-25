#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX 20
#define SECONDARY 10

typedef struct{
    char elem[4];
    int next;
}cell, Heapspace[MAX];

typedef struct{
    Heapspace H;
    int avail;
}VHeap;

void initialize(VHeap * V){
    V->avail = SECONDARY;
    for(int i = 0;i < SECONDARY;i++){
        strcpy(V->H[i].elem, "");
        V->H[i].next = -1;
    }

    for(int i = SECONDARY; i < MAX - 1;i++){
        strcpy(V->H[i].elem, "");
        V->H[i].next = i+1;
    }

    strcpy(V->H[MAX - 1].elem, "");
    V->H[MAX - 1].next = -1;
}


int hash(char * code){
    int hash = ((code[0] - 'A') * 26 * 26  + (code[1] - 'A') * 26 + (code[2] - 'A')) % 10;
    return hash;
}

int allocSpace(VHeap * V){
    int index = V->avail;
    V->avail = V->H[V->avail].next;
    return index;
}

void deallocSpace(VHeap * V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

bool finder(VHeap * V, char * code){
    int key = hash(code);
    int trav = key;
    while(trav != -1){
        if(strcmp(V->H[trav].elem, code) == 0){
            return true;
        }
        trav = V->H[trav].next;
    }
    return false;
}

void insert(VHeap * V){
    if(V->avail != -1){
        char code[4];
        printf("\nEnter Airport Code to Insert: ");
        scanf("%s", code);
        
        if(finder(V, code)){
            printf("\nCANNOT INSERT: Code Already Exists!\n");
            return; 
        }

        int key = hash(code);
        int curr = key; 

        while(V->H[curr].next != -1){
            curr = V->H[curr].next;
        }

        if(strlen(V->H[curr].elem) == 0){
            strcpy(V->H[key].elem, code);
            printf("\nInserted Code %s at Index %d\n", code, curr);
        }else{
            int index = allocSpace(V);
            strcpy(V->H[index].elem, code);
            V->H[index].next = -1;

            V->H[curr].next = index;
            
        printf("\nInserted Code %s at Index %d\n", code, index);
        }

    }else{
        printf("\nCode Storage is Full!\n");
    }
}



void delete(VHeap * V){
    char code[4];
    printf("\nEnter Airport Code to Delete: ");
    scanf("%s", code);

    if(finder(V, code)){
        int key = hash(code);
        int curr = key, prev = -1; 

        while(curr != -1){
            if(strcmp(V->H[curr].elem, code) == 0){
                break;
            }
            prev = curr; 
            curr = V->H[curr].next;
        }

        if(prev ==  - 1){

            if(V->H[curr].next != -1){
                int index = V->H[curr].next; 
                strcpy(V->H[curr].elem, V->H[index].elem);
                V->H[curr].next = V->H[index].next;
                deallocSpace(V, index);
                printf("\nOutcome 1\n"); //deleting on start with a connect on secondary
                return; 
            }

            strcpy(V->H[curr].elem, "");
            printf("\nOutcome 2\n");//deleting start no connection to secondary
        }else{
            V->H[prev].next = V->H[curr].next;
            deallocSpace(V, curr);
            printf("\nOutcome 3\n"); //  deleting within secondary
        }


    }else{
        printf("Code %s is not in the Dictionary!", code);
    }

    return; 

}


void display(VHeap * V){
    printf("--- AIRPLACE CODES ---\n");
    for(int i = 0;i < SECONDARY ;i++){
        int trav = i;
        printf("Index [%d] -> ", i);
        if(strlen(V->H[trav].elem) == 0){
            printf("EMPTY\n");
        }else{
            while(trav != -1){
            printf("%s -> ", V->H[trav].elem);
                trav = V->H[trav].next;
        }

        
         printf(" NULL\n");
   
        }
    }
}

int main(){
    VHeap V;
    initialize(&V);
    bool runProgram = true;
    int choice;

    while(runProgram){
    printf("--- AIRPLANE SYSTEM ---\n1. Insert Code \n2. Delete Code \n3. Display\n4. Exit\nEnter Choice: ");
    scanf("%d", &choice);
        switch(choice){
            case 1:
                insert(&V);
                break;
            
            case 2:
                delete(&V);
                break;

            case 3: 
                display(&V);
                break;

            case 4:
                runProgram = false;
                break;

            default:
                printf("Invalid Choice!\n");
                break;
        
        
        }
    }

}


/*
void insert(VHeap * V){
    if(V->avail != -1){
        char code[4]; 
        
        printf("\nEnter Airport Code to Insert: ");
        scanf("%s", code);
        
        int key = hash(code);
        if(strlen(V->H[key].elem) != 0){
            int trav = key;
            while(V->H[trav].next != -1){
                trav = V->H[trav].next;
            }
            int index = allocSpace(V);

            strcpy(V->H[index].elem, code);
            V->H[index].next = -1;
            V->H[trav].next = index;
            printf("\nInserted Code %s at Index %d\n", code, index);
        }else{
            strcpy(V->H[key].elem, code);
            V->H[key].next = -1;
            printf("\nInserted Code %s at Index %d\n", code, key);

        }
    }else{
        printf("\nFULL\n");
    }
}

void deallocSpace(VHeap * V, int index){
    V->H[index].next = V->avail;
    V->avail = index;
}

bool finder(VHeap * V, char * code, int trav){
    return ((V->H[trav].elem[0] == code[0]) && (V->H[trav].elem[1] == code[1]) && (V->H[trav].elem[2] == code[2]));
}


void delete(VHeap * V){
    char code[4];
    printf("\nEnter Airport Code to Delete: ");
    scanf("%s", code);
    
    int key = hash(code);
    if(key >= 0 && key < SECONDARY){
        int trav = key, checker;
        

            if(finder(V, code, trav) && V->H[trav].next == -1){
                strcpy(V->H[trav].elem, "");
                return;
            }
            else if(finder(V, code, trav)){
                int nextBlock = V->H[trav].next;
                strcpy(V->H[trav].elem, V->H[nextBlock].elem);
                V->H[trav].next = V->H[nextBlock].next;
                deallocSpace(V, nextBlock);
                return;

            }else{
                while(trav != -1){
                  checker = V->H[trav].next;
                  if(finder(V, code, checker)){
                    printf("Code %s was found!\n", code);
                    
                    V->H[trav].next = V->H[checker].next;
                    deallocSpace(V, checker);
                    
                    return;
                  }else{
                    trav = checker;
                  } 
                }
                printf("Code %s was not found\n", code);

            }    
    }else{
        printf("Invalid Code");
    }
    
}


void display(VHeap * V){
    printf("--- AIRPLACE CODES ---\n");
    for(int i = 0;i < SECONDARY ;i++){
        int trav = i;
        printf("Index [%d] -> ", i);
        if(strlen(V->H[trav].elem) == 0){
            printf("EMPTY\n");
        }else{
            while(trav != -1){
            printf("%s -> ", V->H[trav].elem);
                trav = V->H[trav].next;
        }

        
         printf(" NULL\n");
   
        }
    }
}
*/