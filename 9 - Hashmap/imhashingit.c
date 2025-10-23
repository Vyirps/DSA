/*
two types of hash, open and close
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
there are 2 variants, number and string but follow the general rule of % arraysize
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
- get your key, insert it at that index, if null then make it head else insert first
}

5. deletion (match checking through traversal)
- get your key, initialize a temp to traverse, do it like deletepos, if not found then return -1

6. finder
- get your key, initialize a temp to traverse, if found return true if not then -1
SPECIAL CASE: if asking for a struct, return address of struct on true and null at false
*/

