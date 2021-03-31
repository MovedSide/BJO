#include<bits/stdc++.h>

using namespace std;



vector<int> tree[100001];
int n;
int pa[100001] = { 0, };


void func(int x)
{
	for (int el : tree[x])
	{
		if (!pa[el])
		{
			pa[el] = x;
			func(el);
		}
	}
}
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int inp1, inp2;
		cin >> inp1 >> inp2;
		tree[inp1].push_back(inp2);
		tree[inp2].push_back(inp1);
	}
	pa[1] = -1;
	func(1);
	for (int i = 2; i <= n; i++)
		cout << pa[i] << "\n";
	return 0;
}