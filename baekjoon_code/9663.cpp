#include<bits/stdc++.h>

using namespace std;

int N;
int an = 0;
bool lo[14][14] = { false, };
bool is_valid(int x, int y)
{
	int i, j;
	for (i = x - 1; i >= 0; i--)
	{
		if (lo[i][y]) return false;
	}
	for (i = x, j = y; i >= 0 && j >= 0; i--, j--)
	{
		if (lo[i][j]) return false;
	}
	for (i = x, j = y; i >= 0 && j < N; i--, j++)
	{
		if (lo[i][j]) return false;
	}
	return true;
}

void func(int index)
{
	if (index == N)
	{
		an++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (is_valid(index, i))
		{
			lo[index][i] = true;
			func(index + 1);
			lo[index][i] = false;
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	func(0);
	cout << an;
	return 0;
}