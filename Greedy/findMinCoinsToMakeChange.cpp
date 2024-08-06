#include <bits/stdc++.h>
using namespace std;

void findMinCoins(int amount, const vector<int>& coinDenominations, vector<int>& resultCoins) {
    for (int i = coinDenominations.size() - 1; i >= 0; i--) {
        while (amount >= coinDenominations[i]) {
            amount -= coinDenominations[i];
            resultCoins.push_back(coinDenominations[i]);
        }
    }
}

int main() {
    int targetAmount = 49;
    vector<int> coinsUsed;
    vector<int> coinDenominations = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    findMinCoins(targetAmount, coinDenominations, coinsUsed);
    cout << "The minimum number of coins is " << coinsUsed.size() << endl;
    cout << "The coins are: ";
    for (const int& coin : coinsUsed) {
        cout << coin << " ";
    }
    cout << endl;
    return 0;
}
//Time Complexity:O(V)
//Space Complexity:O(1)