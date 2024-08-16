#include<stdio.h>

void printArray(int * A , int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void BubbleSort(int *A, int n){
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void BubbleSortAdaptive(int *A, int n){
    int temp;
    int IsSorted = 0;
    for(int i=0;i<n-1;i++){
        printf("Working on pass %d\n",i+1);
        IsSorted = 1;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                IsSorted = 0;
            }
        }
        if(IsSorted){
            return;
        }
    }

}

int main(){
    //int A[] = {33,11,100,5,8,9,1};
    int A[] = {1,2,3,4,5,6,7};
    int n= 7;

    printArray(A , n);
    BubbleSortAdaptive(A , n);
    printArray(A , n);
    return 0;
}
