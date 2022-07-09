#include <bits/stdc++.h>


using namespace std;

int n, m;
int board[1000][1000];
int board2[10000010];

int ans[1000][1000];
bool vis[1000][1000] = { false };


int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int num = 2;

bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	if (board[x][y]==1) return false;
	return true;
}


void dfs(int x, int y)
{
	queue<pair<int, int>> qu;
	vector<pair<int, int>> v;
	qu.push(make_pair(x, y));
	vis[x][y] = true;
	int cnt = 0;

	while (!qu.empty())
	{
		pair<int, int> el = qu.front();
		qu.pop();
		v.push_back(el);
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int mx = el.first + dx[i];
			int my = el.second + dy[i];
			if (is_valid(mx, my) && !vis[mx][my])
			{
				qu.push(make_pair(mx, my));
				vis[mx][my] = true;
			}
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		board[v[i].first][v[i].second] = num;
	}
	board2[num++] = cnt;

}


void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0 && !vis[i][j])
				dfs(i, j);
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j]==1)
			{
				int sum = 1;
				vector<int> v2;
				for (int x = 0; x < 4; x++)
				{
					int mx = i + dx[x];
					int my = j + dy[x];
					if (is_valid(mx, my))
					{
						if (find(v2.begin(), v2.end(), board[mx][my])==v2.end())
						{
							v2.push_back(board[mx][my]);
						}
					}
				}
				for (int i = 0; i < v2.size(); i++)
				{
					sum += board2[v2[i]];
				}
				ans[i][j] = sum % 10;
			}
			else
				ans[i][j] = 0;
		}

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << ans[i][j];
		}
		cout << "\n";
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string inp;
		cin >> inp;
		for (int j = 0; j < m; j++)
			board[i][j] = inp[j]-'0';
	}


	solution();
	
	return 0;
}