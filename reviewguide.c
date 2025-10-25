/*
Sets
in a form of {1,2,3,etc}, can be interpreted as Set(List) and BitVector(Bitwise, Bitfield, Bitbool array)
- The basic operation of sets are Union(OR), Intersection(AND), Difference(AND-NOT


1. Set(List)
Uses normal operations, represents everything but 0s and 1s(Only for bitvector)
Can be in a form of linked list, cursor based, etc
Example 1: (Insert first LL implementation)
Set A = {grass, water, ice}
Set B = {fire, ice, grass}
Set C(Union) = {fire, grass, water, ice}
Set C(Intersect) = {grass, ice};
*No difference can be done, only in BitVector since we cannot inverse anything thats not 0 


Operations
When doing the operations, rule of thumb is u create a local variable to assign the index and then integrate it to the existing variable()

BitVector
- The concept of using 1 and 0 to represent true/false, with using the set operations
1. Bitwise
manipulates 0 and 1 on the variable itself
Example
unsigned char bitwise = 00100110

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
2. set all pointers within the array to null (array of pointers)
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
}Cell, Heapspace[MAX];

typedef struct{
    Heapspace H; //contains all cells free or not
    int avail; //point to empty 
}VHeap




1. Initialize VHeap, each next must point to the next index, -1 for last.
2. Avail to 0 (pointing to index zero), L is -1 (Signify list is empty or full)
3. functions we have are insertFirst(or last), delete, allocSpace and deallocSpace
4. INSERTION
- call allocSpace, CHECK first if avail is NOT -1, then store CURRENT and update 
it to the NEXT avail, and return CURRENT
- if insertfirst, assign newNode next with *L(head VALUE) and *L to newNode 
(keep in mind newnode is the index of CURRENT avail)

- if insert last , allocspace then set newNode next as -1 to signify its the last, then  
assign head to a pointered trav and do a while loop where
while(*trav != -1) { //traverse to the last
    trav = &V->H[*trav].next;
    //in simple terms, we are ASSIGNING the trav ADDRESS with the ADDRESS of the NEXT trav, 
    & is USED to for address ASSIGNING(Referencing)
- when done iterating, set *trav to the newnode value(CURRENT avail)

5. DELETION
- initialize *trav(store next memory) and temp(store deletion index)
- assign L to trav, start traversion with
while(*trav != -1 && V->H[*trav].elem != elem) // first condition to keep traversing till last, 
next condition checks the NEXT node elem if it matches
-run conditional to check if *trav is not -1, if yes then end function if no then 
assign *trav (VALUE) to  temp 
-change the link of current trav to the NEXT of the NEXT one(think of link list relinking on pos insert)
 *trav = V->H[*trav].next
 call  dealloc, first point your Index's NEXT to AVAIL(think of it as inserting first from link list),
 then set the NEW avail as the Index(the node "emptied");



HEAP 
-is an array, visualize as a tree
-left child 2n+1, right child 2n+2
-parent calculation: (n -1)/2
-two main functions, upheapify(after every insertion) and downheapify(deletion)
1. upheapify
after inserting a node at the most recent empty index, call upheapify
- assign temp as inserted index for traversal, then start a while loop for swappnign
- while loop will keep being true until it is not zero
- inside compare current child(temp) to its parent where if temp is >/< than (temp-1/2) and if true then swap
- update the temp to go up 

2. downheapify
- after deletion(last inserted is MOVED to root value and decrement count), start deheapify on root
- start with a temp set as root for traversal, and bool to keep while loop running while its true 
- inside while loop will be the following in order
1. check if the next temp will exceed/equals arraysize (2(temp) + 1) OR exceed count 
2. initialize values for swap and comparisons, left as left index, right as right index, and index for the bigger/smaller child
3. check first which of the two childs is bigger/smaller which will be the index 
4. compare if index value is bigger/smaller than temp, then swap if true
5. update your temp with index, going down the tree

4.1 if no swap happens, set swap to false which will stop    the whole porcess since nothing cant be swapped anymore


5. Unsorted Array 
1. Make sure its MAX Heaped already 
2. call heapify with iteration starting from the last


