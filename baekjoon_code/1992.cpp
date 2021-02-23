#include<bits/stdc++.h>

using namespace std;

int N;
string gr[64];
string an;

void dfs(int x, int y, int s)
{
	char fix_num = gr[x][y];
	bool is_same = true;
	for (int i = x; i < x + s; i++)
	{
		for (int j = y; j < y + s; j++)
		{
			if (fix_num != gr[i][j])
			{
				is_same = false;
			}
		}
		if (!is_same) break;
	}
	if (!is_same)
	{
		an += '(';
		dfs(x, y, s / 2);
		dfs(x, y + s / 2, s / 2);
		dfs(x + s / 2, y, s / 2);
		dfs(x + s / 2, y + s / 2, s / 2);
		an += ')';
	}
	else
	{
		an += fix_num;
	}
}





int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> gr[i];
	dfs(0, 0, N);
	cout << an;
}