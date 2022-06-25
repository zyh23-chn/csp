#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<double> pr(n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &pr[i]);
    }
    vector<vector<double> > dp(1 << n, vector<double>((n - 1) * k + 2));
    dp[0][0] = 1;
    double ans = 0;

    for (int i = 1; i < (1 << n); i++) {
        double pri = 0;
        int cnt = 0;
        for (int t = 0; t < n; t++) {
            if (i & (1 << t)) {
                pri += pr[t];
                cnt++;
                dp[i][0] += dp[i - (1 << t)][0] * pr[t];
            }
        }
        if (cnt == n) {
            ans += dp[i][0] * cnt;
        }
        for (int j = 1; j <= (n - 1) * k; j++) {
            if (cnt + j / k < n) {
                dp[i][j] += dp[i][j - 1] * pri;
                for (int t = 0; t < n; t++) {
                    if (i & (1 << t)) {
                        dp[i][j] += dp[i - (1 << t)][j] * pr[t];
                    }
                }
            } else if (cnt + j / k == n) {
                if (j % k == 0) {
                    dp[i][j] += dp[i][j - 1] * pri;
                }
                for (int t = 0; t < n; t++) {
                    if (i & (1 << t)) {
                        dp[i][j] += dp[i - (1 << t)][j] * pr[t];
                    }
                }
            }
            if (cnt + j / k >= n) {
                ans += dp[i][j] * (cnt + j);
            }
        }
    }

    printf("%.10f\n", ans);
}
