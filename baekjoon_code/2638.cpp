#include<bits/stdc++.h>

using namespace std;


int lo[100][100];
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	if (lo[x][y] != 0) return false;
	return true;
}
bool is_fin()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) if (lo[i][j] != -1) return false;
	return true;
}

void set_air(int x, int y)
{
	queue<pair<int, int>> qu;
	qu.push(make_pair(x, y));
	lo[x][y] = -1;
	while (!qu.empty())
	{
		auto el = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			int mx = el.first + dx[i];
			int my = el.second + dy[i];
			if (is_valid(mx, my))
			{
				qu.push(make_pair(mx, my));
				lo[mx][my] = -1;
			}
		}
	}
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> lo[i][j];
	for (int i = 0; i < N; i++)
		if (lo[i][0] == 0)
		{
			set_air(i, 0);
		}
	for (int i = 0; i < N; i++)
		if (lo[i][M - 1] == 0)
		{
			set_air(i, M - 1);
		}
	for (int i = 0; i < M; i++)
		if (lo[0][i] == 0)
		{
			set_air(0, i);
		}
	for (int i = 0; i < M; i++)
		if (lo[N - 1][i] == 0)
		{
			set_air(N - 1, i);
		}
	int cnt = 0;
	while (1)
	{
		vector<pair<int, int>> vt;
		for (int i = 1; i < N - 1; i++)
		{
			for (int j = 1; j < M - 1; j++)
			{
				if (lo[i][j] == 1)
				{
					int air = 0;
					for (int x = 0; x < 4; x++)
					{
						int mx = i + dx[x];
						int my = j + dy[x];
						if (lo[mx][my] == -1) air++;
					}
					if (air >= 2)
						vt.push_back(make_pair(i, j));
				}
			}
		}
		for (auto al : vt)
		{
			set_air(al.first, al.second);
		}
		cnt++;
		if (is_fin()) break;
	}
	cout << cnt;
	return 0;
}