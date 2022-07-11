#include <bits/stdc++.h>


using namespace std;




int a[500][500];
int n;

int dp[500][500] = { 0 };

int solution(int x,int y)
{
	if (x == n) return 0;
	if (dp[x][y] != 0) return dp[x][y];
	return dp[x][y] = a[x][y] + max(solution(x + 1,y), solution(x + 1,y+1));
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << solution(0,0);
	return 0;
}