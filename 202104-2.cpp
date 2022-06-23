#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, L, r, t;
    scanf("%d%d%d%d", &n, &L, &r, &t);
    vector<vector<int> > a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            if (i) {
                a[i][j] += a[i - 1][j];
            }
            if (j) {
                a[i][j] += a[i][j - 1];
            }
            if (i && j) {
                a[i][j] -= a[i - 1][j - 1];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int left = max(0, i - r);
            int right = min(n - 1, i + r);
            int up = max(0, j - r);
            int down = min(n - 1, j + r);
            int x = a[right][down];
            if (left) {
                x -= a[left - 1][down];
            }
            if (up) {
                x -= a[right][up - 1];
            }
            if (left && up) {
                x += a[left - 1][up - 1];
            }
            int y = (right - left + 1) * (down - up + 1);
            ans += x / y < t || (x / y == t && x % y == 0);
        }
    }
    printf("%d\n", ans);
}
