#include<bits/stdc++.h>

using namespace std;
int N, M;
int sp[51] = { 0, };
vector<int> party[50];
int an = 0;

void dfs(int a, int p[], int cnt)
{
	if (a == M)
	{
		an = max(an, cnt);
		return;
	}
	int cp1[51], cp2[51];
	for (int i = 1; i <= N; i++)
	{
		cp1[i] = p[i];
		cp2[i] = p[i];
	}
	bool can_speak = true;
	for (int el : party[a])
	{
		if (cp1[el] == 1)
		{
			can_speak = false;
			break;
		}
		cp1[el] = 2;
	}
	if (can_speak) dfs(a + 1, cp1, cnt);
	for (int el : party[a])
	{
		if (cp2[el] == 2) return;
		cp2[el] = 1;
	}
	dfs(a + 1, cp2, cnt + 1);
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int k;
	cin >> k;
	while (k--)
	{
		int inp;
		cin >> inp;
		sp[inp] = 2;
	}
	for (int i = 0; i < M; i++)
	{
		int T;
		cin >> T;
		while (T--)
		{
			int inp;
			cin >> inp;
			party[i].push_back(inp);
		}
	}
	dfs(0, sp, 0);
	cout << an;
	return 0;
}