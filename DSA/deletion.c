#include<stdio.h>

void display(int arr[],int n){

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int inddeletion(int arr[], int size, int index){

    if(index>size){
        return -1;
    }

    for(int i=index;i<size-1;i++){

        arr[i] = arr[i+1];
    }

}

int main(){

    int arr[100] = {2,4,6,7,8};

    int size=5, index=1;
    display(arr,size);

    inddeletion(arr,size,index);
    size -=1;
    display(arr,size);

    return 0;
}
