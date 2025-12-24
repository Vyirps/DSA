#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

typedef struct{
    int items[MAX];
    int top;
}Stack; 


Stack * initialize();
bool isFull(Stack * s);
bool isEmpty(Stack * s);
void push(Stack * s, int value);
int pop(Stack * s);
int peek(Stack * s);
void display(Stack * s);


int main(){
    Stack * s = initialize();
    push(s, 1);
    printf("\n%d data\n", s->items[s->top]);
    push(s, 2);
        printf("\n%d data\n", s->items[s->top]);
    push(s, 3);

    push(s, 4);
    display(s);
    printf("Popped num %d", pop(s)); 

    display(s);
}

Stack * initialize(){
    Stack * s = (Stack*)malloc(sizeof(Stack)); 
    s->top = MAX; 
    return s;
}


bool isFull(Stack * s){
    return s->top == -1;
}



bool isEmpty(Stack * s){
    return s->top == MAX;
}


void push(Stack * s, int value){
        if(isFull(s)) return; 
        s->items[--s->top] = value;
    }



int pop(Stack * s){
    return (!isEmpty(s)) ? s->items[s->top++] : -1;
}
int peek(Stack * s){

    return (!isEmpty(s)) ? s->items[s->top] : -1; 

}
void display(Stack * s){
    if(!isEmpty(s)){
        printf("\nStack\n");
        for(int i = MAX -1 ;i >= s->top ;i--){
            printf("Index %d: %d\n",i,  s->items[i]);
        }
    }else{
        printf("\nList is Empty!\n");
    }
}