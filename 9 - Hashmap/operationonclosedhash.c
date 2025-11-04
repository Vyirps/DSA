
#define MAX 10

typedef struct
{
    char *code;
    int next;
} Node, Heapspace[MAX];

typedef struct
{
    int avail;
    Heapspace H;
} VHeap;

insertSortedCode(VHeap *VH, char *code) //string
{
    if (VH->avail != -1)
    {
        int key = hash(code);

        Node *curr = &VH->H[key];
        Node *prev = NULL;

        if (strcmp(curr->code, EMPTY) == 0)
        {
            strcpy(curr->code, code);
            return;
        }

        while (curr->next != -1)
        {
            if (strcmp(curr->code, code) == 0)
            {
                printf("SAME");
                return;
            }

            if (strcmp(curr->code, code) > 0)
            {
                break;
            }

            prev = curr;
            curr = &VH->H[curr->next];
        }

        int index = allocSpace(VH);
        VH->H[index].next = -1

                            if (strcmp(curr->code, code) < 0)
        {
            prev = curr;
        }

        if (prev == NULL)
        {
            VH->H[index] = *curr;
            strcpy(curr->code, code);
            curr->next = index;
        }
        else
        {
            strcpy(VH->H[index].code, code);
            VH->H[index].next = prev->next;
            prev->next = index;
        }
    }
    a d
        b
            c

                p = n

                    insert a
}

delete(VHeap *VH, char *code) //string
{
    int key = hash(code);
    Node *curr = &VH->H[key];
    Node *prev = NULL;

    while (curr->next != -1)
    {
        if (strcmp(curr->code, code) == 0)
        {
            break;
        }
        prev = curr;
        curr = &VH->H[curr->next];
    }

    if (strcmp(curr->code, code) != 0)
    {
        return;
    }

    if (prev == NULL)
    {
        if (curr->next == -1)
        {
            strcpy(curr->code, DELETED);
            return;
        }

        VH->H[key] = VH->H[curr->next];
        dealloc(VH, curr->next);
    }
    else
    {
        int index = prev->next;
        prev->next = curr->next;
        dealloc(VH, index);
    }
}

void insertClosed(VHeap *VH, int elem) //elem
{
    if (VH->avail != -1)
    {
        int key = hash(elem);
        if (VH->H[key].code == EMPTY || VH->H[key].code == DELETED)
        {
            VH->H[key].code = elem;
            return;
        }

        Node *curr = &VH->H[key], *prev = NULL;
        while (1)
        {
            if (elem == curr->code)
            {
                printf("found!");
                return;
            }

            if (curr->code > elem || curr->next == -1)
            {
                break;
            }
            prev = curr;
            curr = &VH->H[*curr->next];
        }

        if (elem > curr->code)
        {
            prev = curr;
        }

        int index = allocSpace(VH);

        if (prev == NULL)
        {
            VH->H[index] = *curr;
            curr->code = elem;
            curr->next = index;
        }
        else
        {
            VH->H[index].code = elem;
            VH->H[index].next = prev->next;
            prev->next = index;
        }
    }
}

void delete(VHeap * VH, int elem){ //elem
    int key = hash(elem); 
    Node * curr = &VH->H[key], * prev = NULL; 

    while(1){
        if(curr->elem == elem){
            break; 
        }

        if(curr->next == -1){
            printf("not found");
            return; 
        }

        prev = curr;
        curr = &VH->H[curr->next]; 
    }

    if(prev = NULL){
        if(curr->next != -1){
            int index = curr->next; 
            *curr = VH->H[index];
            deallocSpace(index);
            return; 
        }
        curr->code = "DELETED";
    }else{
        int index = prev->next; 
        prev->next = curr->next; 
        deallocSpace(index); 
    }
}


