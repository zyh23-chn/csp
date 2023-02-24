/**
 * 2023/2/24
 * 得分: 20
 * 内存超限
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int f(int a, int b)
{
    for (int _ = 0; _ < b; _++) {
        a = (a << 1) % (int)(1e9 + 7);
    }
    return a;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g1(n + 1, vector<pair<int, int>>(n + 1, { INT_MAX, INT_MAX }));
    for (int i = 1; i <= n; i++) {
        g1[i][i] = { 0, 0 };
    }
    for (int _ = 0; _ < m; _++) {
        int l1, r1, l2, r2, a, b;
        cin >> l1 >> r1 >> l2 >> r2 >> a >> b;
        for (int i = l1; i <= r1; i++) {
            for (int j = l2; j <= r2; j++) {
                if (b + log(a) / log(2) < g1[i][j].second + log(g1[i][j].first) / log(2)) {
                    g1[i][j] = { a, b };
                }
            }
        }
    }
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = g1[i][j].first != INT_MAX && g1[i][j].second != INT_MAX ? f(g1[i][j].first, g1[i][j].second) : -1;
        }
    }
    // Dijkstra
    vector<long long> a(n + 1, LLONG_MAX);
    vector<long long> a1(n + 1, -1);
    a[1] = 0;
    while (true) {
        // select one
        int i = min_element(a.begin(), a.end()) - a.begin(); // use heap to optimize
        if (i == 0) { // all elements are equal to LLONG_MAX
            break;
        }
        a1[i] = a[i];
        a[i] = LLONG_MAX;
        // update
        for (int j = 1; j <= n; j++) {
            if (a1[j] == -1 && g[i][j] != -1) {
                a[j] = min(a[j], a1[i] + g[i][j]);
            }
        }
    }
    // Reverse Dijkstra
    vector<long long> a2(n + 1, -1);
    a[1] = 0;
    while (true) {
        // select one
        int i = min_element(a.begin(), a.end()) - a.begin(); // use heap to optimize
        if (i == 0) { // all elements are equal to LLONG_MAX
            break;
        }
        a2[i] = a[i];
        a[i] = LLONG_MAX;
        // update
        for (int j = 1; j <= n; j++) {
            if (a2[j] == -1 && g[j][i] != -1) {
                a[j] = min(a[j], a2[i] + g[j][i]);
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        cout << (a1[i] != -1 && a2[i] != -1 ? (a1[i] + a2[i]) % (int)(1e9 + 7) : -1) << " ";
    }
}
