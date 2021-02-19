#include<bits/stdc++.h>

using namespace std;



vector<int> vt[1001];
bool vis[1001] = { false, };
stack<int> st;
queue<int> qu;

int N, M, V;

void dfs(int e)
{
	st.push(e);
	vis[e] = true;
	printf("%d ", e);
	for (int el : vt[e])
	{
		if (!vis[el]) dfs(el);
	}
}
void bfs(int e)
{
	qu.push(e);
	while (!qu.empty())
	{
		int t = qu.front();
		vis[t] = true;
		printf("%d ", t);
		qu.pop();
		for (int el : vt[t])
		{
			if (!vis[el])
			{
				qu.push(el);
				vis[el] = true;
			}
		}
	}
}
void reset()
{
	for (int i = 1; i <= N; i++)
	{
		vis[i] = false;
	}

}
int main()
{

	cin >> N >> M >> V;
	while (M--)
	{
		int inp1, inp2;
		cin >> inp1 >> inp2;
		vt[inp1].push_back(inp2);
		vt[inp2].push_back(inp1);
	}
	for (int i = 1; i <= N; i++)
	{
		sort(vt[i].begin(), vt[i].end());
	}

	dfs(V);
	printf("\n");
	reset();
	bfs(V);
	return 0;
}