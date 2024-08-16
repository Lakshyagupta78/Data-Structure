#include<stdio.h>
#include<stdlib.h>


struct stack
{
    int size;
    int top;
    int * arr;
};

int IsEmpty(struct stack *ptr)
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


void push(struct stack *ptr,int val)
{
    if(IsFull(ptr))
    {
        printf("Stack overflow! cannot push %d to the stack\n",val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if(IsEmpty(ptr))
    {
        printf("Stack underflow! cannot pop from the stack");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }

}


int main()
{

    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp,1);
    push(sp,2);
    push(sp,3);
    push(sp,4);
    push(sp,5);
    push(sp,6);
    push(sp,7);
    push(sp,8);

    push(sp,9); // "Stack overflow because the size of array is 8;


    printf("Popped %d from the stack\n",pop(sp));


    if(IsEmpty(sp))
    {
        printf("The stack is Empty\n");
    }
    else
    {
        printf("The stack is Not empty\n");
    }

    if(IsFull(sp))
    {
        printf("The stack is Full\n");
    }
    else
    {
        printf("The stack is not full\n");
    }

    return 0;

}
