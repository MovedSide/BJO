#include<bits/stdc++.h>
using namespace std;



int N, M;

bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M)
		return false;
	return true;
}


int main()
{
	int x, y, K;
	int map[20][20];
	int dice[6] = { 0 };
	int dice_dir[4] = { 3,4,2,5 };
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	int num = 1;
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	for (int i = 0; i < K; i++)
	{
		int inp;
		cin >> inp;
		int mx = x + dx[inp - 1];
		int my = y + dy[inp - 1];
		if (!is_valid(mx, my)) continue;
		int tmp = num;
		num = dice_dir[inp - 1];
		dice_dir[inp - 1] = 7 - tmp;
		if (inp % 2 == 0) dice_dir[inp - 2] = tmp;
		else dice_dir[inp] = tmp;
		x = mx;
		y = my;
		

		if (map[x][y] == 0)
		{
			map[x][y] = dice[num - 1];
		}
		else
		{
			dice[num - 1] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[6 - num] << endl;
	}
}