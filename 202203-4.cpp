/**
 * 60
 * 运行超时
 */
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int n, m;
int n1, n2;
map<pair<int, int>, long long> a;
struct f {
    bool operator()(const pair<int, long long>& o1, const pair<int, long long>& o2) const
    {
        return o1.second > o2.second || (o1.second == o2.second && o1.first < o2.first);
    };
};
vector<set<pair<int, long long>, f>> ans; //[v,x]
bool f1(int u)
{
    return ans[u].empty();
}

bool f2(int u)
{
    if (f1(u)) {
        return false;
    }
    int v = ans[u].begin()->first;
    return !f1(v) && ans[v].begin()->first == u;
}

// Update a node.
void update(int u, int v, int x)
{
    n1 -= f1(u);
    n2 -= f2(u);

    ans[u].erase({ v, a[{ u, v }] });
    a[{ u, v }] += x;
    if (a[{ u, v }]) {
        ans[u].insert({ v, a[{ u, v }] });
    }

    n1 += f1(u);
    n2 += f2(u);
};

int main()
{
    cin >> n >> m;
    n1 = n;
    n2 = 0;
    ans.resize(n + 1);
    //
    vector<vector<vector<int>>> a1(m); //[u,v,x]
    for (int i = 0; i < m; i++) {
        for (auto& a11 : a1[i]) {
            int u = a11[0], v = a11[1], x = a11[2];
            update(u, v, -x);
            update(v, u, -x);
        }
        int k;
        cin >> k;
        for (int _ = 0; _ < k; _++) {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            update(u, v, x);
            update(v, u, x);
            if (i + y < m) {
                a1[i + y].push_back({ u, v, x });
            }
        }
        int l;
        cin >> l;
        for (int _ = 0; _ < l; _++) {
            int u;
            cin >> u;
            if (ans[u].empty()) {
                cout << "0\n";
            } else {
                cout << ans[u].begin()->first << endl;
            }
        }
        int p, q;
        cin >> p >> q;
        if (p) {
            cout << n1 << endl;
        }
        if (q) {
            cout << n2 << endl;
        }
    }
}
