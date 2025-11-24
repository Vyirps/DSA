        #include<stdio.h>
        #include<stdlib.h>
        #include<stdbool.h>

        #define MAX 10 

        typedef struct{
            int arr[MAX]; 
            int counter; 
        }Heap; 





        void swap(int * a, int * b);
        void enqueue(Heap * BH, int * size); 
        void upheapify(int * arr, int size);
        void dequeue(int * arr, int * size);
        void downheap(int * arr, int * size);
        void printheap(int * arr, int size);


        int main(){

            int size;
            Heap * BH = malloc(sizeof(Heap));
            size = 0;
            BH->counter = 0;

            printf("hello\n");

            enqueue(BH, &size);
            enqueue(BH, &size);
            enqueue(BH, &size);
            printheap(BH->arr, size); 
            








        }


        void swap(int * a, int * b){
            int temp = *a; 
            *a = *b; 
            *b = temp;
        }
        void enqueue(Heap * BH, int * size){
            if(*size != MAX){
                BH->arr[*size] = BH->counter;
                BH->counter += 1;

                upheapify(BH->arr, *size);
                (*size)++; 
            }
        }
        void upheapify(int * arr, int size){
            int child = size; 
            int parent; 
            while(child >= 0 ){
                parent = (child - 1)/2;

                if(arr[child] > arr[parent]){
                    swap(&arr[child],  &arr[parent]);
                }else{
                    break;
                }

                child = parent;

            }



        }

        void printheap(int * arr, int size){
            for(int i = 0;i < size;i++){
                printf("Index %d | Data %d\n", i, arr[i]);
            }
        }
        void dequeue(int * arr, int * size);


        void downheap(int * arr, int * size);
