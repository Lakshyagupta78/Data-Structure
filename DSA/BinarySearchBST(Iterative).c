#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createNode(int data){
    struct node * p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

struct node * SearchIterative(struct node *root,int key){
    while(root != NULL){
        if(root->data == key){
            return root;
        }
        else if(root->data>key){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}

int main(){
    struct node * p = createNode(5);
    struct node * p1 = createNode(3);
    struct node * p2 = createNode(6);
    struct node * p3 = createNode(2);
    struct node * p4 = createNode(4);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

  //  struct node *n =SearchIterative(p,10); //Element not found
    struct node *n =SearchIterative(p,6); //Found:)

    if(n != NULL){
        printf("Found: %d",n->data);
    }
    else{
        printf("Element not found");
    }

}
