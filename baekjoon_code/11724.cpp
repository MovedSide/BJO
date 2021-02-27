#include<bits/stdc++.h>

using namespace std;


vector<int> gr[1001];
int vis[1001] = { false, };
int an = 0;

void dfs(int x)
{
	if (vis[x]) return;
	vis[x] = true;
	for (int el : gr[x])
	{
		dfs(el);
	}
}


int main()
{
	int n, m;
	cin >> n >> m;
	while (m--)
	{
		int inp1, inp2;
		cin >> inp1 >> inp2;
		gr[inp1].push_back(inp2);
		gr[inp2].push_back(inp1);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			dfs(i);
			an++;
		}
	}
	cout << an;
	return 0;
}
