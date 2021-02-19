#include<bits/stdc++.h>

using namespace std;



int N, M;
vector<int> vt[101];
int vis[101] = { 0, };
queue<int> qu;



void reset()
{
	for (int i = 1; i <= N; i++) vis[i] = false;
}

int bfs(int e)
{
	qu.push(e);
	int sum = 0;
	vis[e] = 1;
	while (!qu.empty())
	{
		int t = qu.front();
		qu.pop();
		for (int el : vt[t])
		{
			if (vis[el] == 0)
			{
				qu.push(el);
				vis[el] = vis[t] + 1;
				sum += vis[t];
			}
		}
	}

	reset();
	return sum;
}

int main()
{
	cin >> N >> M;
	while (M--)
	{
		int inp1, inp2;
		cin >> inp1 >> inp2;
		vt[inp1].push_back(inp2);
		vt[inp2].push_back(inp1);
	}
	int min_num = bfs(1);
	int an = 1;
	for (int i = 2; i <= N; i++)
	{
		int t = bfs(i);
		if (min_num > t)
		{
			min_num = t;
			an = i;
		}
	}
	printf("%d", an);
	return 0;
}