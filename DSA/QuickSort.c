#include<stdio.h>

void PrintArray(int A[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int Partition(int A[],int low,int high){
    int pivot = A[low];
    int i = low+1;
    int j = high;
    int temp;

    do{
        while(A[i]<=pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    }while(i<j);

    temp = A[j];
    A[j] = A[low];
    A[low] = temp;

    return j;
}


void QuickSort(int A[],int low,int high){
    if(low<high){
        int PartitionIndex;
        PartitionIndex = Partition(A,low,high);
        QuickSort(A,low,PartitionIndex-1);
        QuickSort(A,PartitionIndex+1,high);
    }

}

int main(){
    int A[] = {3,2,55,1,44,2};
    int n = 7;

    PrintArray(A,n);
    QuickSort(A,0,n-1);
    PrintArray(A,n);

}
