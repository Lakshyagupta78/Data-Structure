#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * createNode(int data){
    struct node * p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
};

void Inorder(struct node * root){
    if(root != NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}

struct node * Search(struct node * root,int key){
    if(root == NULL){
        return NULL;
    }
    else if(root->data == key){
        return root;
    }
    else if(root->data > key){
        return Search(root->left,key);
    }
    else{
        return Search(root->right,key);
    }
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

    //Inorder(p);

    struct node * n = Search(p,6);
    if(n != NULL){
        printf("Found: %d",n->data);
    }
    else{
        printf("Element not found");
    }
}
