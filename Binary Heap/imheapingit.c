/*
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

*/