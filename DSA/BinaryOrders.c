#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void PreOrder(struct Node *Root){
    if(Root != NULL){
        printf("%d\n",Root->data);
        PreOrder(Root->left);
        PreOrder(Root->right);
    }
}

void PostOrder(struct Node *Root){
    if(Root != NULL){
        PostOrder(Root->left);
        PostOrder(Root->right);
        printf("%d\n",Root->data);
    }
}

void InOrder(struct Node *Root){
    if(Root != NULL){
        InOrder(Root->left);
        printf("%d\n",Root->data);
        InOrder(Root->right);
    }
}

struct Node * Traversal(struct Node * head){
    struct Node * p = head;
    while(p->right != NULL){
        printf("Element: %d\n",p->data);
        p = p->right;
    }
     printf("Element: %d\n",p->data);
};

struct Node * createNode(int data){
    struct Node *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = data;
    p->right = NULL;
    p->left = NULL;
    return p;
}
int main(){
    struct Node *p  = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    //       TREE
    //
    //          4
    //         / \
    //        /   \
    //       1     6
    //      / \
    //     /   \
    //    5     2
    //
    //

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

   // Traversal(p);
    printf("PreOrder\n");
    PreOrder(p);
    printf("\nPostOrder\n");
    PostOrder(p);
    printf("\nIn Order\n");
    InOrder(p);

}
