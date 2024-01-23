#include <bits/stdc++.h>
using namespace std;
int countSmallerThanMid(vector<int> &row, int mid){
  int l = 0, h = row.size() - 1;
  while (l <= h){
    int md = (l + h) >> 1;
    if (row[md] <= mid)
      l = md + 1;
    else
      h = md - 1;
  }
  return l;
}
int findMedian(vector<vector<int>> &A){
  int low = 1;
  int high = 1e9;
  int n = A.size();
  int m = A[0].size();
  while (low <= high){
    int mid = (low + high) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; i++)
      cnt += countSmallerThanMid(A[i], mid);
    if (cnt <= (n * m) / 2)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return low;
}
int main(){
  int row = 3, col = 3;
  vector<vector<int>> arr = {{11,43, 8},
                             {2, 3, 45},
                             {12, 27, 53}};
  cout <<"The median of the row-wise sorted matrix is: "<<findMedian(arr)<<endl;
  return 0;
}
//TC=O(ROW*LOG COL)
//SC=0(1)