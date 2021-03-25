#include<bits/stdc++.h>

using namespace std;


int N, M;

bool lo[1000][1000];
bool vis[1000][1000][2];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int an = 987654321;
bool is_valid(int x, int y, int z)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	if (vis[x][y][z]) return false;
	return true;
}

void func()
{
	queue<pair<pair<int, int>, int>> qu;
	qu.push(make_pair(make_pair(0, 0), 1));
	int cnt = 1;
	while (!qu.empty())
	{
		int s = qu.size();
		for (int i = 0; i < s; i++)
		{
			auto el = qu.front();
			qu.pop();
			if (el.first.first == N - 1 && el.first.second == M - 1)
			{
				cout << cnt;
				return;
			}
			for (int i = 0; i < 4; i++)
			{
				int mx = el.first.first + dx[i];
				int my = el.first.second + dy[i];
				if (is_valid(mx, my, el.second))
				{
					if (lo[mx][my] == 1 && el.second == 1)
					{
						qu.push(make_pair(make_pair(mx, my), 0));
						vis[mx][my][0] = true;
					}
					else if (lo[mx][my] == 0)
					{
						qu.push(make_pair(make_pair(mx, my), el.second));
						vis[mx][my][el.second] = true;
					}
				}
			}
		}
		cnt++;
	}
	cout << -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string inp;
		cin >> inp;
		for (int j = 0; j < inp.size(); j++)
			lo[i][j] = inp[j] - '0';
	}
	func();
	return 0;
}