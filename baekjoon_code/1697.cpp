#include<bits/stdc++.h>

using namespace std;


int vis[100001] = { 0, };

int N, M;
queue<int> qu;

bool is_valid(int x)
{
	if (x < 0) return false;
	if (x > 100000) return false;
	if (vis[x]) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	qu.push(N);
	vis[N] = 1;
	int an;
	while (!qu.empty())
	{
		int el = qu.front();
		qu.pop();
		if (el == M) break;
		if (is_valid(el + 1))
		{
			qu.push(el + 1);
			vis[el + 1] = vis[el] + 1;
		}
		if (is_valid(el - 1))
		{
			qu.push(el - 1);
			vis[el - 1] = vis[el] + 1;
		}
		if (is_valid(el * 2))
		{
			qu.push(el * 2);
			vis[el * 2] = vis[el] + 1;
		}
	}
	cout << vis[M] - 1;
	return 0;
}