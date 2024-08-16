#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node * DoublyTraversal(struct Node *head)
{
    struct Node * p = head;

      printf("Traversing left to right\n");
    while(p->next!=NULL){
        printf("Element: %d\n",p->data);
        p = p->next;
    }
   // printf("Element: %d",p->data);
   // printf("\n");

    printf("Traversing right to left\n");
    while(p!=NULL)
    {
        printf("Element: %d\n",p->data);
        p = p->prev;

    }

}


int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;


    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;
    head->prev = NULL;


    second->data = 10;
    second->next = third;
    second->prev = head;


    third->data = 15;
    third->next = fourth;
    third->prev = second;


    fourth->data = 20;
    fourth->next = NULL;
    fourth->prev =third;

    DoublyTraversal(head);


}
