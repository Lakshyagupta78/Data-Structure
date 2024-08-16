#include<stdio.h>

int binarysearch(int arr[], int size, int element){

    int low, high, mid;

    low = 0;
    high = size-1;

    while(low<=high){

        mid = (low+high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = high-1;
        }
    }
    return -1;

}


int main(){

    int arr[] = {2,3,6,8,34,56,67,89,99};

    int size = sizeof(arr)/sizeof(int);

    int element = 89;

    int searchIndex = binarysearch(arr, size, element);
    printf("The element %d found at %d index :)",element,searchIndex);

    return 0;

}
