#include<stdio.h>
#include<stdlib.h>

struct Node * f = NULL;
struct Node * r = NULL;


struct Node{
    int data;
    struct Node * next;
};

void LinkedListTraversal(struct Node * ptr){
    printf("printing the element\n");
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr = ptr->next;
    }

}


void Enqueue(int val){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL){
        printf("Queue is full");
    }
    else{
        p->data = val;
        p->next = NULL;
        if(f == NULL){
            f=r=p;
        }
        else{
            r->next = p;
            r=p;
        }
    }
}

int Dequeue(){
    int val = -1;
    struct Node * ptr = f;

    if(f == NULL){
        printf("Queue is Empty");
    }
    else{
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;

}


int main(){
    LinkedListTraversal(f);
    printf("Dequeuing Element: %d\n",Dequeue());  //It will return -1.
    Enqueue(34);
    Enqueue(4);
    Enqueue(6);
    printf("Dequeuing Element: %d\n",Dequeue());  // return 34.
    LinkedListTraversal(f);

    return 0;

}
