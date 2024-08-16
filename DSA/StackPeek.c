#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int * arr;
};

int IsEmpty(struct stack * ptr){
    if(ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int IsFull(struct stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int peek(struct stack * ptr,int i){
    int arrInd = ptr->top - i + 1;
    if(arrInd < 0){
        printf("Please enter valid position");
        return -1;
    }
    else{
        return ptr->arr[arrInd];
    }
}

int main(){
   struct stack * s = (struct stack *)malloc(sizeof(struct stack));
   s->size = 8;
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

    for(int j=1;j<=s->top+1;j++){
        printf("The value at position %d is %d\n",j,peek(s,j));
    }


    if(IsEmpty(s)){
        printf("The stack is Empty");
    }
    else{
        printf("The stack is not Empty");
    }

    if(IsFull(s)){
        printf("The stack is Full");
    }
    else{
        printf("The stack is not Full");
    }



    return 0;
}
