#include<bits/stdc++.h>
using namespace std;

int findMinConnectionCost(vector<int>&arr){
    int n=arr.size();
    int first,second,sum,totalCost=0;
    priority_queue<int, vector<int>, greater<int>>minHeap(arr.begin(),arr.end());
    while(minHeap.size()>1){
        first=minHeap.top();
        minHeap.pop();
        second=minHeap.top();
        minHeap.pop();
        sum=first+second;
        totalCost+=sum;
        minHeap.push(sum);
    }
    return totalCost;
}
int main(){
    vector<int>arr={1,2,3};
    int ans=findMinConnectionCost(arr);
    cout<<"the min cost is "<< ans<<endl;
    return 0;
}
/*The time and space complexity analysis of the given code is as follows:

### Time Complexity

1. **Building the Min-Heap:**
   - Building a min-heap from `n` elements takes `O(n)` time.

2. **While Loop:**
   - The loop runs until there is only one element left in the heap, which means it will execute `n-1` times.
   - In each iteration of the while loop:
     - Extracting the two minimum elements from the heap (`minHeap.pop()`) takes `O(log n)` time each.
     - Inserting the sum back into the heap (`minHeap.push(sum)`) also takes `O(log n)` time.
   - Therefore, each iteration of the loop takes `O(log n) + O(log n) + O(log n) = O(log n)`, and with `n-1` iterations, the total time complexity for the loop is `O((n-1) * log n)`.

Combining these steps:
- Building the heap: `O(n)`
- Processing the heap: `O((n-1) * log n)`

The overall time complexity is:
\[ O(n) + O((n-1) \log n) = O(n \log n) \]

### Space Complexity

1. **Heap Storage:**
   - The heap stores `n` elements, requiring `O(n)` space.

2. **Auxiliary Space:**
   - The function uses a few additional variables (`first`, `second`, `sum`, `totalCost`), which require `O(1)` space.

Thus, the overall space complexity is:
\[ O(n) \]

### Summary
- **Time Complexity:** \( O(n \log n) \)
- **Space Complexity:** \( O(n) \)*/