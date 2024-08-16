void Display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int InsertionElement(int arr[],int ind,int ele,int size,int cap){
    if(size>=cap){
        return -1;
    }
    for(int i=size-1;i>=ind;i--){
        arr[i+1] = arr[i];
    }
}


int main(){
    int arr[10] = {2,3,4,5,8};
    int index = 3;
    int element = 10;
    int size = 5;
    int capacity = 10;
    Display(arr,size);
    InsertionElement(arr,index,element,size,capacity);
}
