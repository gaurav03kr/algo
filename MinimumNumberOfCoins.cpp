#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0; 
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return (dp[amount] == INT_MAX) ? -1 : dp[amount];
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

    int result = minCoins(coins, amount);

    if (result == -1)
        cout << "It is not possible to make amount " << amount << " with given coins.\n";
    else
        cout << "Minimum coins required to make amount " << amount << " = " << result << endl;

    return 0;
}
