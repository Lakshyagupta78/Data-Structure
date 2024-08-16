#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int front;
    int rear;
    int * arr;
};

int isFull(struct queue * k){
    if(k->rear==k->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue * k){
    if(k->front==k->rear){
        return
        1;
    }
    else{
        return 0;
    }
}


void Enqueue_rear(struct queue * k,int val){
    if(isFull(k)){
        printf("Queue is Full");
    }
    else{
        k->rear++;
        k->arr[k->rear] = val;
        printf("Enqueuing element %d\n",val);
    }
}

void Enqueue_front(struct queue * k,int val){
    if(isFull(k)||k->front==-1){
        printf("Queue is full");
    }
    else{
        k->arr[k->front]=val;
        k->front--;
        printf("Insert successfully");
    }
}

int Dequeue_front(struct queue * k){
    int a = -1;
    if(isEmpty(k)){
        printf("Queue is Empty");
    }
    else{
        k->front++;
        a = k->arr[k->front];
    }
    return a;
}

Dequeue_rear(struct queue * k){
    if(isEmpty(k)){
        printf("Queue is Empty");
    }
    else{
        int val = k->arr[k->rear];
        k->rear--;
        return val;
    }
}

int main(){
    struct queue k;
    k.size = 4;
    k.front = -1;
    k.rear = -1;
    k.arr = (int *)malloc(k.size * sizeof(int));

    Enqueue_rear(&k,5);
    Enqueue_rear(&k,10);
    Enqueue_rear(&k,15);
    Enqueue_rear(&k,20);

    printf("Dequeuing element %d\n",Dequeue_front(&k));
    printf("Dequeuing element %d\n",Dequeue_front(&k));
    printf("Dequeuing element %d\n",Dequeue_front(&k));
    printf("Dequeuing element %d\n",Dequeue_front(&k));

    Enqueue_rear(&k,25); // 25 can not insert in queue because F == R.



    if(isEmpty(&k)){
        printf("Queue is empty");
    }
    if(isFull(&k)){
        printf("Queue is full");
    }
    return 0;
}
