/**
 * 50分做法
 * 动态规划 + 前缀和
 * Author: zyh
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, L;
    cin >> n >> L;
    vector<long long> v(n + 1), m(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
    }
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + v[i];
    }
    vector<long long> dp(n + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (m[j] < m[i]) {
                dp[i] = min(dp[i], dp[j] + (a[i] - a[j] - L) * (a[i] - a[j] - L));
            }
        }
    }
    cout << dp[n];
}
