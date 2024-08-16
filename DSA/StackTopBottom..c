#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int IsEmpty(struct stack * sp){
    if(sp->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsFull(struct stack * sp){
    if(sp->top == sp->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(struct stack * sp,int i){
    int arrInd = sp->top - i + 1;
    if(arrInd < 0){
        printf("Please enter valid position");
        return -1;
    }
    else{
        return sp->arr[arrInd];
    }
}

int StackTop(struct stack * sp){
    return sp->arr[sp->top];
}

int StackBottom(struct stack * sp){
    return sp->arr[0];
}


int main(){
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
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

    printf("The Top most element of this stack is: %d\n",StackTop(s));
    printf("The Bottom most element of this stack is: %d\n",StackBottom(s));

    if(IsEmpty(s)){
        printf("The stack is Empty\n");
    }
    else{
        printf("The stack is not Empty\n");
    }

    if(IsFull(s)){
        printf("The stack is Full\n");
    }
    else{
        printf("The stack is not Full\n");
    }

    for(int j=1;j<=s->top+1;j++){
        printf("The value at position %d is %d\n",j,peek(s,j));
    }

    return 0;

}
