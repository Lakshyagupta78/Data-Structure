#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char * arr;
};

int stackTop(struct stack * ptr)
{
    return ptr->arr[ptr->top];
}

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

int Precedence(char ch)
{
    if(ch == '*' || ch == '/')
    {
        return 3;
    }
    if(ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if(ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
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

char * InfixToPostfix(char * infix)
{
    struct stack * sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 80;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char * postfix = (char *)malloc((strlen(infix)+1) * sizeof(char));
    int i=0;
    int j=0;

    while(infix[i]!='\0')
    {
        if(!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if(Precedence(infix[i])>Precedence(stackTop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!IsEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char * infix[100];

    printf("Enter a infix expression ");
    scanf("%s",infix);

    printf("Postfix is %s",InfixToPostfix(infix));
    return 0;
}
