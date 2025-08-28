#include<stdio.h>
#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

int main(){
    
}

List initialize(List L)
{
    L.count = 0;
    return L;
}

List insertAtPosition(List L, int data, int position)
{
    if(position == L.count || position < 0 || L.count == MAX)
    {
        return L;
    }

    for(int i = L.count; i > position; i--)
    {
        L.elem[i] = L.elem[i-1];
    }
    L.elem[position] = data;
    L.count++;
    
    return L;
}

