#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr,int i,int n){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(arr[largest]<arr[left] && left<n){
        largest=left;
    }
    if(arr[largest]<arr[right] && right<n){
        largest=right;
    }
    if(i!=largest){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
}

void maxHeapSort(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }
}

void printArray(const vector<int>&arr){
    for(int i:arr)
        cout<<i<<" ";
    cout << endl;
 }
int main(){
    vector<int> arr={12,5,8,11,7,4,2};
    maxHeapSort(arr);
    cout<<"the resulatant aarya is: ";
    printArray(arr);
    return 0;
}