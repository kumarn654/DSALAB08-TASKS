
#include<iostream>
#include<algorithm>
using namespace std;

void display(int arr[],int n){

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

void heapify(int arr[],int n,int index,int &swapCount){

    int largest = index;

    int left = 2*index+1;
    int right = 2*index+2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != index){

        swap(arr[index],arr[largest]);
        swapCount++;

        heapify(arr,n,largest,swapCount);
    }
}

void buildMaxHeap(int arr[],int n,int &swapCount){

    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i,swapCount);
    }
}

void heapSort(int arr[],int n){

    int swapCount = 0;

    buildMaxHeap(arr,n,swapCount);

    cout<<"Array after building Max Heap:"<<endl;
    display(arr,n);

    for(int i=n-1;i>0;i--){

        swap(arr[0],arr[i]);
        swapCount++;

        cout<<endl<<"After extracting maximum:"<<endl;
        display(arr,n);

        heapify(arr,i,0,swapCount);

        cout<<"After heapify:"<<endl;
        display(arr,n);
    }

    cout<<endl<<"Final Sorted Array:"<<endl;
    display(arr,n);

    cout<<"Total Swaps: "<<swapCount<<endl;
}

int main(){

    int arr[] = {42,17,63,28,51,9,36,74,23};
    int n = 9;

    heapSort(arr,n);

    return 0;
}
