#include <bits/stdc++.h>

using namespace std;
int findCnt(int arr[], int n, int k){
    int ans = 0;
    int j=0,i=0,sum=0;
    while(j<n){
        sum+=arr[j];
        while(i<=j and sum>=k){
            ans+=n - j;
            sum-=arr[i];
            i++;
        }j++;
    }return ans;
}

int main() {
   int n,k;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++) cin>>a[i];
   cin>>k;
   cout<<findCnt(a,n,k)<<endl;
}

/*Input : n= 5 A -> [1, 11, 2, 3, 15]  k = 10 
Output: 11*/
