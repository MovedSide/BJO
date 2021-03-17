#include<bits/stdc++.h>

using namespace std;

int N, M;
int lo[8][8];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool vis[8][8];
int an = -1;
vector<pair<int, int>> vt;
int test = 0;


bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	if (lo[x][y] != 0 || vis[x][y]) return false;
	return true;
}




int func()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) vis[i][j] = false;
	queue<pair<int, int>> qu;
	for (auto el : vt) qu.push(el);
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
				vis[mx][my] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (lo[i][j] == 0 && !vis[i][j]) cnt++;
		}
	}
	return cnt;
}
void set_w(int x, int y, int cnt)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (lo[i][j] == 0)
			{
				if (cnt == 0)
				{
					lo[i][j] = 1;
					set_w(i, j, 1);
					lo[i][j] = 0;
				}
				else if (cnt == 1)
				{
					lo[i][j] = 1;
					set_w(i, j, 2);
					lo[i][j] = 0;
				}
				else if (cnt == 2)
				{
					lo[i][j] = 1;
					an = max(an, func());
					lo[i][j] = 0;
					test++;
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
		for (int j = 0; j < M; j++)
		{
			cin >> lo[i][j];
			if (lo[i][j] == 2)
				vt.push_back(make_pair(i, j));
		}
	set_w(0, 0, 0);
	cout << an;
	return 0;
}