#include<bits/stdc++.h>

using namespace std;

int visit[100][100] = { 0, };
bool maze[100][100] = { false, };
int N, M;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool is_valid(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return false;
	if (maze[x][y] == 0) return false;
	return true;



}




int main()
{

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string inp;
		cin >> inp;
		for (int x = 0; x < M; x++)
		{
			if (inp[x] == '1') maze[i][x] = true;
			else false;
		}
	}
	queue<pair<int, int>> qu;
	qu.push(make_pair(0, 0));
	visit[0][0] = 1;
	while (!qu.empty())
	{
		pair<int,int> el = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			if (is_valid(el.first + dx[i], el.second + dy[i]))
			{
				if (visit[el.first + dx[i]][el.second + dy[i]] == 0)
				{
					qu.push(make_pair(el.first + dx[i], el.second + dy[i]));
					visit[el.first + dx[i]][el.second + dy[i]] = visit[el.first][el.second] + 1;
				}
			}
		}
	}
	cout << visit[N - 1][M - 1];
	return 0;
}