/**
 * @file 202303-5-1.cpp
 * @author zyh
 * @brief Solution 1, 60 points.
 * @date 2023-04-01
 */

#include <bits/stdc++.h>
using namespace std;
int n, m, l, r;
int main()
{
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    for (int _ = 0; _ < m; _++) {
        cin >> l >> r;
        a[r].push_back(l);
    }
    vector<int> a1(n + 1); // 当前包含某个点的所有区间的左端点的最大值
    int x = 0;
    for (int r1 = 2; r1 <= n; r1++) {
        for (int l1 : a[r1]) {
            for (int i = l1; i <= r1; i++) {
                a1[i] = max(a1[i], l1);
            }
        }
        int t = a1[r1];
        for (int i = r1 - 1; i >= 0; i--) {
            x += a1[i] < t;
            t = min(t, a1[i]);
        }
    }
    cout << x;
    return 0;
}
