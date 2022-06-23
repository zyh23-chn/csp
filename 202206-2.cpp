#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, L, S;
    scanf("%d %d %d", &n, &L, &S);
    vector<int> px(n), py(n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &px[i], &py[i]);
    }
    vector<int> px1, py1;
    int num = 0;
    for (int i = 0; i < S + 1; i++) {
        for (int j = 0; j < S + 1; j++) {
            int t;
            scanf("%d", &t);
            if (t) {
                px1.push_back(S - i);
                py1.push_back(j);
                num++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x0 = px[i], y0 = py[i];
        if (x0 + S > L || y0 + S > L) {
            continue;
        }
        int flag = 0;
        for (int j = 0; j < num; j++) {
            int x1 = px1[j] + x0, y1 = py1[j] + y0;
            int flag1 = 1;
            for (int k = 0; k < n; k++) {
                if (px[k] == x1 && py[k] == y1) {
                    flag1 = 0;
                    break;
                }
            }
            if (flag1) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        int num1 = 0;
        for (int j = 0; j < n; j++) {
            num1 += px[j] >= x0 && px[j] <= x0 + S && py[j] >= y0 && py[j] <= y0 + S;
        }
        ans += num1 == num;
    }
    printf("%d\n", ans);
}
