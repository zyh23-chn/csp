#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

double f(vector<vector<int>> m, int i, int j)
{
    double x = 0;
    for (int u = 0; u < 8; u++) {
        for (int v = 0; v < 8; v++) {
            x += (sqrt(0.5) * (u == 0) + (u != 0)) * (sqrt(0.5) * (v == 0) + (v != 0))
                * m[u][v] * cos(acos(-1) / 8 * (i + 0.5) * u) * cos(acos(-1) / 8 * (j + 0.5) * v);
        }
    }
    return x / 4;
}

int main()
{
    vector<vector<int>> q(8, vector<int>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> q[i][j];
        }
    }
    int n, t;
    cin >> n >> t;
    vector<vector<int>> m(8, vector<int>(8));
    for (int _ = 0, i = 0, j = 0; _ < n; _++) {
        cin >> m[i][j];
        if ((i + j) & 1) {
            if (i == 7) {
                j++;
            } else if (j == 0) {
                i++;
            } else {
                i++;
                j--;
            }
        } else {
            if (i == 0) {
                j++;
            } else if (j == 7) {
                i++;
            } else {
                i--;
                j++;
            }
        }
    }
    if (t == 0) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m[i][j] *= q[i][j];
        }
    }
    if (t == 1) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
        return 0;
    }
    vector<vector<double>> m1(8, vector<double>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m1[i][j] = f(m, i, j);
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << max(min((int)round(m1[i][j] + 128), 255), 0) << " ";
        }
        cout << endl;
    }
    return 0;
}
