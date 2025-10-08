/*
hashmap creation
1. open dictionary - array of linked list 
visualization
under the struct of dicts,  
index 0 -> node 1 -> node 2
index 1 -> NULL
index 2 -> NULL
index 3 -> node 1
index 4 -> NULL

1. initialize dict with array size of max
2. set all pointers within the array to null
3. when inserting, calculate the key
 first (ASCII value for string, number 
 addition for nums in an array);
3.1 when calculating for a string, use while to calculate
where 
unsigned long key(const char * str){
    unsigned long hash = 5381 // long for a higher key value, 5381 is magic number to avoid collision
    int c; //store value temporarily

    while((c = (unsigned char)*str++)){ //assign, then increment then check if fits condition
    hash = (hash * 33) + c //<< 5 for safety measure and lesser collision
    }

    return hash;

}
4. find index through key % ARRAY_SIZE
5. insert it on index, if not null insert as first 

*/


/*
string key prac 
unsigned long key(char * str){
    unsigned long index = 5381;
    int c;

    while(c = (unsigned char)*str){
    index = (hash * 33) + c //or u can use ((hash << 5) * hash) + c
    }
    return hash;


}

number key prac
int key(int rgb[]){
    for(int i = 0; i < arraykeysize;i++){
        hash += rgb[i];
    }

    key = key % ARRAY_SIZE;
    return key;

}


stack
1.  First In Last Out (FILO)
2. initialize, put all above each other
3. if linked list, add to end


queue
First In First Out
- 2 types of queue, circular for array and standard queue for linked list 
1A Circular Array (no sacrifice space)
#DEFINE MAX 10
typedef struct{
    int array[MAX]
    int count;
}Array

typedef struct{
    Array arr;
    int front;
    int rear;
}Queue


1. count = keep track of current amount, front and rear for navigation 
2. traversal formula is (f/r = front/rear + 1) % MAX
3. set both f/r to 0 if empty 
4. formula allows it to travel in a roundabout way

1B Circular Array Sacrifical Space


typedef struct{
    int arr[MAX];
    int front;  
    int rear;
}Queue

1. no count, sacrificial to check for space 
2. traversal formula still the same
3. when empty, set your front to be rear + 1
4. full, rear + 2 && empty rear + 1 


Cursor Balls adt
typedef struct{
    int elem; //contains data
    int next; //contains address of next
}Cell, Heapspace;

typedef struct{
    Heapspace H; //contains all cells free or not
    int avail; //point to empty 
}VHeap

typedef int List;

*/