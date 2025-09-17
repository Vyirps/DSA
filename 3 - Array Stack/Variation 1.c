#include<stdio.h>
#include<stdlib.h>

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
    printf("\n%d data\n", s->items[0]);
    push(s, 2);
        printf("\n%d data\n", s->items[1]);
    push(s, 3);

    push(s, 4);
    display(s);
    int num = pop(s);
    num = pop(s);
    display(s);
}

Stack * initialize(){
    Stack * s = (Stack*)malloc(sizeof(Stack)); 
    s->top = -1; 
    return s;
}


bool isFull(Stack * s){
    return s->top == MAX - 1;
}



bool isEmpty(Stack * s){
    return s->top == -1;
}


void push(Stack * s, int value){
        if(!isFull(s)){
            s->top++;
            s->items[s->top] =  value;
        }
    }



int pop(Stack * s){
    if(!isEmpty(s)){
        int num = s->items[s->top];
        s->top--;
        return num;
    }else{
        printf("\nCurrent Stack is empty\n");
    }


}
int peek(Stack * s){
    if(!isEmpty(s)){
        return s->items[s->top];
    }else{
        return -1;
    }


}
void display(Stack * s){
    if(!isEmpty(s)){
        printf("\nList\n");
        for(int i = s->top;i >= 0 ;i--){
            printf("Value: %d\n", s->items[i]);
        }
    }else{
        printf("\nList is Empty!\n");
    }
}