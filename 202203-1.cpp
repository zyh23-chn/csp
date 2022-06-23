#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n + 1);
    a[0] = 1;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ans += 1 - a[y];
        a[x] = 1;
    }
    printf("%d\n", ans);
}
