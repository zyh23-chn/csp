#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    double avg = sum / n;
    double x = 0;
    for (int i = 0; i < n; i++) {
        x += (a[i] - avg) * (a[i] - avg);
    }
    double var = sqrt(x / n);
    for (int i = 0; i < n; i++) {
        printf("%f\n", (a[i] - avg) / var);
    }
}
