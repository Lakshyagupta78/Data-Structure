#include<stdio.h>
#include<stdlib.h>

struct Node
{

    int data;
    struct Node *next;
};

linkedlistTraversal(struct Node *ptr)
{

    while(ptr!=NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}


//Case 1-> Insert at the beginning:

struct Node *insertinbeginning(struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}


//Case 2-> Insert in between:
struct Node *insertAtIndex(struct Node *head,int data,int index)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    int i = 0;
    while(i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}


//Case 3-> Insert at End:
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    ptr->data = data;

    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}



//Case 4-> Insert after a Node:
struct Node *insertAfterNode(struct Node *PrevNode,struct Node *head,int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = PrevNode->next;
    PrevNode->next = ptr;
    return head;
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


    second->data = 10;
    second->next = third;


    third->data = 15;
    third->next = fourth;


    fourth->data = 20;
    fourth->next = NULL;


    printf("without any insersion\n");
    linkedlistTraversal(head);


    //Case-1;
    // printf("Insert at the beginning(Case-1)\n");
    // head = insertinbeginning(head,78);
    // linkedlistTraversal(head);


    //Case-2;
    // printf("Insert in between(Case-2)\n");
    // head = insertAtIndex(head,89,1);
    // linkedlistTraversal(head);


    //Case-3;
    //  printf("Insert at the End(Case-3)\n");
    //  head = insertAtEnd(head,90);
    //  linkedlistTraversal(head);



    //Case-4;
    printf("Insert after a Node(Case-4)\n");
    head = insertAfterNode(second,head,35);
    linkedlistTraversal(head);


    return 0;
}
