#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
};

struct node * createnode(int data){
    struct node * p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

void inOrder(struct node * root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

struct node * InorderPredecessor(struct node * root){
    root = root->left;
    while(root->right != NULL){
       root = root->right;
    }
    return root;
}

struct node * Delete(struct node *root,int value){
    struct node * ipre;
    if(root == NULL){
        return NULL;
    }
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(value<root->data){
        root->left = Delete(root->left,value);
    }
    else if(value>root->data){
        root->right = Delete(root->right,value);
    }
    else{
        ipre = InorderPredecessor(root);
        root->data = ipre->data;
        root->left =Delete(root->left,ipre->data);
    }
    return root;
}


int main(){
    struct node * p = createnode(5);
    struct node * p2 = createnode(3);
    struct node * p3 = createnode(6);
    struct node * p4 = createnode(1);
    struct node * p5 = createnode(4);

    p->left = p2;
    p->right = p3;

    p2->right = p5;
    p2->left = p4;

    inOrder(p);
    Delete(p,3);
    printf("\n");
    inOrder(p);

}
