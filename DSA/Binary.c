#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct node* right;
    struct node* left;
};

struct Node * Traversal(struct Node * head){
    struct Node * p = head;
    while(p->right != NULL){
        printf("Element: %d\n",p->data);
        p=p->right;
    }
    printf("Element: %d\n",p->data);
}
struct Node * createNode(int data){
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->right = NULL;
    p->left = NULL;
    return p;
}

int main(){

   /*
    struct Node* p;
    struct Node* p1;
    struct Node* p2;

    p=(struct Node*)malloc(sizeof(struct Node));
    p1=(struct Node*)malloc(sizeof(struct Node));
    p2=(struct Node*)malloc(sizeof(struct Node));

    p->data = 7;
    p->left = NULL;
    p->right = p1;

    p1->data = 11;
    p1->left = p;
    p1->right = p2;

    p2->data = 2;
    p2->left = p1;
    p2->right = NULL;

  */
    struct Node * p= createNode(7);
    struct Node * p1= createNode(11);
    struct Node * p2= createNode(2);

    p->right = p1;
    p->left = NULL;

    p1->right = p2;
    p1->left = p;

    p2->right = NULL;
    p2->left = p1;

    Traversal(p);

    return 0;
}
