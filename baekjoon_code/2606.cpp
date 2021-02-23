#include<bits/stdc++.h>

using namespace std;



bool vis[101] = { false, };



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int M;
	cin >> M;
	vector<int> com[101];
	while (M--)
	{
		int inp1, inp2;
		cin >> inp1 >> inp2;
		com[inp1].push_back(inp2);
		com[inp2].push_back(inp1);
	}
	queue<int> qu;
	qu.push(1);
	vis[1] = true;
	int cnt = 0;
	while (!qu.empty())
	{
		int el = qu.front();
		qu.pop();
		for (int el2 : com[el])
		{
			if (!vis[el2])
			{
				qu.push(el2);
				vis[el2] = true;
				cnt++;
			}
		}
	}
	cout << cnt;
}