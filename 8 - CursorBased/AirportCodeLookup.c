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
        

            if(finder(V, code, trav)){
                strcpy(V->H[key].elem, "");
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