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

2. Bitfield
same as bitwise, but the 0 and 1s is limited to certain amount
Example
unsigned int field: 4 //meaning theres only four places 0000

3. Bitbool 
0 and 1 represented in the form of array 
Example
arr[] = 128; //would look like [1,0,0,0,0,0,0,0]

/*
DICTIONARY HASH
two types of hash, OPEN and CLOSE
OPEN HASHING
index 0 -> NULL
index 1 -> NULL
index 2 -> node 1 -> NULL
index 3 -> NULL
index 4 -> node 1 -> NULL
index 5 -> node 2 -> node 1

1. initialize your array, make sure each index is null 
2. your functions are insert, delete, and hash(key calculator)
3 hash(key calculator){
there are 2 variants, number and string but follow the general rule of % arraysize //OR FOLLOW SPECIFIED INSTRUC IF THERE IS
3.1 number
- calculate your number, then number % arraysize and return the value easy

3.2 string
- traverses through each letter and calculates the key
- initialize an unsigned var hash(can be int/long ) then assign it with a prime number(magic key is 5381)
- initialize an int c as temp
- have a while loop where c will keep running until its zero (c = (unsigned char)*str) //this will keep running 
bcs c will be non zero until its not
- inside the while loop, each letter value is run through a formula for uniqueness, 
c = (hash * 33) + c OR ((hash << 5)* hash) + c

- at the end, calculate final key where hash % arraysize
}


4. insertion (insert first){
- get your key, insert it at that index, if null then make it head else insert first //or depends on your instruc might be sorted etc
}

5. deletion (match checking through traversal)
- get your key, initialize a curr and prev to traverse, do it like deletePos of LL, if not found then return -1

6. finder
- get your key, initialize a temp to traverse, if found return true if not then -1
SPECIAL CASE: if asking for a struct, return address of struct on true and null at false


CLOSED HASHING
Visualization after initialization
-------------------------------------------------------------------------------------------------                
            data        next                  -               data        next       
index 0       0         -1                    -   index 5       0          6 
index 1       0         -1                    -   index 6       0          7 
index 2       0         -1                    -   index 7       0          8
index 3       0         -1                    -   index 8       0          9
index 4       0         -1                    -   index 9       0         -1
PRIMARY TABLE                                 -   SECONDARY TABLE
                                                Avail = 0 //available node to insert          
--------------------------------------------------------------------------------------------------
- Uses the concept with Primary table(first insertions) and Secondary table(2nd insertions) //take note this is ONE array just split to two
- Works just like a normal cursor based, but the difference is avail is only used when the index in primary is occupied
MAX 10

typedef struct{
    int data;
    int next;
}Node, Heapspace[MAX]

typdef struct{
    Heapspace H;
    int avail; 
}VH

Main functions
1. Insertion
*rule of thumb, always check if avail is not -1 //if it is then dictionary is full
1. check if specific index is empty, if it is then just insert it normally  on primary table 
EXAMPLE, insert(6 as data, index as 2)
-------------------------------------------------------------------------------------------------                
            data        next                  -               data        next       
index 0       0         -1                    -   index 5       0          6 
index 1       0         -1                    -   index 6       0          7 
index 2       6         -1                    -   index 7       0          8
index 3       0         -1                    -   index 8       0          9
index 4       0         -1                    -   index 9       0         -1
PRIMARY TABLE                                 -   SECONDARY TABLE
                                                Avail = 5 //available node to insert          
--------------------------------------------------------------------------------------------------
in a link list visual, it would like 
index 2[data 6, next is -1] -> -1(NULL)
primary table
// we inserted it at primary because we know its EMPTY
// trying another insertion on the same index insert(7 as data,  2 as index), step 1s rule does not apply


2. if its occupied then we assume that insertion will now happen at second table, initiate a traversal where curr = index
while(VH->H[curr].next != -1){
    curr = VH->H[curr].next
} 
After traversing, we can always assume that it will end up as an insert last so
2.1 call allocSpace to ready index for insertion, then set its data and next(always -1)
2.2 connect the next of curr to the index VH->H[curr].next = index  
now our new closed dict would look like this 

-------------------------------------------------------------------------------------------------                
            data        next                  -               data        next       
index 0       0         -1                    -   index 5       7         -1 
index 1       0         -1                    -   index 6       0          7 
index 2       6          5                    -   index 7       0          8
index 3       0         -1                    -   index 8       0          9
index 4       0         -1                    -   index 9       0         -1
PRIMARY TABLE                                 -   SECONDARY TABLE
                                                Avail = 6 //available node to insert          
--------------------------------------------------------------------------------------------------
in a link list visual, it would like 
index 2[data 6, next is 5] -> index 5[data 7, next is -1] -> 1(NULL)
primary table                 the rest in secondary table





2. DELETION
Given we have this hash, we will simulate the three conditions of deletion
Delete at first, delete at first with an EXISTING next, deletion on secondary table
Outcome 1             Outcome 2                           Outcome 3
-------------------------------------------------------------------------------------------------                
            data        next                  -               data        next       
index 0       0         -1                    -   index 5       7          6 
index 1       0         -1                    -   index 6       8          7 
index 2       6          5                    -   index 7       9         -1
index 3       0         -1                    -   index 8       0          9
index 4       0         -1                    -   index 9       0         -1
PRIMARY TABLE                                 -   SECONDARY TABLE
                                                Avail = 8 //available node to insert          
--------------------------------------------------------------------------------------------------
in a link list visual, it would like 
index 2[data 6, next is 5] -> index 5[data 7, next is 6] -> index 6[data 8, next is 7] -> index 7[data 9, next is -1] -> 1(NULL)
primary table                 the rest in secondary table

//all three deletions can be simulated within 1 function where
set curr as key, and prev as -1 //curr will keep traversing the list until it finds the elem to delete, and prev will always be behind it
after traversal, we have a an if else statement do enact deletion where


if(prev == -1){
    if(curr next is NOT equal to -1){
    Outcome 2(Delete at First with existing connection)
    return;
    }

    Outcome 1(delete at first)
}else{
    Outcome 3(Delete on secondary table);
}




2.1 DELETE AT FIRST/DELETE AT FIRST WITH EXISING CONNECT
-------------------------------------------------------------------------------------------------                
            data        next                  -               data        next       
index 0       0         -1                    -   index 5       7          6 
index 1       0         -1                    -   index 6       8          7 
index 2       6          5                    -   index 7       9         -1
index 3       0         -1                    -   index 8       0          9
index 4       0         -1                    -   index 9       0         -1
PRIMARY TABLE                                 -   SECONDARY TABLE
                                                Avail = 8 //available node to insert          
--------------------------------------------------------------------------------------------------
//deleting data 6
index 2[data 6, next is 5] -> index 5[data 7, next is 6] -> index 6[data 8, next is 7] -> index 7[data 9, next is -1] -> 1(NULL)
    ^
curr is here
prev is -1
//in this scenario, we can see that there is a connection so Outcome 2 will occur 
2.1.1 Deleting at first with exisitn connection
- set curr first as the next, and then copy its data to the head
index 2[data 6, next is 5] -> index 5[data 7, next is 6] -> index 6[data 8, next is 7] -> index 7[data 9, next is -1] -> 1(NULL)
                                            ^
                                    curr is now here
                                    copy it to index

after copy it would look like:

index 2[data 7, next is 6] -> index 5[data 7, next is 6] -> index 6[data 8, next is 7] -> index 7[data 9, next is -1] -> 1(NULL)
                                            ^
                                    curr is still here
                                    copy it to index
//notice that both head and next is now the same, we overrid the data we wanted to delete(which was  6)

- after that, call deallocSpace on curr to free it 
index 2[data 7, next is 6] -> index 6[data 8, next is 7] -> index 7[data 9, next is -1] -> 1(NULL)
-------------------------------------------------------------------------------------------------                
            data        next                  -               data        next       
index 0       0         -1                    -   index 5       X          8 
index 1       0         -1                    -   index 6       8          7 
index 2       7          6                    -   index 7       9         -1
index 3       0         -1                    -   index 8       0          9
index 4       0         -1                    -   index 9       0         -1
PRIMARY TABLE                                 -   SECONDARY TABLE
                                                Avail = 5 //available node to insert          
--------------------------------------------------------------------------------------------------
//new state of the table

2.1.2 Delete at start
for this just delete the data in that index or smthn cuz we know theres no next 


DELETE ON SECONDARY TABLE
//lets say we will delete data 9 
index 2[data 7, next is 6] -> index 6[data 8, next is 7] -> index 7[data 9, next is -1] -> 1(NULL)
-------------------------------------------------------------------------------------------------                
            data        next                  -               data        next       
index 0       0         -1                    -   index 5       X          8 
index 1       0         -1                    -   index 6       8          7 
index 2       7          6                    -   index 7       9         -1
index 3       0         -1                    -   index 8       0          9
index 4       0         -1                    -   index 9       0         -1
PRIMARY TABLE                                 -   SECONDARY TABLE
                                                Avail = 5 //available node to insert          
--------------------------------------------------------------------------------------------------

//lets say we will delete data 9 
index 2[data 7, next is 6] -> index 6[data 8, next is 7] -> index 7[data 9, next is -1] -> 1(NULL)
                                        ^                            ^
                                prev is here                  curr is here

//think of deleting pos in link list, thats how it works
- link the prevs next to the currs next (VH->H[prev].next = VH->H[curr].next)
- free curr by calling deallocSpace, and now this is the tables final state
-------------------------------------------------------------------------------------------------                
            data        next                  -               data        next       
index 0       0         -1                    -   index 5       X          8 
index 1       0         -1                    -   index 6       8          7 
index 2       7          6                    -   index 7       X          5
index 3       0         -1                    -   index 8       0          9
index 4       0         -1                    -   index 9       0         -1
PRIMARY TABLE                                 -   SECONDARY TABLE
                                                Avail = 7 //available node to insert          
--------------------------------------------------------------------------------------------------
index 2[data 7, next is 6] -> index 6[data 8, next is -1] -> -1(NULL)


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





