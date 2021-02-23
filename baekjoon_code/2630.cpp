#include<bits/stdc++.h>

using namespace std;



int pap[128][128];
int N;
int an[2] = { 0, };

void dfs(int x, int y, int s)
{
	int fix_num = pap[x][y];
	bool is_same = true;
	for (int i = x; i < x + s; i++)
	{
		for (int j = y; j < y + s; j++)
		{
			if (pap[i][j] != fix_num) is_same = false;
		}
		if (!is_same) break;
	}
	if (is_same)
	{
		an[fix_num]++;
		return;
	}
	dfs(x, y, s / 2);
	dfs(x, y + s / 2, s / 2);
	dfs(x + s / 2, y, s / 2);
	dfs(x + s / 2, y + s / 2, s / 2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) cin >> pap[i][j];
	dfs(0, 0, N);
	cout << an[0] << endl << an[1];
}