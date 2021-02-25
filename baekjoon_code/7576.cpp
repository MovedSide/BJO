#include<bits/stdc++.h>

using namespace std;



int to[1000][1000];
queue<pair<int, int>> qu;
int M, N, H;

bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= M || y >= N) return false;
	if (to[x][y] != 0) return false;

	return true;
}
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };



int main()
{

	cin >> N >> M;
	for (int x = 0; x < M; x++)
		for (int y = 0; y < N; y++)
		{
			cin >> to[x][y];
			if (to[x][y] == 1)
			{
				qu.push(make_pair(x, y));
			}
		}
	int an;
	while (!qu.empty())
	{
		auto el = qu.front();
		qu.pop();
		int xel = el.first;
		int yel = el.second;
		for (int i = 0; i < 4; i++)
		{
			int mx, my;
			mx = xel + dx[i];
			my = yel + dy[i];
			if (is_valid(mx, my))
			{
				qu.push(make_pair(mx, my));
				to[mx][my] = to[xel][yel] + 1;
			}
		}
		if (qu.empty())
		{
			bool print = true;
			for (int x = 0; x < M; x++)
				for (int y = 0; y < N; y++)
				{
					if (to[x][y] == 0) print = false;
				}
			if (print)
				an = to[xel][yel] - 1;
			else an = -1;
		}
	}
	cout << an;
	return 0;
}
