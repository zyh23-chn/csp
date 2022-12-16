/*
 * 0-1 knapsack solution
 * @Author: zyh
 */

#include <iostream>
#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    x = sum - x;
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j < a[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j - a[i]] + a[i], dp[i - 1][j]);
            }
        }
    }
    cout << sum - dp[n][x];
}
