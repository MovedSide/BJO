#include<bits/stdc++.h>

using namespace std;


int g[101][101] = { 0, };
int dp[101][101] = { 0, };
int ru[101][101] = { 0, };
vector<int> vt;

void print(int st, int ed)
{
	if (ru[st][ed] == 0)
	{
		vt.push_back(st);
		vt.push_back(ed);
		return;
	}
	print(st, ru[st][ed]);
	vt.pop_back();
	print(ru[st][ed], ed);
}


int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		fill_n(dp[i], n + 1, 100001);
	}
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
	}
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= n; y++)
			for (int z = 1; z <= n; z++)
			{
				if (y == z) continue;
				if (dp[y][z] > dp[y][x] + dp[x][z])
				{
					dp[y][z] = dp[y][x] + dp[x][z];
					ru[y][z] = x;
				}
			}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == 100001) cout << '0' << " ";
			else cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (dp[i][j] == 100001) cout << '0' << " ";
			else
			{
				print(i, j);
				cout << vt.size() << " ";
				for (int el : vt) cout << el << " ";
				vt.clear();
			}
			cout << endl;
		}
	return 0;
}
