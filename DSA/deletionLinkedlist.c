#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *linkedlistTraversal(struct Node *ptr){

    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

//Case 1->Deleting the first node.
struct Node *deleteFirstNode(struct Node *head){
    struct Node * p = head;
    head = head->next;
    free(p);
    return head;
}


//Case 2-> deleting the element at given index.
struct Node *deleteAtIndex(struct Node *head,int index){

    struct Node * p = head;
    struct Node * q = head->next;

    for(int i=0;i<index-1;i++){

        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

//Case 3->Deleting the last node.
struct Node *deleteLastNode(struct Node *head){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

//Case 4->Deleting the first node with a given value.
struct Node *deleteValueNode(struct Node *head,int value){
    struct Node *p = head;
    struct Node *q = head->next;

    while(q->data!=value && q->next!=NULL){
        p = p->next;
        q = q->next;
    }
    if(q->data == value){
        p->next = q->next;
        free(q);
    }
    return head;
}

int main(){

    struct Node *head;
    struct Node *second;
    struct Node     *third;
    struct Node *fourth;


    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));


    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = NULL;

    printf("Without ant deletion\n");
    linkedlistTraversal(head);


   //Case 1:
   //printf("Deleting the first Node\n");
   //head = deleteFirstNode(head);
   //linkedlistTraversal(head);

    //Case 2:
    //printf("Delete the given index\n");
    //head = deleteAtIndex(head,2);
    //linkedlistTraversal(head);

    //Case 3:
    //printf("Deleting the last node\n");
    //head = deleteLastNode(head);
    //linkedlistTraversal(head);

    //Case 4:
    printf("Delete the node with given value\n");
    head = deleteValueNode(head,15);
    linkedlistTraversal(head);

    return 0;
}
