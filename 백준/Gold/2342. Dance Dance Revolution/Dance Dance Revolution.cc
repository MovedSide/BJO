#include <bits/stdc++.h>


using namespace std;




int a[100000];
int dp[100000][5][5];
int num = 0;



int move(int start, int end)
{
	if (start == end) return 1;
	if (start == 0) return 2;
	if (abs(start - end) == 2) return 4;
	return 3;
}


int func(int cnt, int right, int left)
{
	if (cnt == num) return 0;
	if (dp[cnt][right][left] != 0) return dp[cnt][right][left];

	int move_right = move(right, a[cnt]);
	int move_left = move(left, a[cnt]);
	



	dp[cnt][right][left] = min(move_right + func(cnt + 1, a[cnt], left), move_left + func(cnt + 1, right, a[cnt]));
	return dp[cnt][right][left];
}



void solution()
{
	cout << func(0, 0, 0);
}





int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	while (1)
	{
		int inp;
		cin >> inp;
		if (inp == 0) break;
		a[num++] = inp;
	}
	solution();
	return 0;
}