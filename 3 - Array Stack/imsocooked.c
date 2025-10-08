#include <stdbool.h>
#include<stdio.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int top;
} Stack;

void initialize(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int top(Stack *s);
void display(Stack* s);

int main() {
    Stack s0,s1,s2;
    Stack * s[3] = {&s0,&s1,&s2};
    initialize(s[0]);
    initialize(s[1]);
    initialize(s[2]);


    int choice = 0;
    while(choice != 5){
    printf("--- Warehouse Inventory Management System ---");
    printf("\n1. Push a container");
    printf("\n2. Pop a container");
    printf("\n3. Check if a container exists");
    printf("\n4. Display all stacks");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d",  &choice);

    switch(choice){
        case 1:{
            int i = 0;
        bool found = false;
        while(i < 3 && found != true){
            if(isFull(s[i]) == false){
                found = true;
                break;
            }else{
                i++;
            }
        }

        if(i < 3 && found == true){
            int value;
            printf("Enter container ID to push: ");
            scanf("%d", &value);
            push(s[i], value);
        }else{
            printf("ALL CONTAINERS ARE FULL\n");
        }

        break;
        }
        

        case 2:{
            int i = 0;
        bool found = false;
        while(i < 3 && found != true){
            if(isEmpty(s[i]) == false){
                found = true;
                break;
            }else{
                i++;
            }
        }

        if(i < 3 && found == true){
            int value = pop(s[i]);
            printf("Container %d popped successfully.\n\n", value);
        }else{
            printf("Error: All stacks are empty. Cannot pop container.\n\n");
        }

        break; 
        }
        

        case 3:{
            bool found = false;
        Stack c0 = s0;
        Stack c1 = s1;
        Stack c2 = s2;
        Stack * c[3] = {&c0, &c1, &c2};


        int check;
        printf("Enter container ID to check: ");
        scanf("%d", &check);

        for(int i = 0;i < 3;i++){
            for(int j = top(c[i]);j > -1 ;j--){
                int value = pop(c[i]);
                if(check == value){
                    printf("Container %d exists in a stack.\n\n", value);
                    found = true;
                    break;
                }else{
                    continue;
                }
            }
            if(found == true){
                break;
            }
        }
         if(found == false){
                 printf("Container %d does not exist in any stack.\n\n", check);             
         }

             
        break; 
        }
        

        case 4:{
        for(int i = 0;i < 3;i++){
        printf("\n--- Stack %d ---\n", i + 1);
        display(s[i]);
        }
        printf("\n");


        break;
        }
        



        
        
        case 5:{
            printf("Exiting program.");
            return 0;
            break;
        }


        default:{
            break;
        }

        }
    }
    return 0;
}
void initialize(Stack *s){
    s->top = -1;
}


bool isFull(Stack *s){
    if(s->top == MAX - 1){
        return true; 
    }else{
        return false;
    }
}


bool isEmpty(Stack *s){
    if(s->top == -1){
        return true; 
    }else{
        return false;
    }
}


void push(Stack *s, int value){
            s->top++;
            s->items[s->top] = value;
            printf("Container %d pushed successfully.\n\n", value);

}


int pop(Stack *s){
    if(isEmpty(s) == false){
        int val = s->items[s->top];
        s->top--;
        return val;
    }else{
        return 0;
    }
}


int peek(Stack *s){
        if(isEmpty(s) == false){
        int val = s->items[s->top];
        return val;
    }else{
        return 0;
    }
}



int top(Stack *s){
    return s->top;
}


void display(Stack* s){
    if(isEmpty(s) == false){
        for(int i = s->top;i >= 0;i--){
            printf("%d\n", s->items[i]);
        }
    }else{
        printf("Stack is empty.\n");
    }
}