#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void linkedlistTraversal(struct Node * ptr){
    while(ptr != NULL){
        printf("Element: %d\n",ptr->data);
        ptr = ptr->next;
    }
}

int IsFull(struct Node * top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int IsEmpty(struct Node * top){
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node * Push(struct Node * top,int x){
    if(IsFull(top)){
        printf("Stack Overflow");
    }
    else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

struct Node * Pop(struct Node** top){
    if(IsEmpty(*top)){
        printf("Stack UnderFlow");
    }
    else{
        struct Node * n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main(){
    struct Node * top = NULL;
     top = Push(top,5);
     top = Push(top,9);
     top = Push(top,6);
     top = Push(top,0);
     printf("Traversal before popping\n");
     linkedlistTraversal(top);

     int element = Pop(&top);
     printf("\nPopped element is %d\n",element);

     printf("\nTraversal after popping\n");
     linkedlistTraversal(top);

    return 0;
}
