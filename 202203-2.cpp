#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector<int> t(n), c(n);
    int num = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &t[i], &c[i]);
        num = max(num, t[i]);
    }
    vector<int> time(num + 2);
    for (int i = 0; i < n; i++) {
        time[max(1, t[i] - c[i] + 1)]++;
        time[t[i] + 1]--;
    }
    for (int i = 2; i <= num; i++) {
        time[i] += time[i - 1];
    }
    for (int i = 0; i < m; i++) {
        int q;
        scanf("%d", &q);
        q += k;
        printf("%d\n", q <= num ? time[q] : 0);
    }
}
