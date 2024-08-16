#include<stdio.h>
#include<stdio.h>

struct CircularQueue
{
    int size;
    int f;
    int r;
    int * arr;
};

int IsFull(struct CircularQueue * ptr)
{
    if((ptr->r+1)%ptr->size == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsEmpty(struct CircularQueue * ptr)
{
    if(ptr->r == ptr->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Enqueue(struct CircularQueue * ptr,int val)
{
    if(IsFull(ptr))
    {
        printf("Queue is full\n");
    }
    else
    {
        ptr->r = (ptr->r+1)%ptr->size;
        ptr->arr[ptr->r] = val;
        printf("Enqueuing element %d\n",val);
    }
}

int Dequeue(struct CircularQueue * ptr)
{
    int val = -1;
    if(IsEmpty(ptr))
    {
        printf("Queue is empty\n");
    }
    else
    {
        ptr->f = (ptr->f+1)% ptr->size;
        val = ptr->arr[ptr->f];
    }
    return val;
}

int main()
{
    struct CircularQueue s;
    s.size = 4;
    s.f = s.r = 0;  // In circular Queue we start F and R with 0th index.
    s.arr = (int *)malloc(s.size*sizeof(int));

    //Enquque the element

    Enqueue(&s,10);
    Enqueue(&s,11);
    Enqueue(&s,12);
    Enqueue(&s,12);

    printf("Dequeuing element %d\n",Dequeue(&s));
    printf("Dequeuing element %d\n",Dequeue(&s));
    printf("Dequeuing element %d\n",Dequeue(&s));

    Enqueue(&s,45);

    return 0;
}

