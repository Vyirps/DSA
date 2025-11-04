#include <stdio.h>
#include <stdbool.h>

#define MAX 10

void printHeap(int *arr, int size);
void enqueue(int *arr, int *size);
void dequeue(int *arr, int *size);
void downheapify(int *arr, int n, int size);
bool isFull(int size);
bool isEmpty(int size);

int main()
{
    int arr[MAX], size = 0, choice = 0;
    while (choice != 4)
    {
        printf("\n--- Priority Queue ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Print Queue\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnqueue\n");
            if (!isFull(size))
            {
                enqueue(arr, &size);
            }
            else
            {
                printf("\nCannot Enqueue, Queue is Full!\n");
            }
            break;

        case 2:
            printf("\nDequeue");
            if (!isEmpty(size))
            {
                dequeue(arr, &size);
            }
            else
            {
                printf("\nCannot Dequeue, Queue is Empty!\n");
            }
            break;

        case 3:
            printf("\nPrinting Queue: ");
            if (!isEmpty(size))
            {
                printHeap(arr, size);
            }
            else
            {
                printf("\nQueue is Empty!\n");
            }
            break;

        case 4:
            printf("\nExiting the Program....");
            break;

        default:
            printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}

void printHeap(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d -> ", arr[i]);
    }
    printf("NULL");
}
void enqueue(int *arr, int *size)
{
    int elem = *size;
    if (isEmpty(*size))
    {
        arr[0] = elem;
    }
    else
    {
        arr[*size] = elem;
        int temp = *size;
        int parent;
        while (temp != 0)
        {
            parent = (temp - 1) / 2;
            if (arr[temp] > arr[parent])
            {
                int swap = arr[parent];
                arr[parent] = arr[temp];
                arr[temp] = swap;
            }
            temp = parent;
        }
    }
    printf("Queue Number %d is now enqueued", elem);
    (*size)++;
}
void dequeue(int *arr, int *size)
{
    printf("\nDequeueing Number %d", arr[0]);
    arr[0] = arr[*size - 1];
    (*size)--;
    int temp = 0;
    while (((2 * temp) + 1) < *size)
    {
        int left = (2 * temp) + 1;
        int right = (2 * temp) + 2;
        int bigger;

        if (right > *size)
        {
            bigger = left;
        }
        else
        {
            if (arr[left] > arr[right])
            {
                bigger = left;
            }
            else
            {
                bigger = right;
            }
        }

        if (arr[temp] < arr[bigger])
        {
            int swap = arr[temp];
            arr[temp] = arr[bigger];
            arr[bigger] = swap;

            temp = bigger;
        }
        else
        {
            printf("\nNo More Swaps!");
            break;
        }

        printf("\nSwapping...");
    }
    printf("\nDequeue Successful!");
}

bool isFull(int size)
{
    return size == MAX;
}
bool isEmpty(int size)
{
    return size == 0;
}