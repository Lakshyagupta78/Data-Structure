#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    int * arr;
};

int IsEmpty(struct stack * ptr)
{
    if(ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsFull(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{


    struct  stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));


    //Insert elements manually.
    s->arr[0] = 1;
    s->top++;


    s->arr[1] = 9;
    s->top++;

    s->arr[2] = 2;
    s->top++;

    s->arr[3] = 3;
    s->top++;

    s->arr[4] = 4;
    s->top++;

    s->arr[5] = 8;
    s->top++;



    if(IsEmpty(s)){
        printf("The stack is Empty\n");
    }
    else{
        printf("The stack is Not empty\n");
    }

    if(IsFull(s)){
        printf("The stack is Full\n");
    }
    else{
        printf("The stack is not full\n");
    }
    return 0;



}
