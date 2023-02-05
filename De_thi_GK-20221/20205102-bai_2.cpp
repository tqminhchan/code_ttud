#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x;
	cin >> n;
	priority_queue<int> q;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		// cout << x << endl;
		q.push(x);
	}
	// cout << 111 << endl;
	string s;
	while (cin >> s)
	{
		if (s == "*")
			return 0;
		if (s == "insert")
		{
			cin >> x;
			// cout << x << endl;
			q.push(x);
		}
		else
		{
			cout << q.top() << endl;
			q.pop();
		}
	}
}