/*
made by spry IM SO COOKED
EXAM 3 Coverage 
Priority Queue
Binary Tree
Binary Search Tree
Graphs


Priority Queue
- A queueing system that uses Max Heap, where starting from root each child will always be lower than the parent
Formulas to note
Parent = (child index - 1)/2
Left = 2(parent index) + 1
Right = 2(parent index) + 2
Delete root heapsort = size/2 - 1

PQ's Typedef 
typedef struct {
    int priority; // Priority level (Higher number = Higher priority)
    //maybe some other data
} Process;

// Priority Queue Structure (Max Heap Implementation)
// The heap array will store the processes.
typedef struct {
    Process heap[MAX_PROCESSES]; // Array to store the heap elements
    int size;                    // Current number of processes in the queue
    int capacity;                // Maximum capacity of the queue
} PriorityQueue;


Basic commands
1. enqueue(PriorityQueue * pq, int priority)
- Insert data at last available node (size), then increment
- while loop to upheapify(pushing the number up the tree until root)
    - upheapify uses a while loop that compares child and parent, call swap func if child is greater
- functions ends

2. dequeue(PriorityQueue * pq)
* depending on whats asked, might be a non void func that asks for returned value(extracted root)
- Swap data of root and last, then decrement size;
- Start a for loop where I starts at the last non leaf, each iteration call heapify to fix the heap
    - take note that the heapify argument would be heapify(pq, i)
    *we need to pass i as index for heapify to start there

3. Swap(Process * a, Process * b)
*Make sure the passed value to this functions are ADDRESSES of the struct containing data
- initialize temp to store the value of a(Process temp = *a)
- swap, assign value of b(*b) to value of a(*a) where (*a = *b)
- *b = temp

4. Heapify(PriorityQueue * pq, int i)
*concept of heapify is checks if a swap is possible, if it is then swap then recursively call the number
- initialize variables to store
largest = i //current parent index
left = 2(i) + 1 //current's left child
right = 2(i) + 2 //current's right child

- Setup two if statements, where both:
checks if its under size, meaning valid
if childs index value is higher than largest's index value, assign that specific child as largest 

- check if largest is not equal to i(if its not eq, it means a child is greater)
if condition was fulfilled:
call swap function on largest and i, then heapify where we pass largest as 2nd argument


Binary Tree & Binary Search Tree
BT:
- In shape of a tree, where each data is connected via parent-child relationship
- Looks similar to a PQ, but not in an array format as childs depend on their parent node
- Most common implementation is linked list
- Data is NOT sorted, therefore all datas are around the place

Three Types of Order 
Preorder - root, left, (middle), right
Postorder - left, (middle), right, root
Inorder - left, (middle), root, right
*note that middle is optional, because in cases of BT a middle child usually appears
*in the case of BST, there is no middle child

Terminologies
Root - topmost index, which starts at 0th index
Siblings - nodes under the same parent 
Path - sequences of the nodes as they go down the tree 
Ancestor - all the paths and nodes before the chosen node
Descendant - all the nodes from that subtree from a specific node
Subtree - a branch/node that serves as a root for its children nodes 
Height - number of connections found from root to latest child 
Depth - number of connections found from root to a specific node
Parent - node that serves as an ancestor for a child
Children - node that serves as a descendant of a node
Leaf - node without any children node
Cousins - 2 nodes of the same depth

Visualization: 
        5
      / | \
     0  6  2
       / \   \
      3   1   8
    / | \
   9  4  7
Preorder: 5 0 6 3 9 4 7 1 2 8 
Postorder: 0 9 4 7 3 1 6 8 2 5
Inorder: 0 5 9 3 4 7 6 1 8 2


BST
- Ordered through a system where compared to parent node, all left will be smaller and all right will be higher than the pnode
- Uses a double pointer system to traverse, where traversal will hold the address of the node were looking for/insert on



BST's typedef 
typedef struct node{
    struct node * lc;
    struct node * rc; 
    int data;
}*BST, node; 
//we need node for the sizeof() initializations, also for structs next(lc and rc) 

Basic Commands 
- Important note: traversal works via
    trav = (*trav)->data > val ? &(*trav)->lc : &(*trav)->rc
    //travs new address by checking if its current data is higher than the val we are inserting, 
    if not then we assign it the ADDRESS of lc else the ADDRESS of rc
    *assigning address is important to maintain integrity of double pointer


1. Insert(BST * tree, int val)
- initialize trav as double pointer, containing tree (BST * trav = tree)
- start a while with our traversal inside that only stops if *trav is null, or if matching value was found(duplicate checker)
- After loop stops, add an if statement checking if *trav is NULL (to ensure we are inserting at a free node)
- call calloc on the *trav, with 1 and sizeof(node), this initializes all values to 0 (pointers will treat 0 as null automatically)
- insert data on trav

2. Delete(BST * tree, int val)
- initialize trav as double pointer, containing tree (BST * trav = tree)
- start a while with our traversal inside that only stops if *trav is null, or if matching value was found(meaning target value was found)
- After loop stops, add an if statement checking if *trav's data is equal to target val (to ensure we are on the node we WANT to delete)
- if fulfilled, we start a chain of conditionals checking specifically for:
1. no children (Both null) //1st if statement
    - simply free *trav

2. left child only(left is NOT null, right is null) //2nd else if 
    - Initialize a single pointer temp to store the left child
    - free your *trav
    - assign your temp to *trav
    - now your trav contains the left child
    //note FOLLOW the * because its important to match what we are assigning 
    //if u dont put *, u are saying "we are assigning a single pointer to double pointer"

3. right child only(left is null, right is NOT null) //3rd else if
    - same code as outcome 2(left child only), but temp is set to right child

4. 2 childrens(both are NOT null) //4th else
    - initialize temp as right child of trav, which well use to look for the leftmost on the right subtree
    - start a while loop that ends if the lc of temp is null, and the loop traverses by assigning temps left to temp (temp = temp->lc)
    - after loop ends, copy the data of temp to trav
    - call delete function with the parameters as address of trav's right child, and value of temp: delete(&(*trav)->rc, temp->data)
    //this last step starts a 1 step recursion to delete the node we copied from, which is either no child or 1 child 



















*/




int child = size; 
int parent = 0; 
size++ 


//insertion
heap[child] = data;
while(child >= 0){
    parent = (child - 1)/2;
    if(heap[child] > heap[parent]){
        swap(&heap[child], &heap[parent]);
    }
    child = parent; 
} 


//deletion
int returntop = heap[0];
size--; 
swap(&heap[0], &heap[size]); 

for(int i = size/2 - 1;i >= 0;i--){
    heapify(pq, i);
}


//swap
int temp = *a;
*b = *a; 
*b = temp; 

//heapify 
int largest = i;
int left = 2(i) + 1;
int right = 2(i) + 2; 

if(left < size && arr[left] > arr[largest]){
    largest = left; 
}

if(right < size && arr[right] > arr[largest]){
    largest = right;
}

if(largest != i){
    swap(&arr[largest], &arr[i]);
    heapify(pq, largest);
}


