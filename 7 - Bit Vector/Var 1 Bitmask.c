#include<stdio.h>
#include<stdbool.h>

void initialize(unsigned char * set);
void insert(unsigned char * set, int element);
void delete(unsigned char * set, int element);
bool find(unsigned char * set, int element);
unsigned char Union(unsigned char A, unsigned char B);
unsigned char intersection(unsigned char A, unsigned char B);
unsigned char difference(unsigned char A, unsigned char B);
void display(unsigned char set);

int main(){
    printf("Starting program..\n");
    unsigned char setA, setB;
    initialize(&setA);
    initialize(&setB);

    insert(&setA, 0);
    insert(&setA, 1);
    insert(&setA, 2);
    insert(&setA, 3);
    printf("\nDisplaying Set A\n");
    display(setA);   

    printf("\nINSERTION\n");
    insert(&setB, 3);
    insert(&setB, 4);
    insert(&setB, 6);
    insert(&setB, 7);
    insert(&setB, 9);
    insert(&setB, -1);
    printf("\nDisplaying Set B\n");
    display(setB);   


    printf("\nDELETION\n");
    delete(&setA, 1);
    printf("\nDisplaying Set A\n");
    display(setA); 
    delete(&setB, 7);
    printf("\nDisplaying Set B\n");
    display(setB);

    printf("\nis 3 valid: %d\n", find(&setB, 3));
    unsigned char uni = Union(setA, setB);
    printf("\nDisplaying Union\n");
    display(uni);
    
    
    unsigned char inter = intersection(setA, setB);
    printf("\nDisplaying Intersection\n");
    display(inter);
    
    
    unsigned char diff = difference(setA, setB);
    printf("\nDisplaying Intersection\n");
    display(diff);
    
}

void initialize(unsigned char * set){
    *set = 0;
}

void insert(unsigned char * set, int element){
    if(element < 8 && element >= 0){
        unsigned char bitmask = 1 << element;
        *set |= bitmask; 
    }else{
        printf("\nCannot insert, element is invalid\n");
    }
}

void delete(unsigned char * set, int element){
    if(element < 8 && element >= 0){
        unsigned char bitmask = 1 << element; 
        bitmask = ~bitmask;
        *set &= bitmask;
        
    }else{
        printf("\nCannot delete, element is invalid.\n");
    }

}






bool find(unsigned char * set, int element){
        unsigned char bitmask = 1 << element;
        return (*set & bitmask) != 0; 
}

unsigned char Union(unsigned char A, unsigned char B){
    return (A | B);
}

unsigned char intersection(unsigned char A, unsigned char B){
    return (A & B);
}
unsigned char difference(unsigned char A, unsigned char B){
    return (A & (~B));

    
}
void display(unsigned char set){
    for(int i = 0; i < 8; i++){
        if((set >> i) & 1){
            printf("%d ", i);
        }
    }
}