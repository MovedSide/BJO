#include<bits/stdc++.h>

using namespace std;

const int MAX = 1024;
int N, M;
int num[MAX][MAX];


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int inp;
			cin >> inp;
			if (j == 0)
			{
				num[i][j] = inp;
			}
			else
			{
				num[i][j] = num[i][j - 1] + inp;
			}
		}
	while (M--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int an = 0;
		for (int i = x1 - 1; i <= x2 - 1; i++)
		{
			if (y1 != 1)
				an += num[i][y2 - 1] - num[i][y1 - 2];
			else
			{
				an += num[i][y2 - 1];
			}
		}
		cout << an << "\n";
	}
	return 0;
}