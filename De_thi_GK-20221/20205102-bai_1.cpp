#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, m, q = 0;
    cin >> n >> k >> m;
    long long a[n + 1];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = k; i <= n; i++)
    {
        if (a[i] - a[i - k] == m)
        {
            q++;
        }
    }
    cout << q;
}