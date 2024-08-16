#include<stdio.h>
void printArray(int *A,int n){
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

void Merge(int A[],int mid,int low, int high){
    int i,j,k,B[high+1];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(A[i]<A[j]){
            B[k] = A[i];
            k++;
            i++;
        }
        else{
            B[k] = A[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while(j<=high){
        B[k] = A[j];
        k++;
        j++;
    }
    for(int i = low;i<=high;i++){
        A[i] = B[i];
    }
}

void MergeSort(int A[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,mid,low,high);
    }
}



int main(){
    int A[] = {9,8,7,6,5,4,3,2,1,0};
    int n = sizeof(A)/sizeof(A[0]);
    MergeSort(A,0,9);
    printArray(A,n);
    return 0;
}
