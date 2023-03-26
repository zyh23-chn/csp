#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m, k;
int t[N], c[N];
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> c[i];
    }
    auto f = [&](const int& i1, const int& i2) {
        return t[i1] < t[i2];
    };
    priority_queue<int, vector<int>, decltype(f)> pq(f);
    for (int i = 0; i < n; i++) {
        pq.push(i);
    }
    int T = t[pq.top()], C = 0;
    while (true) {
        while (!pq.empty() && t[pq.top()] == T) {
            C += c[pq.top()];
            pq.pop();
        }
        if (pq.empty()) {
            cout << max(k, T - m / C);
            break;
        }
        int ti = t[pq.top()];
        if (C * (T - ti) < m) {
            m -= C * (T - ti);
        } else {
            cout << (T - m / C);
            break;
        }
        T = ti;
    }
    return 0;
}
