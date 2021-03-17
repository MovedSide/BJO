#include<bits/stdc++.h>

using namespace std;

int N;
int num[100000][3];
int MAX = -1, MIN = 1000000;
int maxdp[2][3] = { 0, };
int mindp[2][3] = { 0, };
void func(int x, int y)
{
	if (y == 0)
	{
		maxdp[1][y] = num[x][y] + max(maxdp[0][y], maxdp[0][y + 1]);
		mindp[1][y] = num[x][y] + min(mindp[0][y], mindp[0][y + 1]);
	}
	else if (y == 1)
	{
		maxdp[1][y] = num[x][y] + max(maxdp[0][y - 1], max(maxdp[0][y], maxdp[0][y + 1]));
		mindp[1][y] = num[x][y] + min(mindp[0][y - 1], min(mindp[0][y], mindp[0][y + 1]));
	}
	else if (y == 2)
	{
		maxdp[1][y] = num[x][y] + max(maxdp[0][y], maxdp[0][y - 1]);
		mindp[1][y] = num[x][y] + min(mindp[0][y], mindp[0][y - 1]);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++) cin >> num[i][j];
	maxdp[0][0] = num[0][0];
	maxdp[0][1] = num[0][1];
	maxdp[0][2] = num[0][2];
	mindp[0][0] = num[0][0];
	mindp[0][1] = num[0][1];
	mindp[0][2] = num[0][2];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			func(i, j);
		}
		maxdp[0][0] = maxdp[1][0];
		maxdp[0][1] = maxdp[1][1];
		maxdp[0][2] = maxdp[1][2];
		mindp[0][0] = mindp[1][0];
		mindp[0][1] = mindp[1][1];
		mindp[0][2] = mindp[1][2];
	}
	cout << max(maxdp[0][0], max(maxdp[0][1], maxdp[0][2])) << " " << min(mindp[0][0], min(mindp[0][1], mindp[0][2]));
	return 0;
}