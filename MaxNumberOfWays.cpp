#include <bits/stdc++.h>
using namespace std;

int countWays(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    int n;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;

    int ways = countWays(coins, amount);
    cout << "Maximum number of ways to make amount " << amount << " = " << ways << endl;

    return 0;
}
