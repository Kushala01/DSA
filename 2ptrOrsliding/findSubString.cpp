#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int findSubString(const string& inputStr, int k) {
    unordered_map<int, int> freqCount;
    freqCount[0] = 1;
    int n = inputStr.size();
    int sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
       if(inputString[i]==5)count ++;
       sum+=freqCount[count-k];
       freqCount[count]++;
    }return sum;
}

int main() {
    string inputString;
    cin >> inputString;
    int k;
    cin >> k;
    int result = findSubString(inputString, k);
    cout << result;
    return 0;
}
