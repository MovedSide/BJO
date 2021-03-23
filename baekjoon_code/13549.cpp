#include<bits/stdc++.h>

using namespace std;


int N, K;
queue<int> qu;
bool vis[100001] = { false, };

bool is_valid(int x)
{
	if (x < 0 || x> 100000) return false;
	if (vis[x]) return false;
	return true;
}

void push_qu(int x)
{
	if (!is_valid(x)) return;
	qu.push(x);
	vis[x] = true;
	if (x == 0) return;
	if (x < K)
	{
		int i = 2;
		while (1)
		{
			if (is_valid(x * i))
			{
				qu.push(x * i);
				vis[x * i] = true;
			}
			if (x * i > K) return;
			i *= 2;
		}
	}
}



int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> K;
	push_qu(N);
	int cnt = 0;
	while (!qu.empty())
	{
		int size = qu.size();
		for (int i = 0; i < size; i++)
		{
			int el = qu.front();
			qu.pop();
			if (el == K)
			{
				cout << cnt;
				exit(0);
			}
			push_qu(el - 1);
			push_qu(el + 1);
		}
		cnt++;
	}
	return 0;
}