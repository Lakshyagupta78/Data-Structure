#include<stdio.h>

int linearsearch(int arr[],int size,int element){

    for(int i=0;i<size;i++){

        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}




int main(){

    int arr[] = {9,5,6,8,4,2,1,7,0};

    int size = sizeof(arr)/sizeof(int);

    int element = 7;

    int searchIndex = linearsearch(arr,size,element);
    printf("The element %d found at index %d",element,searchIndex);

    return 0;
}
