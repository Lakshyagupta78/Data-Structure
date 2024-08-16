#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void linkedlistTraversal(struct node *p){
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->link;
    }
}

int main(){
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *current = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));


    head->data = 45;
    head->link = current;

    current->data = 10;
    current->link = third;

    third->data = 20;
    third->link = NULL;

    linkedlistTraversal(head);


    return 0;
}
