#include<bits/stdc++.h>

using namespace std;

const int MAX = 3 * 3 * 3 * 3 * 3 * 3 * 3;
int N;
int num[MAX][MAX];
int cnt[3] = { 0, };


void dfs(int x, int y, int s)
{
	int tnum = num[x][x];
	bool is_all_same = true;
	for (int i = x; i < x + s * 3; i++)
	{
		for (int j = y; j < y + s * 3; j++)
		{
			if (num[i][j] != tnum) is_all_same = false;
		}
	}
	if (is_all_same)
	{
		cnt[tnum + 1]++;
		return;
	}
	for (int p = 0; p < 9; p++)
	{
		bool is_same = true;
		int fix_num = num[x + (p / 3 * s)][y + (p % 3 * s)];
		for (int i = x + (p / 3 * s); i < x + (p / 3 * s) + s; i++)
		{
			for (int j = y + (p % 3 * s); j < y + (p % 3 * s) + s; j++)
			{
				if (fix_num != num[i][j])
				{
					is_same = false;
				}
			}
		}
		if (!is_same)
		{
			dfs(x + (p / 3 * s), y + (p % 3 * s), s / 3);
		}
		else cnt[fix_num + 1]++;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> num[i][j];
	dfs(0, 0, N / 3);
	for (int i = 0; i <= 2; i++) cout << cnt[i] << endl;
	return 0;
}