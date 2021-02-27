#include<bits/stdc++.h>

using namespace std;

int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int score[500][500];
int vis[500][500] = { false, };
bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	if (vis[x][y]) return false;
	return true;
}


int dfs(int x, int y, int cnt)
{

	if (cnt == 4)	return score[x][y];
	int sum = 0;
	for (int i = 0; i < 4; i++)
	{
		int mx, my;
		mx = x + dx[i];
		my = y + dy[i];
		if (is_valid(mx, my))
		{
			vis[mx][my] = true;
			sum = max(sum, score[x][y] + dfs(mx, my, cnt + 1));
			vis[mx][my] = false;
		}
	}
	return sum;
}
int cal_block(int x, int y)
{
	int sum = 0;
	int bl[4];
	if (y >= 1 && y < M - 1 && x < N - 1)
		sum = max(sum, score[x][y] + score[x][y - 1] + score[x][y + 1] + score[x + 1][y]);
	if (y >= 1 && y < M - 1 && x >= 1)
		sum = max(sum, score[x][y] + score[x][y - 1] + score[x][y + 1] + score[x - 1][y]);
	if (x >= 1 && x < N - 1 && y < M - 1)
		sum = max(sum, score[x][y] + score[x + 1][y] + score[x - 1][y] + score[x][y + 1]);
	if (x >= 1 && x < N - 1 && y < M - 1)
		sum = max(sum, score[x][y] + score[x + 1][y] + score[x - 1][y] + score[x][y - 1]);
	return sum;
}

int main()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> score[i][j];
	int an = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			vis[i][j] = true;
			an = max(an, dfs(i, j, 1));
			an = max(an, cal_block(i, j));
			vis[i][j] = false;
		}
	cout << an;
	return 0;
}
