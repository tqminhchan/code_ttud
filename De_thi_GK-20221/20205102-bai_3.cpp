#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, l, r;
	cin >> n >> l >> r;
	int a[n], b[r + 1] = {}, ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = r; j > a[i]; j--)
		{
			if (b[j - a[i]] > 0)
			{
				b[j]++;
			}
		}
		if (a[i] <= r)
			b[a[i]]++;
	}
	for (int i = l; i <= r; i++)
	{
		ans += b[i];
	}
	cout << ans;
}