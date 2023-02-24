/**
 * 64
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

const int k = 14;
const int mod = 998244353;

int main()
{
    vector<int> a = { 1, 2, 4, 6, 16, 26, 41, 42, 44, 46, 61, 62, 64, 66 };
    vector<vector<int>> a1 = { { 2 }, { 4 }, { 1, 6, 16 }, { 4, 6, 64 }, { 26 }, { 46 }, { 62 }, { 64 }, { 61 }, { 66 }, { 42 }, { 44 }, { 41 }, { 46 } };
    unordered_map<int, int> id;
    for (int i = 0; i < k; i++) {
        id[a[i]] = i;
    }
    vector<vector<int>> m(k, vector<int>(k));
    for (int i = 0; i < k; i++) {
        for (int t : a1[i]) {
            m[i][id[t]] = 1;
        }
    }
    int n;
    string s;
    cin >> n >> s;
    if (s.size() <= 2) {
        if (!id.count(stoi(s))) {
            cout << 0;
            return 0;
        }
        vector<int> x(k);
        x[0] = 1;
        //
        for (int _ = 0; _ < n; _++) {
            vector<int> x1(k);
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < k; j++) {
                    x1[j] = (x1[j] + x[i] * m[i][j]) % mod;
                }
            }
            x = move(x1);
        }
        cout << x[id[stoi(s)]];
        return 0;
    }
}
