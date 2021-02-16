#include<bits/stdc++.h>

using namespace std;


int lo[50][50];

int x, y, n;



bool dfs(int x1, int y1)
{
	if (x1 < 0 || y1 < 0 || x1 >= x || y1 >= y) return false;


	if (lo[x1][y1])
	{
		lo[x1][y1] = 0;
		dfs(x1 + 1, y1);
		dfs(x1, y1 + 1);
		dfs(x1 - 1, y1);
		dfs(x1, y1 - 1);
		return true;
	}
	return false;
}


int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int cnt = 0;
		cin >> x >> y >> n;

		while (n--)
		{
			int x1, y1;
			cin >> x1 >> y1;
			lo[x1][y1] = 1;
		}

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (dfs(i, j) == true) cnt++;
			}
		}
		cout << cnt << endl;
	}
}
