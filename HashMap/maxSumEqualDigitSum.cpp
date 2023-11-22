#include<bits/stdc++.h>
using namespace std;

int maxSumEqualDigitSum(vector<int>&A){
    int maxSum=-1;
    unordered_map<int, int> DsumToValue;
    for(int nums : A){
        int Dsum=0;
        int temp=nums;
        while(temp>0){
            Dsum+=temp%10;
            temp/=10;
        }
        if(DsumToValue.find(Dsum)!=DsumToValue.end()){
            maxSum=max(maxSum, max(nums+DsumToValue[Dsum],nums));
            DsumToValue[Dsum]=max(nums, DsumToValue[Dsum]);
        }else{
            DsumToValue[Dsum]=nums;
        }
    }
    return maxSum;
}
