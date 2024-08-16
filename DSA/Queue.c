#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int b;
    int * arr;
};

int isFull(struct queue * k){
    if(k->b==k->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct queue * k){
    if(k->f==k->b){
        return 1;
    }
    else{
        return 0;
    }
}


void Enqueue(struct queue * k,int val){
    if(isFull(k)){
        printf("Queue is Full");
    }
    else{
        k->b++;
        k->arr[k->b] = val;
        printf("Enqueuing element %d\n",val);
    }
}

int Dequeue(struct queue * k){
    int a = -1;
    if(isEmpty(k)){
        printf("Queue is Empty");
    }
    else{
        k->f++;
        a = k->arr[k->f];
    }
    return a;
}

int main(){
    struct queue k;
    k.size = 4;
    k.f = -1;
    k.b = -1;
    k.arr = (int *)malloc(k.size * sizeof(int));

    Enqueue(&k,5);
    Enqueue(&k,10);
    Enqueue(&k,15);
    Enqueue(&k,20);

    printf("Dequeuing element %d\n",Dequeue(&k));
    printf("Dequeuing element %d\n",Dequeue(&k));
    printf("Dequeuing element %d\n",Dequeue(&k));
    printf("Dequeuing element %d\n",Dequeue(&k));

    Enqueue(&k,25); // 25 can not insert in queue because F == R.



    if(isEmpty(&k)){
        printf("Queue is empty");
    }
    if(isFull(&k)){
        printf("Queue is full");
    }
    return 0;
}
