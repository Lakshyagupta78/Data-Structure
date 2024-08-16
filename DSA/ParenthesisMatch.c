#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char * arr;
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

void push(struct stack *ptr,char val)
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

char pop(struct stack *ptr)
{
    if(IsEmpty(ptr))
    {
        printf("Stack underflow! cannot pop from the stack");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }

}

int ParenthesisMatch(char * exp)
{
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
        {
            push(sp,'(');
        }
        else if(exp[i] == ')')
        {
          if(IsEmpty(sp))
              {
                  return 0;
              }
              else
              {
                  pop(sp);
              }
        }


    }
    if(IsEmpty(sp))
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
    char * exp = "(7+8)";

    if(ParenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }

    return 0;
}
