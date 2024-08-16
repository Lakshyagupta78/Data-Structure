#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char * arr;
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

void push(struct stack * ptr, char val){
    if(IsFull(ptr)){
        printf("Stack Overflow, cannot push %d to the stack\n",val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack * ptr){
    if(IsEmpty(ptr)){
        printf("Stack Underflow, cannot pop from the stack.");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int match(char a, char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    return 0;

}

int MultipleParenthesis(char * exp){
    struct stack * n = (struct stack *)malloc(sizeof(struct stack));
    n->size = 100;
    n->top = -1;
    n->arr = (char *)malloc(n->size * sizeof(char));
    char popped_ch;

    for(int i=0; exp[i] != '\0'; i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(n,exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(IsEmpty(n)){
                return 0;
            }
            else{
                popped_ch = pop(n);
                if(!match(popped_ch, exp[i])){
                    return 0;
                }
            }

        }
    }
    if(IsEmpty(n)){
        return 1;
    }
    else{
        return 0;
    }
}


int main(){
    char * exp = "{[9(787-23)]}";
    if(MultipleParenthesis(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }

    return 0;
}
