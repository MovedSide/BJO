#include<bits/stdc++.h>

using namespace std;


string house[25];
int N;
bool vis[25][25] = { false, };
vector<int> an;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= N) return false;
	if (vis[x][y]) return false;
	if (house[x][y] == '0') return false;
	return true;
}
void bfs(int x, int y)
{
	queue<pair<int, int>> qu;
	qu.push(make_pair(x, y));
	int cnt = 0;
	vis[x][y] = true;
	while (!qu.empty())
	{
		int ex, ey;
		auto el = qu.front();
		ex = el.first;
		ey = el.second;
		qu.pop();
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			if (is_valid(ex + dx[i], ey + dy[i]))
			{
				qu.push(make_pair(ex + dx[i], ey + dy[i]));
				vis[ex + dx[i]][ey + dy[i]] = true;
			}
		}
	}
	an.push_back(cnt);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> house[i];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (house[i][j] == '1' && !vis[i][j]) bfs(i, j);
		}
	sort(an.begin(), an.end());
	cout << an.size() << endl;
	for (int el : an) cout << el << endl;
}