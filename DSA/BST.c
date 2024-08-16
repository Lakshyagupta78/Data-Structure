#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * createNode(int data){
    struct Node * p;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void inOrder(struct Node * root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int BST(struct Node* root){
    static struct Node * prev = NULL;
    if(root!=NULL){
        if(!BST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return BST(root->right);
    }
    else{
        return 1;
    }
}

int main(){
    struct Node * p = createNode(5);
    struct Node * p1 = createNode(3);
    struct Node * p2 = createNode(6);
    struct Node * p3 = createNode(2);
    struct Node * p4 = createNode(4);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    printf("\n");

    if(BST(p)){
        printf("This is a Binary search tree");
    }
    else{
        printf("This is not a Binary search tree");
    }


}
