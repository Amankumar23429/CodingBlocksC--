#include<iostream>
using namespace std;

void merge(int *arr, int s, int e){
    int mid = (s+e)/2;
    
    int i = s;
    int j = mid+1;
    int k = s;

    int temp[100];

    while(i<=mid && j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        }else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }

    while(j<=e){
        temp[k++] = arr[j++];
    }

    for(int x = 0; x<k; x++){
        arr[x] = temp[x];
    }
}

void mergeSort(int a[], int s, int e){
    if(s>=e){
        return;
    }
    // follow three steps
    // first step divide
    int mid = (s+e)/2;
    mergeSort(a, s, mid);
    mergeSort(a, mid+1, e);

    // second step sort
    merge(a, s, e);
}

int main(){
    int n;
    cin>>n;
    int arr[100];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    mergeSort(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}