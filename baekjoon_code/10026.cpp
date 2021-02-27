#include<bits/stdc++.h>

using namespace std;


string gr[100];
string gr2[100];
int N;
bool vis[100][100] = { false, };

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1, -1 };

bool is_valid(int x, int y, char c, int a)
{
	if (x < 0 || y < 0 || x >= N || y >= N) return false;
	if (vis[x][y]) return false;
	if (a == 1)
	{
		if (gr[x][y] != c) return false;
	}
	else if (a == 2)
	{
		if (gr2[x][y] != c) return false;
	}
	return true;
}

bool dfs(int x, int y, char c, int a)
{
	if (!is_valid(x, y, c, a)) return false;;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int mx, my;
		mx = x + dx[i];
		my = y + dy[i];
		dfs(mx, my, c, a);
	}
	return true;
}
int main()
{
	int an1 = 0, an2 = 0;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> gr[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (gr[i][j] == 'G') gr2[i] += 'R';
			else gr2[i] += gr[i][j];
		}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dfs(i, j, gr[i][j], 1))
			{
				an1++;
			}
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) vis[i][j] = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (dfs(i, j, gr2[i][j], 2))
			{
				an2++;
			}
		}
	}
	cout << an1 << " " << an2;
	return 0;
}
