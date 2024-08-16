#include<stdio.h>

linearsearch(int arr[], int size, int element){

    for(int i=0 ; i<size ; i++){

        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}


int main(){

    int arr[] = {1,3,4,6,8,0,7,9,10,11};

    int size = sizeof(arr)/sizeof(int);
    int element = 0;
    int searchindex = linearsearch(arr,size,element);

    printf("The element %d was found at index %d \n", element,searchindex);
    return 0;
}
