#include<bits/stdc++.h>

using namespace std;




char che[50][50];

int M, N;

int black(int a, int b)
{
	int cnt = 0;
	for (int i = a; i < a + 8; i++)
		for (int j = b; j < b + 8; j++)
		{
			if ((i + j) % 2 == (a + b) % 2)
			{
				if (che[i][j] != 'B') cnt++;
			}
			else
			{
				if (che[i][j] != 'W') cnt++;
			}
		}
	return cnt;
}
int white(int a, int b)
{
	int cnt = 0;
	for (int i = a; i < a + 8; i++)
		for (int j = b; j < b + 8; j++)
		{
			if ((i + j) % 2 == (a + b) % 2)
			{
				if (che[i][j] != 'W') cnt++;
			}
			else
			{
				if (che[i][j] != 'B') cnt++;
			}
		}
	return cnt;
}




int main()
{
	int an = 64;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) cin >> che[i][j];
	for (int i = 0; i < N - 7; i++)
		for (int j = 0; j < M - 7; j++)
		{
			an = min(an, black(i, j));
			an = min(an, white(i, j));
		}
	cout << an;
	return 0;
}