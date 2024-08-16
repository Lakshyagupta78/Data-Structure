#include<stdio.h>

void PrintArray(int *A, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

void SelectionSort(int *A, int n)
{
    int temp;
    int indexOfMin;
    for(int i=0; i<n-1; i++)
    {
        indexOfMin = i;
        for(int j=i+1; j<n; j++)
        {
            if(A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

int main()
{
    // Input Array (There will be total n-1 passes)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13


    int A[] = {3,5,2,13,12};
    //int A[] = {3,1,6,8,0,4,22,11};
    int n = 5;

    PrintArray(A,n);
    SelectionSort(A,n);
    PrintArray(A,n);
}
