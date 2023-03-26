#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int x1, y1, x2, y2;
int main()
{
    cin >> n >> a >> b;
    int x = 0;
    for (int _ = 0; _ < n; _++) {
        cin >> x1 >> y1 >> x2 >> y2;
        x += max(0, (min(a, x2) - max(0, x1))) * max(0, (min(b, y2) - max(0, y1)));
    }
    cout << x;
    return 0;
}
