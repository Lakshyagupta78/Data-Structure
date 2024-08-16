#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};
void inOrder(struct node * root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
struct node * createnode(int data)
{
    struct node * p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(struct node * root,int key)
{
    struct node * prev = NULL;
    while(root!=NULL)
    {
        prev = root;
        if(key == root->data)
        {
            printf("cannot insert the duplicate value");
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node * naya = createnode(key);
    if(key<prev->data){
        prev->left = naya;
    }
    else{
        prev->right = naya;
    }
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

    inOrder(p); //1 3 4 5 6
    printf("\n");
    insert(p,16);
    inOrder(p); //1 3 4 5 6 16

    printf("\n%d",p->right->right->data);//16

    return 0;

}
