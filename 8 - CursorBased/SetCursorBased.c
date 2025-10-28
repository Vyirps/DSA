#include<stdio.h>
#include<stdbool.h>
#define MAX 60


typedef struct{
    int elem; 
    int next;
}Node, Heapspace[MAX];

typedef struct{
    Heapspace H;
    int avail;
}VHeap;

void initHeap(VHeap * VH, int * set1, int * set2, int * set3, int * Union, int * intersect, int * difference);
int allocSpace(VHeap * VH);
void deallocSpace(VHeap * VH, int index);
bool isFinder(VHeap * VH, int elem, int * L);
void display(VHeap VH, int L);
void insertUnique(VHeap * VH, int elem, int * L);
void delete(VHeap * VH, int elem, int *L);
void unionNewSet(VHeap * VH, int * set1, int * set2, int * set3, int * Union);
void intersectNewSet(VHeap * VH, int * set1, int * set2, int * set3, int * intersectSet);
void differenceNewSet(VHeap * VH, int * set1, int * set2, int * set3, int * differenceSet);
void deleteSet(VHeap * VH, int * set);


int main(){


    int set1 = -1;
    int set2 = -1;
    int set3 = -1; 
    int unionSet = -1;
    int intersectSet = -1;
    int differenceSet = -1;
    

    VHeap VH;

    int choice = 0; 

    while(choice != 10){
        int setChoice = 0;
        int elem = 0;
        printf("\n\nWelcome to Set Cursor Based! Select your options\n1. Initialize\n2. Insert to Set\n3. Delete from Set\n4. Union of All\n5. Intersection of All\n6. Difference of All\n7. Display\n8. Delete set\n9. Delete Vheap\n10. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

    switch(choice){
         case 1:{
            printf("INITIALIZING VHEAP\n");
            initHeap(&VH, &set1, &set2, &set3, &unionSet, &intersectSet, &differenceSet);
            printf("Heap Initialized!");
            break;
        }

        case 2:{
            printf("INSERT TO SET\n");
            printf("Enter what set to enter(1,2,3): ");
            scanf("%d", &setChoice);
            printf("Enter elem to insert: ");
            scanf("%d", &elem);

                if(setChoice == 1){
                    insertUnique(&VH, elem, &set1);
                }
                else if(setChoice == 2){
                    insertUnique(&VH, elem, &set2);
                }
                else if(setChoice == 3){
                    insertUnique(&VH, elem, &set3);
                }else{
                    printf("Invalid Set!");
                }
            break;
        }

        case 3:{
            printf("DELETE FROM SET\n");
            printf("Enter what set to delete(1,2,3): ");
            scanf("%d", &setChoice);
            printf("Enter elem to delete: ");
            scanf("%d", &elem);

                if(setChoice == 1){
                    delete(&VH, elem, &set1);
                }
                else if(setChoice == 2){
                    delete(&VH, elem, &set2);
                }
                else if(setChoice == 3){
                    delete(&VH, elem, &set3);
                }else{
                    printf("Invalid Set!");
                }
            break;
        }

        case 4:{
            printf("UNION OF ALL\n");
            unionNewSet(&VH, &set1, &set2, &set3, &unionSet);
            break;
        }

        case 5:{
            printf("INTERSECTION OF ALL\n");
            intersectNewSet(&VH, &set1, &set2, &set3, &intersectSet);
            break;
        }

        case 6:{
            printf("DIFFERENCE OF ALL\n");
            printf("Enter what set to difference(1,2,3): ");
            scanf("%d", &setChoice);

                if(setChoice == 1){
                    differenceNewSet(&VH, &set1, &set2, &set3, &differenceSet);
                }
                else if(setChoice == 2){
                    differenceNewSet(&VH, &set2, &set1, &set3, &differenceSet);
                }
                else if(setChoice == 3){
                    differenceNewSet(&VH, &set3, &set1, &set2, &differenceSet);
                }else{
                    printf("Invalid Set!");
                }
            break;
        }

        case 7:{
            printf("DISPLAY ALL\n");
            printf("SET 1: ");
            display(VH, set1);
            printf("SET 2: ");
            display(VH, set2);
            printf("SET 3: ");
            display(VH, set3);
            printf("SET Union: ");
            display(VH, unionSet);
            printf("SET Intersect: ");
            display(VH, intersectSet);
            printf("SET Difference: ");
            display(VH, differenceSet);
            break;
        }

        case 8:{
            printf("DELETE SET\n");
            printf("Enter what set to difference(1,2,3, 4(Union), 5(Intersect), 6(Difference)): ");
            scanf("%d", &setChoice);

                if(setChoice == 1){
                    deleteSet(&VH, &set1);
                }
                else if(setChoice == 2){
                    deleteSet(&VH, &set2);
                }
                else if(setChoice == 3){
                    deleteSet(&VH, &set3);
                }
                else if(setChoice == 4){
                    deleteSet(&VH, &unionSet);
                }
                else if(setChoice == 5){
                    deleteSet(&VH, &intersectSet);
                }
                else if(setChoice == 6){
                    deleteSet(&VH, &differenceSet);
                }
                else{
                    printf("Invalid Set!");
                }

            break;
        }

        case 9:{
            printf("DELETE VHEAP\n");
            initHeap(&VH, &set1, &set2, &set3, &unionSet, &intersectSet, &differenceSet);
            break;
        }

        case 10:{
            printf("Exiting Program...\n");
        }
    }
       
            
            
    }
    
}



void initHeap(VHeap * VH, int * set1, int * set2, int * set3, int * Union, int * intersect, int * difference){
    for(int i = 0;i < MAX - 1;i++){ 
        VH->H[i].next = i+1;
    }


    VH->H[MAX - 1].next = -1;
    VH->avail = 0;

    *set1 = -1;
    *set2 = -1;
    *set3 = -1;
    *Union = -1;
    *intersect = -1;
    *difference = -1;
}

int allocSpace(VHeap * VH){
    int index  = VH->avail;
    VH->avail = VH->H[index].next;
    return index;
}

void deallocSpace(VHeap * VH, int index){
    VH->H[index].next = VH->avail;
    VH->avail = index;
}

bool isFinder(VHeap * VH, int elem, int * L){
    int * trav = L; 
    while(*trav != -1){
        if(VH->H[*trav].elem == elem){
            return true;
        }
        trav =  &VH->H[*trav].next;
    }

    return false; 
}

void display(VHeap VH, int L){
    if(L != -1){
        int curr = L;
        printf("{ ");
        while(curr != -1){
            printf("%d", VH.H[curr].elem);
            curr = VH.H[curr].next;
            if(curr != -1){
               printf(", ");
            }
        }
        printf(" }\n");
    }else{
        printf("No existing set!\n");
    }
   
}



void insertUnique(VHeap * VH, int elem, int * L){
    if(VH->avail != -1){
        if(!(isFinder(VH, elem, L))){
            int * curr = L; 
            
            int index = allocSpace(VH); 
            VH->H[index].next = -1; 
            VH->H[index].elem = elem;


            while(*curr != -1){
                if(elem < VH->H[*curr].elem){
                    VH->H[index].next = *curr; 
                    break;
                }
                curr = &VH->H[*curr].next;
            }

            *curr = index;

            printf("Inserted elem %d at index %d!\n", elem, index);
        }else{
            printf("Element is already in the set!\n");
        }

    }else{
        printf("\nCannot Insert, full Set!\n");
    }
}

void delete(VHeap * VH, int elem, int *L){
    if(*L != -1){
        
        if(!(isFinder(VH, elem, L))){
            printf("Not in the set!\n");
            return;
        }


        int * curr = L;
        while(*curr != -1){
            printf("traversing...\n");
            if(VH->H[*curr].elem == elem){
                printf("Found!\n");
                break;
            }
            curr = &VH->H[*curr].next;
        }

        int index = *curr; 
        *curr = VH->H[*curr].next;
        deallocSpace(VH, index);
        printf("Deleted %d successfully!\n", elem);

    }else{
        printf("Empty Set!\n");
    }

}

void unionNewSet(VHeap * VH, int * set1, int * set2, int * set3, int * Union){
    int * curr = set1;
    while(*curr != -1){
        insertUnique(VH, VH->H[*curr].elem, Union);
        curr = &VH->H[*curr].next;
    }

    curr = set2;
    while(*curr != -1){
        insertUnique(VH, VH->H[*curr].elem, Union);
        curr = &VH->H[*curr].next;
    }

    curr = set3;
    while(*curr != -1){
        insertUnique(VH, VH->H[*curr].elem, Union);
        curr = &VH->H[*curr].next;
    }
}

void intersectNewSet(VHeap * VH, int * set1, int * set2, int * set3, int * intersectSet){
    int * one = set1;


    while(*one != -1){
        if(isFinder(VH, VH->H[*one].elem, set2) && (isFinder(VH, VH->H[*one].elem, set3))){
           
                insertUnique(VH, VH->H[*one].elem, intersectSet);
            
        }
        one = &VH->H[*one].next;
    }


}


void differenceNewSet(VHeap * VH, int * set1, int * set2, int * set3, int * differenceSet){
    int * one = set1, * two = set2, *three = set3;

    while(*one != -1){
        if(!(isFinder(VH, VH->H[*one].elem, two)) && (!(isFinder(VH, VH->H[*one].elem, three)))){
           
                insertUnique(VH, VH->H[*one].elem, differenceSet);
            
        }
        one = &VH->H[*one].next;
    }

}

void deleteSet(VHeap * VH, int * set){
    VH->H[*set].next = VH->avail;
    VH->avail = *set;
    *set = -1; 
}



