#include<bits/stdc++.h>

using namespace std;

int N;
int an = 0;
int next_node;
bool vis[10001] = { false, };
vector <pair<int, int>> vt[10001];


void func(int index, int cost)
{
	if (vis[index]) return;
	vis[index] = true;
	if (an < cost)
	{
		an = cost;
		next_node = index;
	}
	for (auto el : vt[index])
	{
		func(el.first, el.second + cost);
	}
}







int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int inp1, inp2, inp3;
		cin >> inp1 >> inp2 >> inp3;
		vt[inp1].push_back(make_pair(inp2, inp3));
		vt[inp2].push_back(make_pair(inp1, inp3));
	}
	func(1, 0);
	an = 0;
	for (int i = 1; i <= N; i++) vis[i] = false;
	func(next_node, 0);

	cout << an;
	return 0;
}