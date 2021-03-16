#include<bits/stdc++.h>

using namespace std;

int N, K;

bool vis[100001] = { false, };
bool new_vis[100001] = { false, };



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	queue<int> qu, new_qu;
	qu.push(N);
	int cnt = 0;
	int cnt2 = 1;
	vis[N] = true;
	while (!qu.empty())
	{
		int s = qu.size();
		for (int i = 0; i < s; i++)
		{
			int el = qu.front();
			qu.pop();
			if (el == K)
			{
				cout << cnt << "\n";
				i++;
				while (i < s)
				{
					int f = qu.front();
					if (f == K) cnt2++;
					qu.pop();
					i++;
				}
				cout << cnt2;
				exit(0);
			}
			if (el - 1 >= 0)
			{
				if (!vis[el - 1])
				{
					new_vis[el - 1] = true;
					qu.push(el - 1);
					new_qu.push(el - 1);
				}
			}
			if (el + 1 <= 100000)
			{
				if (!vis[el + 1])
				{
					new_vis[el + 1] = true;
					qu.push(el + 1);
					new_qu.push(el + 1);
				}
			}
			if (el * 2 <= 100000)
			{
				if (!vis[el * 2])
				{
					new_vis[el * 2] = true;
					qu.push(el * 2);
					new_qu.push(el * 2);
				}
			}
		}
		cnt++;
		while (!new_qu.empty())
		{
			int e = new_qu.front();
			new_qu.pop();
			vis[e] = true;
		}
	}
	return 0;
}