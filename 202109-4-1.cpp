/**
 * @file 202109-4-1.cpp
 * @author zyh
 * @brief Solution 1, 100 points.
 */

#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv)
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<double> pr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &pr[i]);
    }
    vector<vector<double> > dp(1 << n, vector<double>((n - 1) * k + 2));
    double ans = 0;
    dp[0][0] = 1;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j <= (n - 1) * k; j++) {
            int cnt = __builtin_popcount(i);
            if (cnt + j / k >= n) {
                ans += dp[i][j] * (cnt + j);
            } else {
                for (int t = 0; t < n; t++) {
                    if (i & (1 << t)) {
                        dp[i][j + 1] += dp[i][j] * pr[t];
                    } else {
                        dp[i | (1 << t)][j] += dp[i][j] * pr[t];
                    }
                }
            }
        }
    }
    printf("%.10f\n", ans);
}
