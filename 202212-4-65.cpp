/**
 * 65 TLE
 */
 
#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;
int n;
int a[N];
vector<int> c[N];
long long ans[N];
vector<int> f(int node)
{
    vector<int> nodes = { node };
    for (int cnode : c[node]) {
        vector<int> nodes1 = f(cnode);
        for (int node1 : nodes1) {
            nodes.push_back(node1);
        }
    }
    int len = nodes.size();
    if (len >= 2) {
        vector<int> vals(len);
        for (int i = 0; i < len; i++) {
            vals[i] = a[nodes[i]];
        }
        sort(vals.begin(), vals.end());
        long long t1 = vals[1] - vals[0];
        long long t = t1 * t1;
        for (int i = 1; i <= len - 2; i++) {
            t1 = min(vals[i] - vals[i - 1], vals[i + 1] - vals[i]);
            t += t1 * t1;
        }
        t1 = vals[len - 1] - vals[len - 2];
        t += t1 * t1;
        ans[node] = t;
    }
    return nodes;
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        c[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    f(1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
