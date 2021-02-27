#include<bits/stdc++.h>

using namespace std;

int N, M;

int lo[50][50];
int ch[13][50];
vector<pair<int, int>> house, chicken;
bool vis[13] = { false, };
int an = 987654321;

void dfs(int x, int cnt)
{

	if (cnt == M)
	{
		int sum = 0;
		for (int i = 0; i < house.size(); i++)
		{
			int dis = 987654321;
			for (int j = 0; j < chicken.size(); j++)
			{
				if (vis[j])
				{
					dis = min(dis, abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second));
				}
			}
			sum += dis;
		}
		an = min(an, sum);
		return;
	}
	if (x == chicken.size()) return;
	vis[x] = true;
	dfs(x + 1, cnt + 1);
	vis[x] = false;
	dfs(x + 1, cnt);
}


int main()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> lo[i][j];
			if (lo[i][j] == 1) house.push_back(make_pair(i, j));
			else if (lo[i][j] == 2) chicken.push_back(make_pair(i, j));
		}

	dfs(0, 0);
	cout << an;
	return 0;
}
