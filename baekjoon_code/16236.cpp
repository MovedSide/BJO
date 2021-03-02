#include<bits/stdc++.h>

using namespace std;

int N, M;

int lo[20][20];
bool vis[20][20] = { false, };
int an = 0;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
int sz = 2;
int cnt2 = 0;
bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N) return false;
	if (vis[x][y]) return false;
	if (lo[x][y] > sz) return false;
	return true;
}
void is_init()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) vis[i][j] = false;
}

void bfs(int x, int y)
{
	is_init();
	queue<pair<int, int>> qu;
	qu.push(make_pair(x, y));
	vis[x][y] = true;
	int cnt = 1;
	int nx = 21;
	int ny = 21;
	while (!qu.empty())
	{
		int k = qu.size();
		while (k--)
		{
			auto el = qu.front();
			qu.pop();
			for (int i = 0; i < 4; i++)
			{
				int mx = el.first + dx[i];
				int my = el.second + dy[i];
				if (is_valid(mx, my))
				{
					if (lo[mx][my] < sz && lo[mx][my] != 0)
					{
						if (nx > mx)
						{
							nx = mx;
							ny = my;
						}
						else if (nx == mx && ny > my)
						{
							nx = mx;
							ny = my;
						}
					}
					else
					{
						qu.push(make_pair(mx, my));
						vis[mx][my] = true;
					}
				}
			}
		}
		if (nx != 21 && ny != 21)
		{
			an += cnt;
			cnt2++;
			if (cnt2 == sz)
			{
				cnt2 = 0;
				sz++;
			}
			lo[nx][ny] = 0;
			bfs(nx, ny);
			return;
		}
		cnt++;
	}
}




int main()
{
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> lo[i][j];
			if (lo[i][j] == 9)
			{
				lo[i][j] = 0;
				x = i;
				y = j;
			}
		}
	bfs(x, y);
	cout << an;
	return 0;
}
