#include<bits/stdc++.h>
using namespace std;




int main()
{
	int n, m;
	cin >> n >> m;
	int mat[2][100][100];
	for (int x = 0; x < 2; x++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> mat[x][i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[0][i][j] + mat[1][i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}