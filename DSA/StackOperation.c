#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * top = NULL;

int IsFull(struct Node * top)
{
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

IsEmpty(struct Node * top)
{
    if(top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

struct Node * Push(struct Node * top,int x)
{
    if(IsFull(top))
    {
        printf("Stack Overflow");
    }
    else
    {
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int Peek(int pos)
{
    struct Node * ptr = top;
    for(int i=0; (i<pos-1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }
    if(ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int StackTop(struct Node * ptr){
    return ptr->data;
}

int StackBottom(struct Node * ptr){
    struct Node * p = ptr;
    while(p->next != NULL){
        p = p->next;
    }
    return p->data;
}

int main()
{

    top = Push(top,5);
    top = Push(top,10);
    top = Push(top,15);
    top = Push(top,20);

    printf("\nValue at 1 is %d\n\n", Peek(1));

    printf("Top most of the stack is %d\n",StackTop(top));

    printf("Bottom most of the stack is %d\n",StackBottom(top));


    return 0;
}
