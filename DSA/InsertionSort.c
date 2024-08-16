#include<stdio.h>

void PrintArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void InsertionSort(int *A,int n){
    int key;
    int j;
    for(int i=1;i<=n-1;i++){
        key = A[i];
        j = i-1;

        while(j>=0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}

int main(){
    int A[]={9,3,5,66,78,2,1};
    int n = 7;
    PrintArray(A,n);
    InsertionSort(A,n);
    PrintArray(A,n);
}
