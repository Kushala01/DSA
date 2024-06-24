#include<bits/stdc++.h>
using naamespacestd;

int MaxSubArraySum(int arr[], int n){
	long long maxi=LONG_MIN;
	long sum=0;
    int start=-1;
    int startInd=-1,endInd=-1;
	for(int i=0; i<n; i++){
		if(sum==0) start=i;
        sum+=arr[i];
        if(sum<0) sum=0;
        if(sum>maxi){
            maxi=sum;
            startInd=start;
            endInd=i;
        }
	}
}