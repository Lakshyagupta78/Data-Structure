#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node * left;
    struct node * right;
    int height;
};

int Max(int a,int b){
    return (a>b)?a:b;
}

struct node * createNode(int data){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->left = NULL;
    n->right =  NULL;
    n->data = data;
    n->height = 1;
}

int getheight(struct node * n){
    if(n==NULL){
        return 0;
    }
    return n->height;
}

int getBalanceFactor(struct node * n){
    if(n==NULL){
        return 0;
    }
    return getheight(n->left) - getheight(n->right);
}

struct node * rightRotate(struct node * y){
    struct node * x = y->left;
    struct node * T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = Max(getheight(x->right),getheight(x->left)) + 1;
    y->height = Max(getheight(y->right),getheight(y->left)) + 1;

    return x;
}

struct node * leftRotate(struct node * x){
    struct node * y = x->right;
    struct node * T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = Max(getheight(x->right), getheight(x->left)) + 1;
    y->height = Max(getheight(y->right), getheight(y->left)) + 1;

    return y;
}

struct node * insert(struct node *node, int data){
    if(node == NULL){
        return createNode(data);
    }
    if(data<node->data){
        node->left = insert(node->left,data);
    }
    else if(data>node->data){
        node->right = insert(node->right, data);
    }

    //we measure the height of the leaf node because the code runs recursively.
    node->height = 1 + Max(getheight(node->right),getheight(node->left));
    int bf = getBalanceFactor(node);

    //left left case
    if(bf>1 && data < node->left->data){
        return rightRotate(node);
    }

    //right right case
    if(bf<-1 && data >  node->right->data){
        return leftRotate(node);
    }

    //left right case
    if(bf>1 && data > node->left->data){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    //right left case
    if(bf<-1 && data<node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;

}

void preorder(struct node * root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(){
    struct node * root = NULL;

    root = insert(root,1);
    root = insert(root,2);
    root = insert(root,4);
    root = insert(root,5);
    root = insert(root,6);
    root = insert(root,3);

    preorder(root);

    return 0;
}
