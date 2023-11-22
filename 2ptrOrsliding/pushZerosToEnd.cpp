void pushZerosToEnd(int arr[], int n) {
    int i=0,j=0;
    while(j<n){
        if(arr[j]!=0){
            swap(arr[i++],arr[j]);
        }j++;
    }i++;
    while(i<n){
        arr[i]=0;
        i++;
    }
}
