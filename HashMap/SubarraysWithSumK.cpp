#include <bits/stdc++.h>
using namespace std;

// Subarrays with sum K
 int findSubArraySum(int Arr[], int N, int sum)
    {

       int count = 0;
       unordered_map<int,int> mpp;
       int currSum = 0;
       for(int i=0;i<N;i++)
       {
           currSum += Arr[i];

           if(currSum == sum)
           {
               count++;
           }
           if(mpp.find(currSum-sum) != mpp.end())
           {
               count += mpp[currSum-sum];
           }
           mpp[currSum]++;
       }
       return count;
    }
