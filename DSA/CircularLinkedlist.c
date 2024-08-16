#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node * CircularTraversal(struct Node *head){
    struct Node *p = head;

    do{
        printf("Element: %d\n",p->data);
        p = p->next;
    }while(p!=head);
}

struct Node * insertAtfirst(struct Node *head,int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;

    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}


int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 4;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = head;

    printf("Circular Linked list before insertion\n");
    CircularTraversal(head);

    printf("circular Linked list after insertion\n");
    head = insertAtfirst(head,90);
    CircularTraversal(head);
}
