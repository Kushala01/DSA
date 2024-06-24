#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int lenOfLongSubarr(vector<int>& A, int N, int K)
{
    unordered_map<int, int> sum_index_map;
    int maxLen = 0;
    int prefix_sum = 0;

    for (int i = 0; i < N; ++i) {
        prefix_sum += A[i];

        if (prefix_sum == K) {
            maxLen = i + 1;
        }

        else if (sum_index_map.find(prefix_sum - K) != sum_index_map.end()) {
            maxLen = max(maxLen, i - sum_index_map[prefix_sum - K]);
        }

        if (sum_index_map.find(prefix_sum) == sum_index_map.end()) {
            sum_index_map[prefix_sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> arr = { 10, 5, 2, 7, 1, 9 };
    int n = arr.size();
    int k = 15;
    cout << "Length = " << lenOfLongSubarr(arr, n, k)
         << endl;
    return 0;
}