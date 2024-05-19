#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=20;
    int prev2=1;
    int prev1=1;
    int curr;
    for(int i=2;i<n;i++){
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    cout<<curr;
    return 0;
}